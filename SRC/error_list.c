#include "../Includes/ft_ls.h"

static void		err_push_front(t_err **lst, t_err *new)
{
	new->next = *lst;
	(*lst)->prev = new;
	*lst = new;
}

static void		err_push_back(t_err *runner, t_err *new)
{
	runner->next = new;
	new->prev = runner;
}

void		error_list(t_err **lst, char *file, int error)
{

}
