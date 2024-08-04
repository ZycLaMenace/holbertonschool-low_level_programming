Thank you README FROM ArcturusSky

# FILE I/O

This repository is part of the `low-programming` parent repository focused on C programming. Here, I'm starting to learn and work with FILE I/O. This project will holds my 

Note : I will also update that README.md regarding new concepts I have to learn during these projects.

## Summary

- [FILE I/O](#file-io)
	- [Summary](#summary)
	- [Glossary](#glossary)
	- [File Descriptors](#file-descriptors)
		- [File Flags and Modes](#file-flags-and-modes)
		- [Reminder: File permissions](#reminder-file-permissions)
		- [Combined Permissions](#combined-permissions)
	- [System Calls](#system-calls)
		- [`open`](#open)
		- [`close`](#close)
		- [`read`](#read)
		- [(advanced) Strategies for Reading Data When Size is Unknown](#advanced-strategies-for-reading-data-when-size-is-unknown)
		- [`write`](#write)
	- [Higher-Level File I/O Functions](#higher-level-file-io-functions)
		- [`fopen`](#fopen)
		- [`fread`](#fread)
		- [`fwrite`](#fwrite)
	- [Conclusion](#conclusion)
	- [Author](#author)

## Glossary

**A**

  - **Access Mode:** Specifies how a file is to be opened, such as reading, writing, or appending.

**B**

  - **Binary File:** A file that contains data in a format that is not human-readable, often used for efficient data storage and retrieval.

  - **Buffer:** A temporary storage area used to hold data while it is being transferred between two locations, such as from a file to memory.

  - **Bytes:** Units of data that are read from or written to a file, typically 8 bits in size.

**C**

  - **Chunks:** Portions or blocks of data read from or written to a file, often used in file operations.

  - **Close:** The action of releasing system resources associated with an open file descriptor or file stream.

**D**

  - **Descriptor:** An integer handle used by the operating system to manage open files.

**E**

  - **End of File (EOF):** A condition indicating that no more data can be read from a file.

**F**

  - **File:** A collection of data stored on a disk that can be read from or written to.

  - **File Descriptor:** An integer that uniquely identifies an open file within a process.

  - **File Pointer:** A pointer to a `FILE` structure used in higher-level file I/O functions.

  - **File Stream:** A flow of data that can be read from or written to, represented by a `FILE` structure.

**F (cont.)**

  - **Flags:** Options used with the `open` function to specify how a file should be accessed or modified.

**H**

  - **Higher-Level Functions:** File I/O functions that provide a more abstract interface compared to lower-level system calls, making file operations easier to use.

**I**

  - **I/O:** Stands for Input/Output, referring to the communication between a computer and the outside world, including file operations.

**M**

  - **Mode:** Specifies the permissions for a file or the access mode when opening a file.

**O**

  - **Octal Notation:** A base-8 number system used to represent file permissions in Unix-like systems.

**P**

  - **Pointer:** A variable that holds the memory address of another variable or data structure.

  - **POSIX:** A set of standards specified by the IEEE for maintaining compatibility between operating systems.

  - **Perror:** A function that prints a descriptive error message to `stderr` based on the current value of `errno`.

**R**

  - **Read:** The action of retrieving data from a file into a buffer.

**S**

  - **Size:** The number of bytes for each element read or written in file operations.

  - **Stream:** A sequence of data elements made available over time, used for file I/O operations.

  - **ssize_t:** A data type used to represent the size of a data object or the number of bytes read or written.

  - **System Call:** A function provided by the operating system kernel that allows user programs to request services such as file operations.

**T**

  - **Truncate:** To reduce the size of a file to zero length.

**W**

  - **Write:** The action of storing data from a buffer to a file.


## File Descriptors

**Definition:** 
A file descriptor is an integer handle used by the operating system to manage open files. it acts as a unique identifier for each file or I/O stream (flux d'entrée/sortie) that a program can access. The standard file descriptors are:

  - **Standard Input (stdin):** File descriptor **`0`** (`STDIN_FILENO`).
	
	- Used for readin incoming data (*example:* keyboard input).
  
  - **Standard Output (stdout):** File descriptor **`1`** (`STDOUT_FILENO`).
	
	- Used for writing output data (*example:* displaying text on the screen).
  
  - **Standard Error (stderr):** File descriptor **`2`** (`STDERR_FILENO`).
	
	- Used for outputting error messages (*exemple:* program error messages).

**Why use them?**

File descriptors are essential for performing file operations in Unix_like systems, providing a way to interact with files and other I/O resources.

**Analogy:** Imagine, you have a mailbox with three different drawers:
	
  - One drawer for incoming letters **(stdin)**
  - One drawer for outgoing letters **(stout)**
  - One drawer gor letters containing problems or errors **stderr**.

Each drawer has a number so you can easily find it and know where to put or retrieve letters. File descriptors work similary to manage data streams.

**Code example:**
Here's a simple example in C to illustrate the use of file descriptors:

```c
#include <stdio.h>
#include <unistd.h> /** Includes definitions for file descriptors */

int main() 
{
	/** Write a message to standard output (stdout) */
	const char *message = "Hello, here is a message on stdout!\n";
	write(1, message, 34); /** 1 is the file descriptor for stdout containing 34 char*/

	/** Read a character from standard input (stdin) */
	char c;
	read(0, &c, 1); /** 0 is the file descriptor for stdin */

	/** Write a message to standard error (stderr) */
	const char *error_message = "This is an error message on stderr!\n";
	write(2, error_message, 36); /** 2 is the file descriptor for stderr */

return (0);
}
```
**Code Explanation:**

  - **`write(1, message, 34);`:** Sends `message` to file descriptor **`1`**. The **`write`** function write data directly to a file descriptor.
  - **`read(0 &c, 1);`:** Reads a character from file descriptor **`0`** **(stdin)**. The **`read`** function reads data from a file descriptor.
  - **`write (2, error_message, 36);`:** Sends an error message to file descriptor **`2`** **(stderr).**


### File Flags and Modes

**Definition:**

**Flags** and **modes** control how files are accessed and manipulated in Unix-like systems. Flags specify how a file should be opened, and modes define file permissions. Common flags include:

 - **`Read Only (O_RDONLY)`:** Open the file for reading only.
 - **`Write Only (O_WRONLY)`:** Open the file for writing only. 
 - **`Read and Write (O_RDWR)`**: Open the file for both reading and writing.
 - **`Create if Not Exists (O_CREAT)`**: Create the file if it does not exist.
 - **`Append (O_APPEND)`**: Append data to the end of the file.

**Combining Flags**

Flags can be combined using the bitwise **OR** operator (**`|`**). This allows for multiple options to be specified when opening a file.

### Reminder: File permissions


| Octal Value | Binary | Owner (User) | Group | Others | Description				|
|-------------|--------|--------------|-------|--------|----------------------------|
| **`0`**	  | `000`  | ---		  | ---	  | ---	   | No permissions				|
| **`1`**	  | `001`  | ---		  | ---	  | --x	   | Execute only				|
| **`2`**	  | `010`  | ---		  | ---	  | -x-	   | Write only					|
| **`3`**	  | `011`  | ---		  | ---	  | -x-	   | Write and execute			|
| **`4`**	  | `100`  | ---		  | r--	  | ---	   | Read only					|
| **`5`**	  | `101`  | ---		  | r--	  | --x	   | Read and execute			|
| **`6`**	  | `110`  | ---		  | rw-	  | ---	   | Read and write				|
| **`7`**	  | `111`  | ---		  | rwx	  | rwx	   | Read, write, and execute	|

### Combined Permissions

When combining permissions, you concatenate the octal values:

- **`0644`**:
  - **0** = specifies that the number should be interpreted as octal.
  - **Owner (User)**: `rw-` (6)
  - **Group**: `r--` (4)
  - **Others**: `r--` (4)

- **`0755`**:
  - **Owner (User)**: `rwx` (7)
  - **Group**: `r-x` (5)
  - **Others**: `r-x` (5)

**Mnemonic for Permission Types:**
- **`r` (read)**: 4
- **`w` (write)**: 2
- **`x` (execute)**: 1

Combine these values to form the desired permission set. For example:
- **`rw-`** = 4 (read) + 2 (write) = **`6`**
- **`r-x`** = 4 (read) + 1 (execute) = **`5`**


## System Calls

### `open`

**Definition:**

The **`open`** system call is used to **open a file** and returns a **file descriptor**, which is a unique integer used to identify the fil in subsequent operations.

**Why use it?**

You use **`open`** tp either create a new file or access an existing file. It provides a file descriptor that allows you to perform various operations on the file, such as reading or writing.

**Template:**

```c
int open(const char *pathname, int flags, mode_t mode);
```
**Parameters:**

  - **pathname:** The path to the file you want to open.
  - **flags:** Specifies how the fil should be accessed or modified.
  - **mode:** File permissions to use when creating a new file (only used with **`0_CREAT`**).

**Common Flags**

  - **`0_RONLY`:** Open the file for reading only.
  - **`0_WRONLY`:** Open the file for writing only.
  - **`0_RDWR`:** Open the file for both reading and writing.
  - **`0_CREAT`:** Create the file if it does not exist.
  - **`0_TRUNC`:** Truncate (cut off) the file to zero length if it already exists.
  - **`0_APPEND`:** Append data to the end of the file.

**Note:** When creating a file, you also need to specify the fil permissions using **`mode`**, which determines who can read, write, or execute the file.

**Example:**

Here's an example of using `open` to open a file name `"file.text"`:

```c
#include <fcntl.h> /** Includes definitions for file control operations */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> /** Includes definitions for POSIX constants and types */

int main()
{
	/** Open "file.txt" for reading and writing, create if it does not exist, and truncate it to zero length if it exists */
	int fileDescriptor = open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);

	/** Check if the file was opened successfully */
	if (fileDescriptor < 0)
	{
		/** Handle the error */
		perror("Error opening file");
		return (1);
	}

	/** File operations can be performed here */

	/** Close the file descriptor */
	close(fileDescriptor);

	return (0);
}

```

**Explanation:**

  - **`open("file.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);`**

	- **`O_RDWR`:** Open the file for both reading and writing
	- **`0_CREAT`:** Create the file if it doesn't exist.
	- **`0_TRUNC`:** Truncate the file to zero length if it already exists.
	- **`0666`:** File permissions (read and write for everyone)

	- **`fileDescriptor`** will hold the file descriptor for "``file.txt"``. If the open call fails, it will return **`-1`**.

### `close`

**Definition:**

The **`close`** system call is used to **close an open file descriptor**
. When you're done working with a file, calling `close` realeased the system resources associated with that file descriptor.

**Why Use it?**

Using **`close`** is important to free up system resources that were allocated for the file descriptor. This prevents resource leaks and ensures that other processes or parts of your programm can use these resources efficiently.

**Template:**

```c
int close(int fd);
```

**Parameters:**
  
  - `fd`: The file descriptor that you want to close.

**Returns:**

  - **`0`** on success
  - **`-1`** on faillure, and sets **`errno`** to indicate the error.

**Example:**
Here's a simple example demonstration how to use **`close`** to close a file descriptor:

```c
#include <fcntl.h>   /** Includes definitions for file control operations */
#include <unistd.h>  /** Includes definitions for POSIX constants and types */
#include <stdio.h>   /** Includes definitions for standard I/O operations */

int main() 
{
	/** Open "file.txt" for reading and writing, create if it does not exist */
	int fileDescriptor = open("file.txt", O_RDWR | O_CREAT, 0666);

	/** Check if the file was opened successfully */
	if (fileDescriptor < 0) {
		perror("Error opening file");
		return -1;
	}

	/**!  Perform file operations here */

	/** Close the file descriptor */
	if (close(fileDescriptor) < 0) {
		perror("Error closing file");
		return (-1); /** Return -1 to indicate an error occurred during file closing */
	}

	return (0); /** Return 0 to indicate success */
}
```
**Explanation:**

  - **`close(fileDescriptor);`:** Closes the file descriptor previously obtained by the **`open`** system call.
  - if **`close`** returns **`-1`**  it indicate that the file descriptor could not be closed. **`perror`** is used to print the error message.

### `read`

**Definition:**

The **`read`** system call is used to **read data** from a file descriptor into a buffer. It retrieves data from a file or I/O resource.

**Why Use it?**

Using **`read`** to obstain data from a filr oe other I/O resource. This is essential for processing file contents or handling input data. 

**Template:**

```c
ssize_t read(int fd, void *buf, size_t count);
```

**Parameters:**
  
  - **`fd`**: The file descriptor from which to read data. This descriptor must be valid and open for reading.
  - **`buf`:** A pointer to the buffer where the read data will be stored.
  - **`count`**: The number of bytes to read from the file descriptor.

**Returns:**

  - **Number of bytes read:** The number of bytes successfully read into the buffer.
  - **`0`** Indicates the end of the file (EOF) has been reached.
  - **`-1`** Indicates an error occurred, and **`errno`** is set to indicate the specific error.

**Example:**
Here's a simple example demonstration how to use **`read`** to read data frome a file:

```c
#include <fcntl.h>   /** Includes definitions for file control operations */
#include <unistd.h>  /** Includes definitions for POSIX constants and types */
#include <stdio.h>   /** Includes definitions for standard I/O operations */

int main(void) 
{
	/** Open "file.txt" for reading only */
	int fileDescriptor = open("file.txt", O_RDONLY);

	/** Check if the file was opened successfully */
	if (fileDescriptor < 0) 
	{
		perror("Error opening file");
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Buffer to store the read data */
	char buffer[100];
	ssize_t bytesRead = read(fileDescriptor, buffer, sizeof(buffer));

	/** Check if the read operation was successful */
	if (bytesRead < 0) 
	{
		perror("Error reading file");
		close(fileDescriptor); /** Close the file descriptor */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Print the data read from the file */
	printf("Read %zd bytes: %.*s\n", bytesRead, (int)bytesRead, buffer);

	/** Close the file descriptor */
	close(fileDescriptor);

	return (0); /** Return 0 to indicate success */
}

```
**Explanation:**

  - **`read(fileDescriptor, buffer, sizeof(buffer));`**: Reads data from fileDescriptor into buffer. The sizeof(buffer) specifies the maximum number of bytes to read.
  - **`bytesRead`**: Stores the number of bytes actually read. If bytesRead is 0, it means the end of the file has been reached.

### (advanced) Strategies for Reading Data When Size is Unknown

  1. **Read in Chunks:**
	 - You can read data in chunks of a fixed size (*example: 1024 bytes*) and then process or store it incrementally. This is useful when you’re dealing with large files or streams where you don’t know the total size. 

```c
#include <fcntl.h> /** Includes definitions for file control operations */
#include <unistd.h> /** Includes definitions for POSIX constants and types */
#include <stdio.h> /** Includes definitions for standard I/O operations */

/**
 * main - Opens a file, reads it in chunks, and prints the content to stdout.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	int fileDescriptor; /** File descriptor for the opened file */
	char buffer[1024]; /** Buffer to store data read from the file */
	ssize_t bytesRead; /** Number of bytes read from the file */

	/**Open "file.txt" for reading only */
	fileDescriptor = open("file.txt", O_RDONLY);
	if (fileDescriptor < 0)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		return (-1); /**Return -1 to indicate an error occurred */
	}

	/** Read data from the file in chunks and print to stdout */
	while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0)
	{
		/** Write the data read to stdout */
		write(STDOUT_FILENO, buffer, bytesRead);
	}

	if (bytesRead < 0)
	{
		perror("Error reading file"); /** Print error message if reading fails */
		close(fileDescriptor); /** Close the file descriptor */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Close the file descriptor */
	close(fileDescriptor);

	return (0); /** Return 0 to indicate success */
}
```

 
  2. **Read Until End-of-File (EOF):**
	 - You can keep reading until read returns 0, indicating the end of the file. This method is common for reading text files where the end-of-file is a natural stopping point.

```c
#include <fcntl.h> /** Includes definitions for file control operations */
#include <unistd.h> /** Includes definitions for POSIX constants and types */
#include <stdio.h> /** Includes definitions for standard I/O operations */

/**
 * main - Opens a file, reads until EOF, and prints the content to stdout.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	int fileDescriptor; /** File descriptor for the opened file */
	char buffer[256]; /** Buffer to store data read from the file */
	ssize_t bytesRead; /** Number of bytes read from the file */

	/** Open "file.txt" for reading only */
	fileDescriptor = open("file.txt", O_RDONLY);
	if (fileDescriptor < 0)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Read data from the file until EOF and print to stdout */
	while ((bytesRead = read(fileDescriptor, buffer, sizeof(buffer))) > 0)
	{
		/** Write the data read to stdout */
		write(STDOUT_FILENO, buffer, bytesRead);
	}

	if (bytesRead < 0)
	{
		perror("Error reading file"); /** Print error message if reading fails */
		close(fileDescriptor); /** Close the file descriptor */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Close the file descriptor */
	close(fileDescriptor);

	return (0); /** Return 0 to indicate success */
}

```

  3. **Dynamic Buffer Allocation:**
	  - Start with a small buffer and dynamically resize it as needed. This method is useful if you expect to handle varying amounts of data but want to start with a manageable size. 

```c
#include <fcntl.h> /** Includes definitions for file control operations */
#include <unistd.h> /** Includes definitions for POSIX constants and types */
#include <stdio.h> /** Includes definitions for standard I/O operations */
#include <stdlib.h> /** Includes definitions for memory allocation functions */
#include <string.h> /** Includes definitions for string manipulation functions */

/**
 * main - Opens a file, reads it dynamically, and prints the content to stdout.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	int fileDescriptor; /** File descriptor for the opened file */
	char *buffer; /** Pointer to dynamically allocated buffer */
	size_t bufferSize; /** Current size of the buffer */
	ssize_t bytesRead; /** Number of bytes read from the file */
	size_t totalBytesRead; /** Total number of bytes read */
	char *newBuffer; /** Pointer to new buffer when resizing */

	/** Initial buffer size */
	bufferSize = 256;

	/** Allocate initial buffer */
	buffer = malloc(bufferSize);
	if (buffer == NULL)
	{
		perror("Error allocating buffer"); /** Print error message if allocation fails */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Open "file.txt" for reading only */
	fileDescriptor = open("file.txt", O_RDONLY);
	if (fileDescriptor < 0)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		free(buffer); /** Free allocated buffer */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	totalBytesRead = 0;

	/** Read data from the file dynamically */
	while ((bytesRead = read(fileDescriptor, buffer + totalBytesRead, bufferSize - totalBytesRead)) > 0)
	{
		totalBytesRead += bytesRead; /** Update total bytes read */
		
		/** Check if buffer needs resizing */
		if (totalBytesRead == bufferSize)
		{
			bufferSize *= 2;					/** Double the buffer size */
			newBuffer = realloc(buffer, bufferSize);
			if (newBuffer == NULL)
			{
				perror("Error reallocating buffer"); /** Print error message if reallocation fails */
				free(buffer); /** Free allocated buffer */
				close(fileDescriptor); /** Close the file descriptor */
				return (-1); /** Return -1 to indicate an error occurred */
			}
			buffer = newBuffer; /** Update buffer pointer */
		}
	}

	if (bytesRead < 0)
	{
		perror("Error reading file"); /** Print error message if reading fails */
		free(buffer); /** Free allocated buffer */
		close(fileDescriptor); /** Close the file descriptor */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Print the data read from the file */
	write(STDOUT_FILENO, buffer, totalBytesRead);

	/** Free the dynamically allocated buffer */
	free(buffer);

	/** Close the file descriptor */
	close(fileDescriptor);

	return (0); /** Return 0 to indicate success */
}
```

### `write`

**Definition:**

The **`write`** system call is used to **write data** from a buffer to a file descriptor. This is essential for saving data to a file or sending data to an I/O resource.

**Why Use it?**

You use **`write`** to send data to a file or other I/O resource, allowing you to store or transmit data.

**Template:**

```c
ssize_t write(int fd, const void *buf, size_t count);
```

**Parameters:**
  
  - **`fd`**: The file descriptor to which data will be written.This descriptor must be valid and open for reading.
  - **`buf`:** A pointer to the buffer containing the data to be written.
  - **`count`**: The number of bytes to write from the buffer.

**Returns:**

  - **Number of bytes written:** The number of bytes successfully written to the file descriptor.
  - **`-1`** Indicates an error occurred, and **`errno`** is set to indicate the specific error.

**Example:**
Here's a simple example demonstration how to use **`write`** to write to a file:

```c
#include <fcntl.h> /** Includes definitions for file control operations */
#include <unistd.h> /** Includes definitions for POSIX constants and types */
#include <stdio.h> /** Includes definitions for standard I/O operations */
#include <string.h> /** Includes definitions for string manipulation functions */

/**
 * main - Opens a file, writes data to it, and then closes the file.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	int fileDescriptor; /** File descriptor for the opened file */
	const char *data = "Hello, World!"; /** Data to be written to the file */
	ssize_t bytesWritten; /** Number of bytes written to the file */

	/** Open "file.txt" for writing only. Create it if it does not exist. */
	fileDescriptor = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fileDescriptor < 0)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Write data to the file */
	bytesWritten = write(fileDescriptor, data, strlen(data));
	if (bytesWritten < 0)
	{
		perror("Error writing to file"); /** Print error message if writing fails */
		close(fileDescriptor); /** Close the file descriptor */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Close the file descriptor */
	close(fileDescriptor);

	return (0); /** Return 0 to indicate success */
}


```
**Explanation:**

- **`fileDescriptor = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);`**

  - Opens **`file.txt`** for writing only. If the file does not exist, it will be created **`(O_CREAT)`**, and if it exists, it will be truncated to zero length **`(O_TRUNC)`**.
  - The permissions `0666` set read and write permissions for the owner, group, and others.

- **``bytesWritten = write(fileDescriptor, data, strlen(data));``** 

  - Writes the content of data to the file. The length of data is determined using `strlen(data)`.

- **`if (bytesWritten < 0)`**
  
  - Checks if **`write`** failed and prints an error message if it did.

- **`close(fileDescriptor);`**
  
  - Closes the file descriptor to release system resources.

## Higher-Level File I/O Functions

### `fopen`

**Definition:**

The **`fopen`** function opens a file and returns a pointer to a **`FILE`** structure, which represents the file stream.

**Why Use it?**

**`fopen`** provides a higher-level interface for file operations, making it easier to perform file I/O operations compared to lower-level system calls.

**Template:**

```c
FILE *fopen(const char *filename, const char *mode);
```

**Parameters:**
  
  -  **`filename`:** the name of the file to open.
  - **`mode`:** Access mode (*example* **`"r"`** for reading, **`"w"`** for writing)  

**Returns:**

  - A pointer to a **`FILE`** structure on success
  - **`NULL`** if an error occurs.

**Example:**

```c
#include <stdio.h>

/**
 * main - Opens a file for writing.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	FILE *filePointer; /** Pointer to the file stream */

	/** Open "example.txt" for writing. Create it if it does not exist. */
	filePointer = fopen("example.txt", "w");
	if (filePointer == NULL)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** File is now open and ready for writing */

	/** Close the file stream */
	fclose(filePointer);

	return (0); /** Return 0 to indicate success */
}

```

### `fread`

**Definition:**

The **`fread`** function reads a block of data from a file into a buffer.

**Why Used it?**

**`fread`** allows for reading data in a structered and efficient manner.

**Template:**

```c
size_t fread(void *pointer_to_buffer, size_t size, size_t count, FILE *stream);
```

**Parameters:**

- **`pointer_to_buffer`:** Pointer to the buffer where data will be read into.
- **`size`:** Size of each element to read.
- **`count`:** Number of elements to read.
- **`stream`:** Pointer to a **`FILE`** structure.

**Returns:**

- The number of elements successfully read.
- **`-1`** if en of the file or error occurs.

**Example:**

```c
#include <stdio.h>

/**
 * main - Reads data from a file and prints it.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	FILE *filePointer; /** Pointer to the file stream */
	char buffer[100]; /** Buffer to store data read from the file */
	size_t bytesRead; /** Number of bytes read */

	/** Open "example.txt" for reading. */
	filePointer = fopen("example.txt", "r");
	if (filePointer == NULL)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Read data from the file into buffer */
	bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, filePointer);
	if (bytesRead < 0)
	{
		perror("Error reading from file"); /** Print error message if reading fails */
		fclose(filePointer); /** Close the file stream */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Null-terminate the buffer and print the data */
	buffer[bytesRead] = '\0';
	printf("Data read: %s\n", buffer);

	/** Close the file stream */
	fclose(filePointer);

	return (0);	/** Return 0 to indicate success */
}

```

### `fwrite`

**Definition:**

The **`fwrite`** function wrties a block of data from a buffer to a file.

**Why use it?**

**`fwrite`** allows for writing data in a structured and efficient manner.

**Template:**

```c
size_t fwrite(const void *pointer_to_data_to_write, size_t size, size_t count, FILE *stream);
```

**Parameters:**

- **`pointer_to_data_to_write`:** Pointer to the data to write.
- **`size`:** Size of each element to write.
- **`count`:** Number of elements to write.
- **`stream`:** Pointer to a **`FILE`** structure.

**Returns:**

- The number of elements successfully written.
- **`-1`** if an error occurs

**Example:**

```c
#include <stdio.h>

/**
 * main - Writes data to a file.
 * 
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	FILE *filePointer; /** Pointer to the file stream */
	const char *data = "Hello, fwrite!"; /** Data to be written */
	size_t bytesWritten; /** Number of bytes written */

	/** Open "example.txt" for writing. */
	filePointer = fopen("example.txt", "w");
	if (filePointer == NULL)
	{
		perror("Error opening file"); /** Print error message if opening fails */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Write data to the file */
	bytesWritten = fwrite(data, sizeof(char), strlen(data), filePointer);
	if (bytesWritten < strlen(data))
	{
		perror("Error writing to file"); /** Print error message if writing fails */
		fclose(filePointer); /** Close the file stream */
		return (-1); /** Return -1 to indicate an error occurred */
	}

	/** Close the file stream */
	fclose(filePointer);

	return (0); /** Return 0 to indicate success */
}

```
## Conclusion

This project covers the basics of file I/O operations in C, including system calls and higher-level file functions. Understanding these concepts is essential for handling files and data effectively in C programming.

## Author

Anne-Cécile Besse (Arc)