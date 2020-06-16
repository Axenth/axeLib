# AxeLib

A simple library I use during the 42 program at CODAM

## Functions

ft_atoi<br/>
ft_itoa<br/>
ft_bzero<br/>
ft_calloc<br/>
ft_convert_to_hex<br/>
ft_isalnum<br/>
ft_isalpha<br/>
ft_isascii<br/>
ft_isdigit<br/>
ft_isprint<br/>
ft_memcpy<br/>
ft_memccpy<br/>
ft_memchr<br/>
ft_memcmp<br/>
ft_memmove<br/>
ft_memset<br/>
ft_strlen<br/>
ft_strlcat<br/>
ft_strlcpy<br/>
ft_strnstr<br/>
ft_substr<br/>
ft_strncmp<br/>
ft_strchr<br/>
ft_strrchr<br/>
ft_strdup<br/>
ft_strmapi<br/>
ft_strjoin<br/>
ft_strtrim<br/>
ft_strcontains<br/>
ft_split<br/>
ft_tolower<br/>
ft_toupper<br/>
ft_putchar_fd<br/>
ft_putendl_fd<br/>
ft_putstr_fd<br/>
ft_putnbr_fd<br/>
ft_lstnew<br/>
ft_lstlast<br/>
ft_lstdelone<br/>
ft_lstclear<br/>
ft_lstadd_front<br/>
ft_lstadd_back<br/>
ft_lstiter<br/>
ft_lstsize<br/>
ft_lstmap<br/>
ft_printf<br/>
get_next_line<br/>
ft_sqrt<br/>
ft_pow<br/>
ft_abs<br/>
ft_floor<br/>
ft_ceil<br/>

## Usage of each Function

```
void				*ft_memset(void *b, int c, size_t len);
```
Description - The ft_memset() function fills the first len bytes of the memory area pointed to by b with the constant byte of c.<br/>
Return - The ft_memset() function returns a pointer to the memory area s.<br/>

```
void				ft_bzero(void *s, size_t n);
```
Description - The ft_bzero() function erased the data in the n bytes of the memory starting at the location pointed to by s, by writing zeroes (bytes containing '\0') to that area.<br/>
Return - None.<br/>

```
void				*ft_memcpy(void *dst, const void *src, size_t n);
```
Description - The ft_memcpy() function copies n bytes from memory area src to memory area dst. The memory areas must not overlap. Use ft_memmove() if the memory areas do overlap.<br/>
Return - The ft_memcpy() function returns a pointer to dest.<br/>

```
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
```
Description - The ft_memccpy() function copies no more than n bytes from memory area src to memory area dest, stopping when the character c is found. If the memory areas overlap, the results are undefined.<br/>
Return - The ft_memccpy() function returns a pointer to the next character in dest after c, or NULL if c was not found in the first n characters of src.<br/>


```
void				*ft_memmove(void *dst, const void *src, size_t len);
```
Description - The ft_memmove() function copies n bytes from memory area src to memory area dest. The memory areas may overlap: copying takes place as tough the bytes in src are first copied into a temporary array that does not overlap src or dest, and the bytes are then copied from the temporary array to dest.<br/>
Return - The ft_memmove() function returns a pointer to dest.<br/>

```
void				*ft_memchr(const void *s, int c, size_t n);
```
Description - The ft_memchr() function scans the initial n bytes of the memory area pointed to by s for the first instance of c. Both c and the bytes of the memory area pointed to by s are interpreted as unsigned char.<br/>
Return - The ft_memchr() function returns a pointer to the matching byte or NULL if the character does not occur in the given memory area.<br/>

```
int				ft_memcmp(const void *s1, const void *s2, size_t n);
```
Description - The ft_memcmp() function compares the first n bytes (each interpreted as unsigned char) of the memory areas s1 and s2.<br/>
Return - The ft_memcmp() function returns an integer less than, equal to, or greater than zero if the first n bytes of s1 is found, respectively, to be less than, to match, or be greater than the first n bytes of s2. For a nonzero return value, the sign is determined by the sign of the difference between the first pair of bytes (interpreted as unsigned char) that differ in s1 and s2. If n is zero, the return value is zero.<br/>

```
size_t				ft_strlen(const char *str);
```
Description - The ft_strlen() function calculates the length of the string pointed to by s, excluding the terminating null byte ('\0').<br/>
Return - The ft_strlen() function returns the number of characters in the string pointed to by s.<br/>

```
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
```
Description - The ft_strlcpy() function copies up to size - 1 characters from the NULL-terminated string src to dst, NULL-terminating the result.<br/>
Return - The ft_strlcpy() function returns the length of src.<br/>

```
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
```
Description - The ft_strlcat() function appends the NULL-terminated string srcs to the end of dst. It will append at most size - ft_strlen(dst) - 1 bytes, NULL-terminating the result.<br/>
Return - The ft_strlcat() function returns the initial length of dst plus the length of src.<br/>

```
char				*ft_strchr(const char *s, int c);
```
Description - The ft_strchr() function returns a pointer to the first occurence of the character c in string s.<br/>
Return - The ft_strchr() function returns a pointer the the matched character or NULL if the character is not found. The terminating NULL byte is considered part of the string, so that if c is specified as '\0', this function returns a pointer to the terminator.<br/>

```
char				*ft_strrchr(const char *s, int c);
```
Description - The ft_strrchr() function returns a pointer to the last occurence of the character c in string s.<br/>
Return - The ft_strrchr() function returns a pointer the the matched character or NULL if the character is not found. The terminating NULL byte is considered part of the string, so that if c is specified as '\0', this function returns a pointer to the terminator.<br/>

```
char				*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
```
Description - The ft_strnstr() function locates the first occurence of the NULL-terminated string needle in the string haystack, where not more than len characters are searched. Characters that appear after a '\0' character are not searched.<br/>
Return - If Needle is an empty string, Haystack is returned; if needle occurs nowhere in haystack, NULL is returned; otherwise a pointer to the first character of the first occurence of needle is returned.<br/>

```
int				ft_strncmp(const char *s1, const char *s2, size_t n);
```
Description - The ft_strncmp() function compares the two strings s1 and s2. It returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less then, to match, or be greater than s2. It only compares at most n bytes of s1 and s2.<br/>
Return - The ft_strncmp() function returns an integer less than, equal to, or greater than zero if s1 (or the first n bytes thereof) is found, respectively, to be less than, to match, or be greater than s2.<br/>

```
int				ft_atoi(const char *str);
```
Description - The ft_atoi() function converts the initial portion of the string pointed to by str to int.<br/>
Return - The converted value.<br/>

```
int				ft_isalpha(int c);
```
Description - The ft_isalpha() function checks wether or not c is an alphabetic character based on the ASCII Table.<br/>
Return - 1 for true; 0 for false.<br/>

```
int				ft_isdigit(int c);
```
Description - The ft_isdigit() function check wether or not c is a digit based on the ASCII Table.<br/>
Return - 1 for true; 0 for false.<br/>

```
int				ft_isalnum(int c);
```
Description - The ft_isalnum() function checks wether or not c is a alphabetic character or an digit based on the ASCII Table.<br/>
Return - 1 for true; 0 for false.<br/>

```
int				ft_isascii(int c);
```
Description - The ft_isascii() function check wether or not c is a character based on the ASCII table.<br/>
Return - 1 for true; 0 for false.<br/>

```
int				ft_isprint(int c);
```
Description - The ft_isprint() function checks wether or not c is a printable character based on the ASCII Table.<br/>
Return - 1 for true; 0 for false.<br/>

```
char				ft_toupper(char c);
```
Description - The ft_toupper() function converts c into an uppercase character.<br/>
Return - The ft_toupper() function returns the converted character. If the character cannot be converted the initial character is returned.<br/>

```
char				ft_tolower(char c);
```
Description - The ft_tolower() function converts c into an lowercase character.<br/>
Return - The ft_tolower() function returns the converted character. If the character cannot be converted the initial character is returned.<br/>

```
void				*ft_calloc(size_t count, size_t size);
```
Description - The ft_calloc() function allocates memory for an array of count elements of size bytes each and returns a pointer to the allocated memory. The memory is set to zero. <br/>
Return - The ft_calloc() function returns a pointer to the allocated memory. If the memory allocation fails or the memory cannot be set to zero than NULL is returned.<br/>

```
char				*ft_convert_to_hex(unsigned long value);
```
Description - The ft_convert_to_hex() function takes in a unsigned long and converts this value to its hexadecimal counter-part. <br/>
Return - The ft_convert_to_hex() function returns a pointer to the hexadecimal string. It returns NULL if insufficient memory was available.<br/>

```
char				*ft_strdup(const char *s1);
```
Description - The ft_strdup() function returns a pointer to a new string wich is a duplicate of the string s1. Memory for the new string is obtained with malloc(), and an be freed with free().<br/>
Return - On success, the ft_strdup() function returns a pointer the duplicated string. It returns NULL if insufficient memory was available.<br/>

```
char				*ft_substr(char const *s, unsigned int start, size_t len);
```
Description - The ft_substr() function allocates and returns a substring from the string s. The substring begins at index start and is of maximum size len.<br/>
Return - The ft_substr() function returns a substring from the string s.<br/>

```
char				*ft_strjoin(char const *s1, char const *s2);
```
Description - The ft_strjoin() function allocates and returns a new string wich is the result of the concatenation of s1 and s2.<br/>
Return - The ft_strjoin() function returns a new string consisting of both s1 and s2.<br/>

```
char				*ft_strtrim(char const *s1, char const *set);
```
Description - The ft_strtrim() function allocates and returns a copy of s1 with the characters specified in set removed from the beginning and end of the string.<br/>
Return - The ft_strtrim() function returns a copy of s1 with the sets removed from the beginning and end.<br/>

```
int					ft_strcontains(char *str, char *set);
```
Description - The ft_strcontains() functions checks to see if the set of characters is present within the string <br/>
Return - The ft_strcontains() functions returns 1 if the set is present 0 if its not present and -1 if there is an error <br/>

```
char				**ft_split(char const *s, char c);
```
Description - The ft_split() function allocates and returns an array of strings obtained by splitting s using the character c as a delimiter. The array ends with a NULL pointer.<br/>
Return - The ft_split() function returns an array of strings or NULL if the operation fails.<br/>

```
char				*ft_itoa(int n);
```
Description - The ft_itoa() function allocates and returns a string representing the integer received as an argument.<br/>
Return - The ft_itoa() function returns the string containing the integer. Null if the allocation fails.<br/>

```
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
```
Description - The ft_strmapi() function applies the function f to each character of the string s to create a new string resulting from successive applications of f.<br/>
Return - The ft_strmapi() function returns the string created from the successive applications of f. NULL if the allocation fails.<br/>

```
void				ft_putchar_fd(char c, int fd);
```
Description - The ft_putchar_fd() function outputs the character c to the given file descriptor fd.<br/>
Return - None.<br/>

```
void				ft_putstr_fd(char *s, int fd);
```
Description - The ft_putstr_fd function outputs the string s to the given file descriptor fd.<br/>
Return - None.<br/>

```
void				ft_putendl_fd(char *s, int fd);
```
Description - The ft_putendl_fd() function outputs the string s to the given file descriptor fd, followed by a newline.<br/>
Return - None.<br/>

```
void				ft_putnbr_fd(int n, int fd);
```
Description - The ft_putnbr_fd() function outputs the integer n to the given file descriptor fd.<br/>
Return - None.<br/>

```
t_list				*ft_lstnew(void *content);
```
Description - The ft_lstnew() function allocates and returns a new element. The variable content is initialized with the value of the parameter content. The variable next is initialized to NULL.<br/>
Return - The ft_lstnew() function returns a pointer to the new element.<br/>

```
void				ft_lstadd_front(t_list **alst, t_list *new);
```
Description - The ft_lstadd_front() function adds the element new at the beginning of the list lst.<br/>
Return - None.<br/>

```
int				ft_lstsize(t_list *lst);
```
Description - The ft_lstsize() function counts the number of elements in a list.<br/>
Return - The ft_lstsize() function returns the length of the list.<br/>

```
t_list				*ft_lstlast(t_list *lst);
```
Description - The ft_lstlast() function returns the last element of the list.<br/>
Return - The ft_lstlast() function returns a pointer to the last element of the list.<br/>

```
void				ft_lstadd_back(t_list **alst, t_list *new);
```
Description - The ft_lstadd_back() function adds the element new at the end of the list alst.<br/>
Return - None.<br/>

```
void				ft_lstdelone(t_list *lst, void(*del)(void *));
```
Description - The ft_lstdelone() function Takes as a parameter an element and frees the memory of the element's content using the function del given as a parameter adn free the element. The memory of next is not freed.<br/>
Return - None.<br/>

```
void				ft_lstclear(t_list **lst, void (*del)(void *));
```
Description - The ft_lstclear() function deletes and frees the given element and every successor of that element using the function del and free. Finally, the pointer of the list is set to NULL.<br/>
Return - None.<br/>

```
void				ft_lstiter(t_list *lst, void (*f)(void *));
```
Description - The ft_lstiter() function iterates the list lst and applies the function f to the content of each element.<br/>
Return - None.<br/>

```
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *)
```
Description - The ft_lstmap() function Iterates the list lst and applies the function f to the content of each element. Creates a new list resulting of the successive applications of the function f. The del function is ued to delete the content of an element if needed.<br/>
Return - The ft_lstmap() function returns the newly created list. Null if the allocation Fails.<br/>

```
int				ft_printf(const char *format, ...);
```
Description - The ft_printf() function replicates the behaviour of printf for the conversions: c s p d i u x X % and the flags: - 0 . * as well as minimum field width.<br/>
Return - The ft_printf() function returns the amount of characters printed.<br/>

```
int				get_next_line(int fd, char **line);
```
Description - The get_next_line() function reads a line from the file descriptor fd and returns the next line found.<br/>
Return - The get_next_line() function returns the next line from a file descriptor.<br/>

```
double				ft_sqrt(double x);
```
Description - The ft_sqrt() function takes in a double x and calculates the square root value. <br/>
Return - The ft_sqrt() function returns the square root of x. <br/>

```
double				ft_pow(double x, double y);
````
Description - The ft_pow() function calculates the value of x to the power of y. <br/>
Return - The ft_pow() function returns x^y. <br/>

```
int				ft_abs(int i);
```
Description - The ft_abs() function calculates the absolute value of i. <br/>
Return - The ft_abs() function returns the absolute value of i. <br/>

```
double				ft_fabs(double x);
```
Description - The ft_fabs() function calculates the absolute value of x. <br/>
Return - The ft_fabs() function returns the absolute value of x. <br/>

```
double				ft_floor(double x);
```
Description - The ft_floor() function calculates the largest integer possible that is equal to or lesser then x. <br/>
Return - The ft_floor() function returns the largest interger equal or lesser then x. <br/>

```
double				ft_ceil(double x);
```
Description - The ft_floor() function caluclates the largest integer possible that is equal to or greater then x. <br/>
Return - The ft_ceil() function returns the largest interger equal or greater then x. It returns x in the case of an error. <br/>

## Compiling

To compile the library simply call the makefile

```
make all
```

## Usage

Include the desired header in your .c file

```
#include <libft.h>
#include <libftmath.h>
```

and compile with the library and the path to the header

```
gcc main.c libft.a -I ./path_to_header
```
