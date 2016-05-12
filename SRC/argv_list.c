#include "../Includes/ft_ls.h"

static void		argv_list_alpha(t_arg **lst, t_arg *new)
{
	t_arg *runner;

	if (*lst)
	{
		runner = *lst;
		if (list_len(lst) == 1)
		{
			((S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) == 1) || ((S_ISDIR(new->buf->st_mode) != 1 && S_ISREG(runner->buf->st_mode) == 1 && ft_strcmp(runner->name, new->name) > 0))) ? push_front(lst, new) : push_back(runner, new);
		}
			else
		{
			if (S_ISDIR(new->buf->st_mode) != 1)
				while (runner->next && S_ISDIR(new->buf->st_mode) != 1 && S_ISDIR(runner->buf->st_mode) != 1 && (ft_strcmp(runner->name, new->name) < 0))
					runner = runner->next;
			else if (S_ISDIR(new->buf->st_mode))
				while (runner->next && ((S_ISDIR(runner->buf->st_mode) != 1 || (((new->buf->st_mode) == (runner->buf->st_mode)) && ft_strcmp(runner->path, new->path) < 0))))
					runner = runner->next;
			if (runner->prev == NULL)
				push_front(&runner, new);
			else if ((runner->next == NULL && runner->buf->st_mode != 1 && new->buf->st_mode != 1 && ft_strcmp(runner->path, new->path) < 0) || (S_ISDIR(runner->buf->st_mode) != 1 && S_ISDIR(new->buf->st_mode) == 1))
				push_back(runner, new);
		}
	}
	else
		*lst = new;
}

static int		call_stat(t_arg *link, char *file, t_flags *option)
{
	t_arg		**arg_lst;
	
	if (!(arg_lst = (t_arg**)ft_memalloc(sizeof(t_arg*))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if (!(link->buf = (t_stat*)ft_memalloc(sizeof(t_stat))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if ((stat(file, link->buf)) == -1)
	{
		free(link->buf);
		free(link);
		return (-1);
	}
	if ((!(link->path = ft_strdup(file))) || (!(link->name = ft_strdup(file))))
	{
		if (link->path)
			free(link->path);
		free(link->buf);
		free(link);
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	link->prev = NULL;
	link->next = NULL;
	if (!option->t)
	{	argv_list_alpha(arg_lst, link);
	}
	else
		return(0);
	return (0);
}


int		get_av_list(char **argv, t_flags *option)
{
	t_arg		*link;
	
	if (!(link = (t_arg*)ft_memalloc(sizeof(t_arg))))
	{
		perror("error malloc");
		exit(EXIT_FAILURE);
	}
	if (call_stat(link, *argv, option) != -1)
		return (0);
	else
	{
//		error_list();
		return (-1);
	}
	return (0);
}
