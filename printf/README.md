# ft_printf

usage: <br/>

`ft_printf("Format", ...)` <br />

### ft_fprintf

usage: <br />

`ft_fprintf(1, "Format", ...)` <br/>

The first value given is the file descriptor to write to.

### Format

The format can handle the following conversions: <br />

* %c
* %s
* %p
* %d , %i
* %u
* %x , %X
* %%
<br />

It can also handle the following flags: <br />

* '-'
* '0'
* '.'
<br />

As well as minimum field with and supports * as a value. <br />

Conversions must always be done in the following format: <br />

` "% FLAGS WIDTH PRECISION TYPE"` <br />
Note: spaces are for readability and should not be included. <br />

Example: <br />
`ft_printf("%-50.2s", "Hello");`

In this example we tell it to print a string with a minimum width of 50 and a precision of 2 that is left justified. <br>
This will print: <br>
`"He"` followed by 48 spaces.

### Conversions

* `%c` This will print a variable of type char.
* `%s` This will print a variable of type char*.
* `%p` This will print the adress of a variable.
* `%i %d` These will print a variable of type int.
* `%u` This will print a variable of type unsigned int.
* `%x %X` These will print a unsigned int as lowercase or Uppercase hexadecimal.
* `%%` This will print a % symbol.

### Flags

* `-` This will left justify the printed conversion.
<br> note: the `0` flag will cancel out `-`
* `0` This will fill the empty spaces with 0's for the d i u x and X conversions.
* `.` Followed by a number will be the amount of characters printed from the conversion.
* `*` If used on the minimum field width or precision will grab the next variable from the va_list and use that instead of a given number.
