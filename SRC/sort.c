// fonction sort alpha
// fonction sort time
// fonction sort files and dir
// fonction sort reverse

#include "ft_ls.h"

void			arg_sort_alpha(t_arg **arg_lst, t_arg *new)
{
	t_arg	*runner;

	runner = *arg_lst;

	while (runner->next != NULL)
	{
		if (ft_strcmp(runner->name, new->name) < 0)
		{	
			ft_putendl(runner->name);
			runner = runner->next;
		}
		else
		{
			ft_putendl("NOT SORTED");
			push_back(runner, new);
//			if (runner->prev)
//			{
//				runner->prev->next = runner->next;
//			}
//			if (runner->next)
//			{
//				runner->next->prev = runner->prev;
//			}
//			runner->next = link;
//			link->prev = runner;
			runner = runner->next;
		}
//		runner = *arg_lst;
	}
}


/*	while (runner->next != NULL && ft_strcmp(runner->name, link->name) < 0)
	{
//		ft_putendl(runner->name);
		runner = runner->next;
	}
	if (runner->next != NULL && ft_strcmp(runner->name, link->name) > 0)
	{
		ft_putendl(runner->name);
		push_front(arg_lst, link);
	}


//	if (runner->prev == NULL)
//		push_front(arg_lst, link);

	{
		ft_putendl("SORT ALPHA");
		if (ft_strcmp(link->name, runner->name) > 0)
		{
			push_back(runner, link);
		}
		runner = runner->next;
	}
*/

void			arg_sort_time(t_arg **arg_lst, t_arg *link)
{

}
