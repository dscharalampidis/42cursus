/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcharala <dcharala@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 04:00:51 by dcharala          #+#    #+#             */
/*   Updated: 2022/08/29 05:37:44 by dcharala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int
	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	(void)argc;
	if (!argv[1])
	{
		printf("Error: No file provided.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	printf("fd[%s]: %d\n", argv[1], fd);
	line = ft_strdup("");
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
		usleep(100000);
	}
	free(line);
	close(fd);
	return (0);
}
