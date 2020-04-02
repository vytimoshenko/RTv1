/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_open_cl_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:07:24 by mperseus          #+#    #+#             */
/*   Updated: 2020/04/02 16:04:01 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/rtv1_open_cl.h"

void	pfn_notify(const char *errinfo, const void *private_info, size_t cb,
		void *user_data)
{
	(void)private_info;
	(void)cb;
	(void)user_data;
	ft_putendl(errinfo);
}

void	put_error_pn(char *str)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": ");
	ft_putendl(str);
	exit(1);
}

void	put_open_cl_error(t_open_cl *open_cl, char *str)
{
	ft_putstr(PROGRAM_NAME);
	ft_putstr(": error occured in OpenCL function ");
	ft_putendl(str);
	clean_open_cl(open_cl);
	exit(1);
}
