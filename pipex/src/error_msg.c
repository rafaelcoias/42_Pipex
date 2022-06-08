/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:41:15 by rade-sar          #+#    #+#             */
/*   Updated: 2022/05/24 15:41:17 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error_msg(char *str)
{
	ft_putstr_fd(RED, 2);
	perror("\nError\n");
	ft_putstr_fd(RESET, 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}
