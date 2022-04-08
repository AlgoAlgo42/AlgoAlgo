#include <stdio.h>
#include <stdlib.h>
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
void path(t_node **edges, int *counted, int vertex, int *count)
{
	int		index;
	t_node	*edge;
	t_node	*ptr;

	edge = (*edges) + vertex;
	ptr = edge -> connected;
	while (ptr)
	{
		index = ptr -> number - 1;
		if (!counted[index])
		{
			(*count)++;
			counted[index] = 1;
			path(edges, counted, index, count);
		}
		ptr = ptr -> connected;
	}

	
}
int	main(void)
{
	int V, E, v1, v2, count = 0;
	int	*counted;
	t_node	*edges;
	
	scanf("%d %d", &V, &E);
	edges = (t_node *)calloc(V, sizeof(t_node));
	counted = (int *)calloc(V, sizeof(int));
	for (int i = 0; i < V; i++)
		edges[i].number = i + 1;
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d", &v1, &v2);
		ft_lstadd_back(edges + (v1 - 1), ft_lstnew(v2));
		ft_lstadd_back(edges + (v2 - 1), ft_lstnew(v1));
	}
	counted[0] = 1;
	path(&edges, counted, 0, &count);
	printf("%d", count);
	for (int i = 0; i < V; i++)
		ft_lstfree(edges + i);
	free(edges);
	free(counted);
	return (0);
}
