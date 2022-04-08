/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:06:58 by jchoi             #+#    #+#             */
/*   Updated: 2022/04/08 16:07:00 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int	main(void)
{
	int N, max, tmp, total = 0;
	int time[1000];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", time + i);
	
	for (int i = 0; i < N; i++)
	{
		max = time[i];
		for (int j = i + 1; j < N; j++)
		{
			if (max < time[j])
			{
				tmp = time[j];
				time[j] = max;
				max = tmp;
			}
		}
		total += ((i + 1) * max);
	}
	printf("%d", total);
	return (0);
}
