/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:24:20 by jchoi             #+#    #+#             */
/*   Updated: 2022/03/18 11:26:53 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int scan(char **table, int N, int M, int row, int col)
{
	char	norm;
	int		i, j;
	int		size = 1;

	norm = table[row][col];
	j = col + 1;
	i = row + 1;
	while (i < N && j < M)
	{
		if (table[i][col] == norm && table[row][j] == norm && table[i][j] == norm)
			size = (i - row + 1) * (j - col + 1);
		i++;
		j++;
	}
	return (size);
}

int	main(void)
{
	int		N, M;
	char	**table;
	int		square, max = 1;

	scanf("%d %d", &N, &M);
	table = (char **)calloc(N, sizeof(char *));
	for (int i = 0; i < N; i++)
	{
		table[i] = (char *)calloc(M + 1, sizeof(char)); // if you use specifier %c, you should care about \n in input buffer
		scanf("%s", table[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			square = scan(table, N, M, i, j);
			if (max < square)
				max = square;
		}
	}
	printf("%d", max);

	for (int i = 0; i < N; i++)
		free(table[i]);
	free(table);
	return (0);
}
