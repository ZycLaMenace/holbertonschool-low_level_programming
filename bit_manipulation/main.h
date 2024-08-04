#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <fcntl.h> /** Includes definitions for file control operations */
#include <unistd.h> /** Includes definitions for POSIX constants and types */
#include <stdlib.h> /** Includes definitions for mem management operations */

int _putchar(char c);
	/**Fonction utilitaire servant à remplacer putchar classique */

int _isupper(int c);
	/**
	 * Fonction utilitaire servant à vérifier les Majuscules
	 * si MAJUSCULES return 1
	 * sinon 0
	 */

int _isdigit(int c);
	/**
	 * Fonction utilitaire servant à vérifier les chiffres
	 * si chiffres return 1
	 * sinon 0
	 */

int mul(int, int);
	/**
	* mul - Fonction utilitaire pour multiplier deux entiers
	* Return: the result
	*/

void print_numbers(void);
	/** Fonction utilitaire servant à imprimer les chiffres de 0 à 9 */

void print_most_numbers(void);
	/** Fonction utilitaire servant à print les chiffres de 0 à 9 sans 2 et 4 */

void more_numbers(void);
	/** Fonction utilitaire servant à imprimer les chiffres de 0 à 14 fois 10*/

void print_line(int n);
	/** Fonction utilitaire permettant de dessiner une ligne droite */

void print_diagonal(int n);
	/** Fonction utilitaire permettant de dessiner une ligne diagonale */

void print_square(int size);
	/** Fonction utilitaire permettant de dessiner un carré */

void print_triangle(int size);
	/** fonction utilitaire permettant de dessiner un triangle */


void print_alphabet(void);
	/** Fonction utilitaire servant à imprimer l'alphabet en minuscule */

void print_alphabet_x10(void);
	/** Fonction utilitaire servant à imprimer l'alphabet en minuscule 10 fois */

int _islower(int c);
	/**
	 * Fonction utilitaire servant à vérifier les minuscules
	 * si minuscules return 1
	 * sinon 0
	 */

int _isalpha(int c);
	/**
	 * Fonction utilitaire servant à vérifier les caractères
	 * si caractère alphanumerique return 1
	 * sinon 0
	 */

int print_sign(int n);
	/**
	 * Fonction utilitaire servant à print le signe d'un nombre
	 * si positif return 1, si 0 return 0, si negatif return -1
	 * sinon 0
	 */

int _abs(int);
	/** Fonction utilitaire servant à computer les valeurs absolues en int */

int print_last_digit(int);
	/** Fonction utilitaire servant print le dernier digit */

void jack_bauer(void);
	/** Fonction utilitaire permettant chaque min de la journée de Jack Bauer */

void times_table(void);
	/** Fonction uti permettant de print la "9 times table" commençant par 0 */

int add(int, int);
	/**
	* add - Fonction utilitaire pour additioner deux entiers
	* Return: the sum
	*
	*/
void print_to_98(int n);
	/** Fonction uti pour print tous les nbs naturels de n à 98, suivi d'un \n */

int _isupper(int c);
	/**
	 * Fonction utilitaire servant à vérifier les Majuscules
	 * si MAJUSCULES return 1
	 * sinon 0
	 */

int _isdigit(int c);
	/**
	 * Fonction utilitaire servant à vérifier les chiffres
	 * si chiffres return 1
	 * sinon 0
	 */

int mul(int, int);
	/**
	* mul - Fonction utilitaire pour multiplier deux entiers
	* Return: the result
	*/

void print_numbers(void);
	/** Fonction utilitaire servant à imprimer les chiffres de 0 à 9 */

void print_most_numbers(void);
	/** Fonction utilitaire servant à print les chiffres de 0 à 9 sans 2 et 4 */

void more_numbers(void);
	/** Fonction utilitaire servant à imprimer les chiffres de 0 à 14 fois 10*/

void print_line(int n);
	/** Fonction utilitaire permettant de dessiner une ligne droite */

void print_diagonal(int n);
	/** Fonction utilitaire permettant de dessiner une ligne diagonale */

void print_square(int size);
	/** Fonction utilitaire permettant de dessiner un carré */

void print_triangle(int size);
	/** Fonction utilitaire permettant de dessiner un triangle */

void reset_to_98(int *n);
	/** Fonction utilitaire permettant d'update la valeur pointée à 98 */

void swap_int(int *a, int *b);
	/** Fonction utilitaire permettant de swap la valeur de deux entiers */

int _strlen(char *s);
	/** Fonction utilitaire retournant la taille d'un string */

void _puts(char *str);
	/** Fonction utilitaire permettant de print le string */

void print_rev(char *s);
	/** Fonction utilitaire permettant d'imprimer le string à l'envers */

void rev_string(char *s);
	/** Fonction uti permettant d'obtenir une string inversée (pas de la print)*/

void puts2(char *str);
	/**
	 * Fonction utilitaire permettant d'imprimer 2 char sur 2 dans une string
	 * (exemple : "HelloWorld" devient "Hlood")
	 */

void puts_half(char *str);
	/**
	 * Fonction utilitaire servant à imprimer la moitié d'une string
	 * (exemple : "0123456789" devient "56789")
	 */

void print_array(int *a, int n);
	/**
	 * Fonction utilitaire permettant d'imprimer "n"
	 * éléments d'un tableau d'entiers
	 */

char *_strcpy(char *dest, char *src);
	/**
	 * Fonction uti servant à copier la string pointée par "src" inclus \0
	 * vers le buffer "dest".
	 */

int _atoi(char *s);
	/**
	 * Fonction permettant de convertir un string en interger
	 */

char *_strcat(char *dest, char *src);
	/**
	 * Fonction permettant de concatener deux strings.
	 */

char *_strncat(char *dest, char *src, int n);
	/**
	 * Fonction permettant de concatener deux strings mais différemment.
	 */

char *_strncpy(char *dest, char *src, int n);
	/**
	 * Fonction uti servant à copier la string pointée par "src" inclus \0
	 * vers le buffer "dest".
	 */

int _strcmp(char *s1, char *s2);
	/**
	 * Fonction permettant de comparer deux strings
	 */

void reverse_array(int *a, int n);
	/**
	 * Fonction permettant de renverse un tableau d'entier
	 */

char *string_toupper(char *str);
	/**
	 * Fonction permettant de transformer les lower case en uppercase
	 */

char *cap_string(char *);
	/**
	 * Fonction permettant de mettre une majuscule à chaque mot
	 */

char *_memset(char *s, char b, unsigned int n);
	/**
	 * Fonction permettant d'ajouter à la mémoire un byte
	 * (en gros d'incrémenter d'une valeur...)
	 */

void *_memcpy(void *dest, const void *src, size_t n);
	/**
	 * Function that copies a memory block specified by the parameter src
	 * and which the size has been specified by the parameter size,
	 * in a new emplacement designated by dest
	 */

char *_strchr(char *s, char c);
	/**
	 * Fonction permettant de trouver un character dans un string
	 */

unsigned int _strspn(char *s, char *accept);
	/**
	 * Fonction permettant de trouver le nombre de bytes dans la string "s"
	 * contenant seulement les bytes (character) de "accept"
	 */

char *_strpbrk(char *s, char *accept);
	/**
	 * Fonction permettant de rechercher la première occurrence
	 * dans la chaîne "s" de l'un des caractères de la chaîne "accept"
	 * Et retourne le pointeur là où il se trouve
	 */

char *_strstr(char *haystack, char *needle);
	/**
	 * Fonction permettant de retrouver une sous string dans une string
	 * les caractères "\0" ne sont pas comparés
	 */

void print_chessboard(char (*a)[8]);
	/**
	 * Fonction permettant d'imprimer un échiquier
	 */

void print_diagsums(int *a, int size);
	/**
	 * Fonction permettant de print la somme de la diagonale
	 * d'une matrice en forme de carré (en gros d'un tableau)
	 */

char *create_array(unsigned int size, char c);
	/**
	 * Function that creates an array of chars
	 * and initialized it with a specific char.
	 */

char *_strdup(char *str);
	/**
	 * Function that returns a pointer to a newly allocated space in memory
	 * which contains a copy of the string given as a parameter.
	 */

char *str_concat(char *s1, char *s2);
	/** Function that concatenates two strings */

int **alloc_grid(int width, int height);
	/** Function that returns a pointer to a 2 dimensional array of integers */

void free_grid(int **grid, int height);
	/**
	 * Function that free a 2 dimensional grid previously
	 * created by alloc_grid function
	 */

char *argstostr(int ac, char **av);
	/**
	 * Function that concatenates all the arguments of your program
	 */

void *malloc_checked(unsigned int b);
	/**
	 * Function that allocates memory using malloc
	 * and also introduce the use of exit
	 */

char *string_nconcat(char *s1, char *s2, unsigned int n);
	/**
	 * Function that concatenates two strings
	 */

void *_calloc(unsigned int nmemb, unsigned int size);
	/**
	 * Function that allocates memory for an array, using malloc.
	 */

int *array_range(int min, int max);
	/**Function that creates an array of integers. */

ssize_t read_textfile(const char *filename, size_t letters);
	/** Function that reads a text file and prints it to the POSIX std output */

int create_file(const char *filename, char *text_content);
	/** Function to create a file */

int append_text_to_file(const char *filename, char *text_content);
	/** Function to append text at the end of a file */

/** -------------- Part to try to lighten my code -------------- */

#define BUFFER_SIZE 1024

int close_file_free_buff(int file_descriptor, char *buf, int returnval);
	/** Function to shorten close file, free buff and return value */

int close_file_no_free(int file_descriptor, int returnval);
	/** Function to shorten close file without freeing buff and return value */

unsigned int binary_to_uint(const char *b);
	/** Function that converts a binary number to an unsigne int */

#endif
