#include <unistd.h>

ft_putchar (char c);

ft_putstr(char *str)
{
    int i;

    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}