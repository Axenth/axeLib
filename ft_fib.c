

int     calcNext(int a, int b)
{
    return (a + b);    
}

int     *ft_fib (int startValueA, int startValueB, int amountOfTimes)
{
    int *result;
    int i;

    i = 2;
    result = (int)malloc(sizeof(int) * amountOfTimes + 2);
    result[0] = startValueA;
    result[1] = startValueB;
    while(i < amountOfTimes)
    {
        result[i] = calcNext(result[i - 2], result[i - 1]); 
    }

    return (result);
}
