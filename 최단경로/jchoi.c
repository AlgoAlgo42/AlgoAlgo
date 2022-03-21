/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:32:46 by jchoi             #+#    #+#             */
/*   Updated: 2022/03/21 21:44:42 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fail due to memory exceed

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF INT_MAX - 1
#define DONE 1

int	main(void)
{
	int	V, E, K;
	int u, v, w, done, min, index;
	int *ptr;
	int *vertices;								// vertex array
	int	**adjmtx;								// adjacency matrix
	
	scanf("%d %d %d", &V, &E, &K);
	vertices = (int *)calloc(V, sizeof(int));
	adjmtx = (int **)calloc(V, sizeof(int *));
	for (int i = 0; i < V; i++)
		adjmtx[i] = (int *)calloc(V, sizeof(int));
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		ptr = adjmtx[u - 1] + (v - 1);
		if (!*ptr || w < *ptr)	// even among parallel edges, minimum should be selected
			*ptr = w;
	}
	for (int i = 0; i < V; i++)
		vertices[i] = INF;
	vertices[K - 1] = 0;


	done = V;		// in dijkstra algorithm, interate until set Q be empty
	while (done)	// int variable named 'done' means the number of element in set Q
	{
		min = INT_MAX;
		for (int i = 0; i < V; i++)		// find the minimum among vertices
		{
			if (!adjmtx[i][i] && vertices[i] < min)
			{
				min = vertices[i];
				index = i;
			}
		}
		// loop element in adjmtx used to check whether it's already done or not
		adjmtx[index][index] = DONE;	// because there's no loop
		done--;
		for (int i = 0; i < V; i++)
		{
			w = adjmtx[index][i] * (index != i);
			if (w && min + w < vertices[i])
					vertices[i] = min + w;
		}
	}

	for (int i = 0; i < V; i++)	// print each vertex value
	{
		if (vertices[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", vertices[i]);
	}
	for (int i = 0; i < V; i++)
		free(adjmtx[i]);
	free(adjmtx);
	free(vertices);
	return (0);
}
