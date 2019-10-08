void ft_sqrt(int value)
{
    int i;

    while (i < value)
    {
        if (i * i == value)
            return (i);
        else
            i++;
    }
}