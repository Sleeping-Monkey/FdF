/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssheba <ssheba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:40:44 by ssheba            #+#    #+#             */
/*   Updated: 2019/07/08 16:05:26 by ssheba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __APPLE__
	# define KEY_W 13
	# define KEY_A 0
	# define KEY_S 1
	# define KEY_D 2
	# define KEY_Q 12
	# define KEY_E 14
	# define KEY_R 15
	# define KEY_T 17
	# define KEY_Y 16
	# define KEY_U 32
	# define KEY_ESC 53
	# define WIN_X 1000
	# define WIN_Y 1000
# else
	# define KEY_W 119
	# define KEY_A 97
	# define KEY_S 115
	# define KEY_D 100
	# define KEY_Q 113
	# define KEY_E 101
	# define KEY_R 114
	# define KEY_T 116
	# define KEY_Y 121
	# define KEY_U 117
	# define KEY_ESC 65307
	# define WIN_X 300
	# defien WIN_Y 300
# endif
#endif