/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gimsang-won <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:45:10 by gimsang-w         #+#    #+#             */
/*   Updated: 2022/03/15 12:11:52 by gimsang-w        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace	std;

int	toalph(char	a)
{
	if (a >= 65 && a <= 90)
		return (a - 65);
	else if (a >= 97 && a <= 122)
		return (a - 97);
	return (-1);
}

void	count(const string &str, int *array)
{
	int	i,j,k;

	i = str.length();
	j = -1;
	while (++j < i)
	{
		k = toalph(str[j]);
		if (k >= 0)
			++array[k];
	}
}

void	bubble(int *array)
{
	int	max, j;

	j = 0;
	max = array[j];
	for (int i = 0; i < 26; ++i)
	{
		if (array[i] > max)
		{
			max = array[i];
			j = i;
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		if (array[i] == max && i != j)
		{
			cout << '?' << endl;
			return ;
		}
	}
	cout << (char)(j + 65) << endl;
	return ;
}

int	main(void)
{
	string		str;
	static int	b[26];

	cin >> str;
	count(str, b);
	bubble(b);
}
