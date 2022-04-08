/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:03:40 by jchoi             #+#    #+#             */
/*   Updated: 2022/04/08 23:03:49 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define INF 16384
void	path(int map[][100], int mtx[][100], int i, int j, int pre, const int M, const int N)
{
	pre++;
	if (pre < map[i][j])
	{
		map[i][j] = pre;
		if (0 < i && mtx[i - 1][j])
			path(map, mtx, i - 1, j, pre, M, N); 
		if (0 < j && mtx[i][j - 1])
			path(map, mtx, i, j - 1, pre, M, N); 
		if (i + 1 < M && mtx[i + 1][j])
			path(map, mtx, i + 1, j, pre, M, N); 
		if (j + 1 < N && mtx[i][j + 1])
			path(map, mtx, i, j + 1, pre, M, N); 
	}
}

int	main(void)
{
	int	M, N;
	int	mtx[100][100];
	int	map[100][100];

	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", mtx[i] + j);
			map[i][j] = INF;
		}
	}
	path(map, mtx, 0, 0, 0, M, N);
	printf("%d", map[M - 1][N - 1]);
	return (0);
}
