/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pminialg <pminialg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/23 09:55:33 by pminialg      #+#    #+#                 */
/*   Updated: 2024/03/28 11:03:58 by pminialg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAXITER 50

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdbool.h>

/* STRUCTS */
typedef struct s_complex
{
	double	x; // real value on the x axis
	double	y; // imaginary value on the y axis
}	t_complex;

typedef struct s_colour
{
	double	red;
	double	green;
	double	blue;
}	t_colour;

// mlx_image_t *img , is the same thing as the
// mlx_get_data_addr function in different version

typedef struct s_fractal
{
	char			*name; // name of fractal
	mlx_t			*mlx; // mlx_init(), old version mlx_new_image()
	mlx_image_t		*img;
	double			escape;
	int				iterations;
	double			shift_x;
	double			shift_y;
	double			zoom;
	double			julia_x; // input value for julia set
	double			julia_y; // input value for julia set
	t_colour		colour;
	uint32_t		palette[MAXITER];
}	t_fractal;

/* COLORS */
void		initialize_palette(t_fractal *fractal);
void		shift_palette(t_fractal *fractal);

/* INITIALIZE */
void		init_fractal(t_fractal *fractal);
/* MAIN */
void		error_function(int value);

/* KEYS */
void		my_keyhook(void *param);
void		close_window(void *param);

/* MOUSE */
void		my_scrollhook(double xdelta, double ydelta, void *param);

/* RENDER */
void		render_fractal(t_fractal *fractal);

/* UTILS MATH*/
t_complex	sum_complex(t_complex z, t_complex c);
t_complex	square_complex(t_complex z);
double		scale(int point, double new_min, double new_max, int old_max);
double		atodbl(char *str);
#endif