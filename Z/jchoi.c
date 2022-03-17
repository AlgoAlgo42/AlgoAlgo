/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 20:30:11 by jchoi             #+#    #+#             */
/*   Updated: 2022/03/17 20:51:16 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	main(void)
{
	int N, row, column;
	int exponent = 1, order = 0;

	scanf("%d %d %d", &N, &row, &column);
	for (int i = 1; i < N; i++)
		exponent *= 2;

	while (0 < exponent)
	{
		order += ((row / exponent) * 2 + (column / exponent)) * exponent * exponent;
		row %= exponent;
		column %= exponent;
		exponent /= 2;
	}
	printf("%d",order);
	return (0);
}
