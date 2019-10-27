/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blinnea <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:17:07 by blinnea           #+#    #+#             */
/*   Updated: 2019/10/25 19:17:13 by blinnea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"
#include <fcntl.h>

static void	cleanbody(char **map, int realsize)
{
	int i;

	i = 0;
	while (i < realsize)
		free(map[i++]);
	free(map);
}

static void	printbody(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(STDOUT_FILENO, map[i++], size);
		ft_putchar('\n');
	}
}

static int	makemap(t_field *map, int lstsize)
{
	int i;
	int j;

	map->realsize = (lstsize == 1 ? 4 : lstsize * 3);
	if (!(map->body = (char **)malloc(map->realsize * sizeof(char *))))
		return (ERR);
	i = -1;
	while (++i < map->realsize)
	{
		if (!(map->body[i] = (char *)malloc(map->realsize * sizeof(char))))
		{
			cleanbody(map->body, i);
			return (ERR);
		}
		j = 0;
		while (j < map->realsize)
			map->body[i][j++] = '.';
	}
	map->size = 2;
	return (OK);
}

static int	fill_landm(char *fname, t_list **tetrlst, t_field *map)
{
	int	fd;

	if ((fd = open(fname, O_RDONLY)) < 0)
		return (ERR);
	if (!(*tetrlst = gettetrlst(fd)))
	{
		close(fd);
		return (ERR);
	}
	close(fd);
	if (makemap(map, ft_lstsize(*tetrlst)) == ERR)
	{
		ft_lstdel(tetrlst, &deltetr);
		return (ERR);
	}
	return (OK);
}

int			main(int ac, char **av)
{
	t_list	*tetrlst;
	t_field	map;

	if (ac == 2)
	{
		if (fill_landm(av[1], &tetrlst, &map) == OK)
		{
			while (puttetrlst(tetrlst, &map) == ERR)
				map.size++;
			printbody(map.body, map.size);
			cleanbody(map.body, map.realsize);
			ft_lstdel(&tetrlst, &deltetr);
		}
		else
			ft_putendl("error");
	}
	else
		ft_putendl("usage: ./fillit source_file");
	return (0);
}
