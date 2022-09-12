/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rade-sar <rade-sar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 05:13:14 by rade-sar          #+#    #+#             */
/*   Updated: 2022/09/12 12:22:33 by rade-sar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_free_mtx(char **mtx)
{
	int	i;

	i = -1;
	while (mtx[++i])
		free(mtx[i]);
	free(mtx);
}
