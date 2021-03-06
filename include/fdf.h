/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:51:23 by apakhomo          #+#    #+#             */
/*   Updated: 2018/01/30 15:51:23 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_brz
{
	int				px;
	int				py;
	int				dx;
	int				dy;
	int				xinc;
	int				yinc;
	unsigned long	pc;
}					t_brz;

typedef struct		s_map
{
	float			px;
	float			py;
	float			pz;
	int				z;
	unsigned long	pc;
	struct s_map	*next;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				window;
	unsigned long	fill;
	int				fd;
	int				ret;
	char			*str;
	char			**map;
	int				how_x;
	int				how_y;
	int				iter;
	int				move;
	int				coloriz;
	int				show;
	float			firstx;
	float			firsty;
	float			lastx;
	float			lasty;
	float			radx;
	float			rady;
	float			radz;
	float			shiftx;
	float			shifty;
	float			zoom;
	float			zoomnew;
	struct s_map	*line;
}					t_mlx;

void				free_data(t_mlx *data, int a);
int					check_flags(t_mlx *data, int argc, char **argv);
int					create_fdf_map(t_mlx *data, int a, int count);
void				rotate_fdf(t_mlx *data, int l);
void				scale(t_mlx *data, int flag);
void				start_fdf(t_mlx *data);
void				brz_start(t_mlx *data, t_map *lines, int y, int x);
int					deal_key(int k, t_mlx *data);

#endif
