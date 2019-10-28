/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 14:29:47 by jlensing       #+#    #+#                */
/*   Updated: 2019/10/28 15:31:18 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *str1, char *str2, int n)
{
	int i;
	int count1;
	int count2;

	count1 = 0;
	count2 = 0;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] - 48 > str2[i] - 48)
				return (1);
			else if (str1[i] - 48 < str2[i] - 48)
				return (-1);
		}
		i++;
	}
	return (0);
}
