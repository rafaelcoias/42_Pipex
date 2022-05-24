/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:03:35 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/24 17:04:30 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

/* ERRORS */

# define FILE_ERROR "Could not access file (file path may not exist).\n"
# define DIR_ERROR "Argument is a directory, it must be a file."
# define CMD_ERROR "Argument is not a valid shell command.\n"

/* CHECK FUNCTIONS */

void	check_all(int argc, char **argv);
void	error_msg(char *str);

#endif
