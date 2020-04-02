/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1_open_cl.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperseus <mperseus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 15:35:02 by mperseus          #+#    #+#             */
/*   Updated: 2020/04/02 15:45:30 by mperseus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_OPEN_CL_H

# define RTV1_OPEN_CL_H

# include "rtv1.h"

# define CPU	0
# define GPU	1

t_open_cl	*init_open_cl(int device);
void		get_device(t_open_cl *open_cl, int device);
void		read_open_cl_kernel(t_open_cl *open_cl);
void		load_open_cl_kernel(t_open_cl *open_cl);

void		get_open_cl_info(t_open_cl *open_cl);
void		get_device_info(t_open_cl *open_cl);
void		get_platform_info(t_open_cl *open_cl);

void		run_open_cl(t_status *status, t_open_cl *open_cl, int *res);
void		set_arg_open_cl_kernel(t_status *status, t_open_cl *open_cl);
void		pack_arg_to_struct(t_status *status, t_kernel_arg *kernel_arg);
void		get_execution_time(t_open_cl *open_cl, cl_event event);

void		clean_open_cl(t_open_cl *open_cl);
void		clean_open_cl_1(t_open_cl *open_cl);
void		clean_open_cl_2(t_open_cl *open_cl);
void		clean_open_cl_info(t_open_cl *open_cl);

void		pfn_notify(const char *errinfo, const void *private_info, size_t cb,
			void *user_data);
void		put_error_pn(char *str);
void		put_open_cl_error(t_open_cl *open_cl, char *str);

#endif
