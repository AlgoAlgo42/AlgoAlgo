/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:49:03 by jchoi             #+#    #+#             */
/*   Updated: 2022/04/08 18:49:06 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#define ROOT -1
typedef struct s_node
{
	int	number;
	struct s_node	*connected;
} t_node;

t_node  *ft_lstnew(int content)
{
        t_node  *ret;

        ret = (t_node *)malloc(sizeof(t_node));
        if (ret)
        {
                ret -> number = content;
                ret -> connected = NULL;
        }
        return (ret);
}

void    ft_lstadd_back(t_node *lst, t_node *new)
{
        t_node  *thislst;
		if (lst)
		{
			thislst = lst;
			while (thislst -> connected)
				thislst = thislst -> connected;
			thislst -> connected = new;
		}
}

void    ft_lstfree(t_node *lst)
{
	t_node	*ptr;
	t_node	*tmp;

	ptr = lst -> connected;
	while (ptr)
	{
		tmp = ptr -> connected;
		free(ptr);
		ptr = tmp;
	}
}

void	children(t_node	**edges, int *parents, int vertex)
{
	int		index;
	t_node	*edge;
	t_node	*ptr;

	edge = (*edges) + vertex;
	ptr = edge -> connected;
	while (ptr)
	{
		index = ptr -> number - 1;
		if (!parents[index])
		{
			parents[index] = edge -> number;
			children(edges, parents, index);
		}
		ptr = ptr -> connected;
	}
}

int	main(void)
{
	int N, v1, v2;
	int	*parents;
	t_node	*edges;
	
	scanf("%d", &N);
	edges = (t_node *)calloc(N, sizeof(t_node));
	for (int i = 0; i < N; i++)
		edges[i].number = i + 1;
	parents = (int *)calloc(N, sizeof(int));
	for (int i = 1; i < N; i++)
	{
		scanf("%d %d", &v1, &v2);
		ft_lstadd_back(edges + (v1 - 1), ft_lstnew(v2));
		ft_lstadd_back(edges + (v2 - 1), ft_lstnew(v1));
	}
	parents[0] = ROOT;
	children(&edges, parents, 0);

	for (int i = 1; i < N; i++)
		printf("%d\n", parents[i]);
	for (int i = 0; i < N; i++)
		ft_lstfree(edges + i);
	free(edges);
	free(parents);
	return (0);
}
