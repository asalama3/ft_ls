#include "../Includes/ft_ls.h"

int		list_len(t_arg **lst)
{
	t_arg	*runner;
	int		n;

	if (*lst)
	{
		n = 0;
		printf("%d\n", n);
		runner = *lst;
		while (runner)
		{
			n++;
			runner = runner->next;
		}
		return (n);
	}
	return (0);
}

void	push_front(t_arg **lst, t_arg *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

void	push_back(t_arg *runner, t_arg *new)
{
	runner->next = new;
	new->prev = runner;
}

