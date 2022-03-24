/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:38:55 by jchoi             #+#    #+#             */
/*   Updated: 2022/03/15 22:40:18 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define ATTEND	1
#define TRUTH	2
int check(int **table, int people, int party, int i, int j)
{
	int ret = 0;
	for (int k = 0; k < party; k++)
	{
		if (table[i][k] == ATTEND)
		{
			table[i][k] = TRUTH;
			ret++;
		}
	}
	for (int k = 0; k < people; k++)
	{
		if (table[k][j] == ATTEND)
		{
			table[k][j] = TRUTH;
			ret++;
		}
	}
	return (ret);
}

int	main(void)
{
	int	**table;
	int	*aware_list;
	int	people, party, aware;	
	int	number, guest, flag, bluffs = 0;

	scanf("%d %d\n%d", &people, &party, &aware);
	table = (int **)calloc(people, sizeof(int *));
	for (int i = 0; i < people; i++)
		table[i] = (int *)calloc(party, sizeof(int));

	aware_list = (int *)calloc(aware, sizeof(int));
	for (int i = 0; i < aware; i++)
		scanf("%d", aware_list + i);


	for (int i = 0; i < party; i++)			// write attending table.
	{
		scanf("%d", &number);
		for (int j = 0; j < number; j++)
		{
			scanf("%d", &guest);
			table[guest - 1][i] = ATTEND;
		}
	}

	

	for (int i = 0; i < aware; i++)
	{
		for (int j = 0; j < party; j++)
			table[aware_list[i] - 1][j] *= TRUTH;
	}
	flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < people; i++)
		{
			for (int j = 0; j < party; j++)
			{
				if (table[i][j] == TRUTH)
					flag += check(table, people, party, i, j);
			}
		}
	}
	

	for (int i = 0; i < party; i++)
	{
		for (int j = 0; j < people; j++)
		{
			if (table[j][i] == ATTEND)
			{
				bluffs++;
				break;
			}
		}
	}
	printf("%d", bluffs);
	

	if (aware)
		free(aware_list);
	for (int i = 0; i < people; i++)
		free (table[i]);
	free(table);

	return (0);
}
