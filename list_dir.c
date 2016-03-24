/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:08:10 by asalama           #+#    #+#             */
/*   Updated: 2016/03/23 15:30:18 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int		main(int argc, char **argv)
{
	DIR					*tmp;
	struct dirent		*ptr;
	struct stat			*buf;
	time_t				sec;
	
	if (argc == 2)
	{
		if (!(buf=(struct stat*)malloc(sizeof(struct stat))))
			return (1);
		if ((stat(argv[1], buf)) == -1)
			return (1);
		printf("------STAT------\n");
		printf("dev: %d\n", buf->st_dev);
		printf("ino: %llu\n", buf->st_ino);
		printf("mode: %d\n", buf->st_mode);
		printf("uid: %d\n", buf->st_uid);
		printf("gid: %d\n", buf->st_gid);
		printf("rdev: %d\n", buf->st_rdev);
		printf("size: %lld\n", buf->st_size);
		printf("blksize: %d\n", buf->st_blksize);
		printf("blocks: %lld\n", buf->st_blocks);
		printf("atime: %ld\n", buf->st_atime);
		printf("mtime: %ld\n", buf->st_mtime);
		printf("ctime: %ld\n", buf->st_ctime);
		
//		if (!(tmp = opendir(argv[1])))
//			return (1);
		while ((ptr = readdir(tmp)))
		{
			printf("------DIR------\n");
			printf("ino: %llu\n",ptr->d_ino);
//		printf("%llu\n",ptr->d_off);
			printf("reclen: %hu\n",ptr->d_reclen);
			printf("type: %hhu\n",ptr->d_type);
			printf("name: %s\n",ptr->d_name);
		}
		if (closedir(tmp) == -1)
			return (1);
	}
	else
		write (1, "\n", 1);

	sec = time(NULL);
	printf("time: %ld\n", sec/31104000);
	return (0);
}
