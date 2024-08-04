Readme from ArcturusSky

This README.md will hold the template I used for every README.md for each directory.

# Main subject of my README.md

This repository is part of the `low-programming` parent repository focused on C programming. Here, I'm starting to learn and work with...

Note : I will also update that README.md regarding new concepts I have to learn during these projects.

## Summary

- [Main subject of my README.md](#main-subject-of-my-readmemd)
	- [Summary](#summary)
	- [Glossary (in alphabetical order)](#glossary-in-alphabetical-order)
	- [Conversion Between Number Systems](#conversion-between-number-systems)
		- [Hexadecimal to Decimal](#hexadecimal-to-decimal)
		- [Binary to Decimal](#binary-to-decimal)
		- [Decimal to Binary](#decimal-to-binary)
	- [Key Concepts](#key-concepts)
		- [Bitwise Operators](#bitwise-operators)
		- [Bit Masking](#bit-masking)
		- [Template of How to perform bit masking](#template-of-how-to-perform-bit-masking)
		- [Bit Shifting](#bit-shifting)
		- [Bit Fields](#bit-fields)
	- [Conclusion](#conclusion)
	- [Author](#author)

## Glossary (in alphabetical order)

**A**

- **AND Operator (&):** A bitwise operator that performs a logical AND operation on each bit of its operands.

**B**

- **Bit:** The smallest unit of data in a computer, which can be either 0 or 1.

**C**

- **Clear a Bit:** Setting a specific bit to 0.

**D**

- **Divide-and-Conquer Algorithm:** An algorithm design paradigm that solves a problem by dividing it into smaller subproblems.

**E**

- **Endianness:** The order in which bytes are ordered within larger data types.

**F**

- **Flag:** A bit used to indicate the status of some condition or setting.

**G**

- **Get Bit:** Retrieving the value of a specific bit.

**H**

- **Hexadecimal:** A base-16 number system used in computing to represent binary values in a more readable form.

**I**

- **Increment:** Increasing a value, often used in bit manipulation to set or toggle bits.

**J**

- **Jitter:** Small variations in timing or data values, often considered in real-time computing.

**K**

- **Kernel-Level Operations:** Operations performed at the kernel level of an operating system, which may involve bit manipulation for efficiency.

**L**

- **Logical Shift:** A bit shift operation where the vacant bit positions are filled with zeros.

**M**

- **Mask:** A value used in bitwise operations to isolate or modify specific bits.

**N**

- **Negate:** To invert the bits of a value (change 0s to 1s and 1s to 0s).

**O**

- **OR Operator (|):** A bitwise operator that performs a logical OR operation on each bit of its operands.

**P**

- **Parity Bit:** An additional bit used to ensure that the number of set bits is even or odd.

**Q**

- **Query:** Checking the state of a specific bit or bit field.

**R**

- **Rotate:** Circular shifting of bits, where bits that fall off one end are reintroduced at the other end.

**S**

- **Set a Bit:** Changing a specific bit to 1.

**T**

- **Toggle:** Flipping a bit from 0 to 1 or from 1 to 0.

**U**

- **Unsigned Integer:** An integer type that can only represent non-negative values.

**V**

- **Value Mask:** A mask used to extract specific bits from a value.

**W**

- **Word:** A unit of data that is typically larger than a byte and is manipulated as a whole in a processor.

**X**

- **XOR Operator (^):** A bitwise operator that performs an exclusive OR operation on each bit of its operands.

**Y**

- **Yield:** In programming, the term can refer to temporarily relinquishing control or data, which can sometimes be managed via bit manipulation.

**Z**

- **Zero Fill:** Filling vacant bit positions with zeros.

## Conversion Between Number Systems

### Hexadecimal to Decimal

To convert a hexadecimal number to decimal:
1. Multiply each digit by 16 raised to the power of its position.
2. Sum the results of these multiplications.

**Example:**
Convert `0x89` to decimal:
- 0x89 = 8 * 16^1 + 9 * 16^0
- 8 * 16 + 9 * 1
- 128 + 9 = 137

### Binary to Decimal

To convert a binary number to decimal:
1. Multiply each bit by 2 raised to the power of its position.
2. Sum the results of these multiplications.

**Example:**
Convert `0b1011` to decimal:
- 0b1011 = 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 1 * 2^0
- 1 * 8 + 0 * 4 + 1 * 2 + 1 * 1
- 8 + 2 + 1 = 11

### Decimal to Binary

To convert a decimal number to binary:
1. Repeatedly divide the number by 2.
2. Record the remainders in reverse order.

**Example:**
Convert `13` to binary:
- 13 ÷ 2 = 6 remainder 1
- 6 ÷ 2 = 3 remainder 0
- 3 ÷ 2 = 1 remainder 1
- 1 ÷ 2 = 0 remainder 1
- Read remainders in reverse order: `1101`


## Key Concepts

### Bitwise Operators

**Definition:**

Bitwise operators are used to perform bit-level operations on data. Common bitwise operators include AND (`&`), OR (`|`), XOR (`^`), and NOT (`~`).

**Why using it?**

Bitwise operations are often used for low-level programming tasks, such as setting flags, masking bits, and performing efficient arithmetic operations.

### Bit Masking

**Definition:**

Bit masking involves using a mask to isolate or modify specific bits in a value.

**Why using it?**

Bit masking is useful for extracting or altering particular bits without affecting the others.


### Template of How to perform bit masking

```c
#define MASK 0x0F  // Define a mask with specific bits set

unsigned int value = 0xAB;  // Example value
unsigned int result = value & MASK;  // Apply the mask
```

**Example:**

```c
#include <stdio.h>

#define MASK 0x0F

int main(void) {
    unsigned int value = 0xAB;  // 10101011 in binary
    unsigned int result = value & MASK;  // 00001011 in binary
    printf("Result: 0x%X\n", result);  // Output: 0x0B
    return 0;
}
```

### Bit Shifting

**Definition:**

Bit shifting involves moving the bits of a value to the left or right.

**Why using it?**

Bit shifting is used for efficient multiplication or division by powers of two and for packing and unpacking data.

**Template How to perform bit shifting:** 

```c 
unsigned int value = 0x01;  // Example value
unsigned int left_shift = value << 3;  // Left shift by 3 bits
unsigned int right_shift = value >> 2;  // Right shift by 2 bits

``` 

  - **Exemple:**

```c
 #include <stdio.h>

int main(void) {
    unsigned int value = 0x01;  // 00000001 in binary
    unsigned int left_shift = value << 3;  // 00001000 in binary
    unsigned int right_shift = value >> 2;  // 00000000 in binary
    printf("Left Shift: 0x%X\n", left_shift);  // Output: 0x8
    printf("Right Shift: 0x%X\n", right_shift);  // Output: 0x0
    return 0;
}

```

### Bit Fields

**Definition:**

Bit fields are a way to allocate a specific number of bits for individual members within a struct.

**Why using it?**

Bit fields help manage memory usage by packing multiple variables into a single word.

**Template of "How to use bit fields"**
 
```c
struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 3;
    unsigned int flag3 : 4;
};

```

**Example**

```c
#include <stdio.h>

struct Flags {
    unsigned int flag1 : 1;
    unsigned int flag2 : 3;
    unsigned int flag3 : 4;
};

int main(void) {
    struct Flags myFlags = {1, 5, 10};  // Initialize bit fields
    printf("Flag1: %u\n", myFlags.flag1);
    printf("Flag2: %u\n", myFlags.flag2);
    printf("Flag3: %u\n", myFlags.flag3);
    return 0;
}
```
## Conclusion

Bit manipulation is a fundamental concept in computer science and programming that involves directly handling and modifying the individual bits of data. This technique is crucial for optimizing performance, managing data at a low level, and implementing various algorithms and systems efficiently.

Understanding bit manipulation not only improves your ability to write efficient code but also deepens your comprehension of how data is represented and processed at the hardware level. By mastering operations such as AND, OR, XOR, shifts, and masks, you gain the tools to tackle complex problems and enhance your programming skills.

As you continue to explore and apply bit manipulation techniques, remember to practice with different problems and scenarios. This will help solidify your understanding and allow you to leverage bit manipulation effectively in your projects.


## Author

Anne-Cécile Besse (Arc)