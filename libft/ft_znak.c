/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_znak.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:23:11 by ssoraka           #+#    #+#             */
/*   Updated: 2019/04/16 13:27:27 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_znak(int n)
{
	if (n > 0)
		return (1);
	else if (n == 0)
		return (0);
	else
		return (-1);
}