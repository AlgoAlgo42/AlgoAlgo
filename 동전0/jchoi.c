/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:05:02 by jchoi             #+#    #+#             */
/*   Updated: 2022/04/08 14:05:05 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	int N, K, index, worth, count = 0;
	int	*coins;
	
	scanf("%d %d", &N, &K);
	coins = (int *)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++)
		scanf("%u",coins + i);
	index = N - 1;
	while (0 < K)
	{
		worth = coins[index];
		if (worth <= K)
		{
			count += (K / worth);
			K %= worth;
		}
		index--;
	}
	printf("%d", count);
	free(coins);
	return (0);
}
