/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jlensing <jlensing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 16:08:10 by jlensing      #+#    #+#                 */
/*   Updated: 2020/04/06 19:10:26 by jlensing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>

typedef int				t_bool;
enum {	e_false, e_true	};

struct					s_info
{
	int					format_type;
	int					position;
	int					width;
	int					toprint;
	int					amount;
	int					prec;
	t_bool				width_flag;
	t_bool				dash_flag;
	t_bool				zero_flag;
	t_bool				precision_flag;
	t_bool				print;
	t_bool				negative_flag;
	t_bool				skip;
	t_bool				error;
};

struct					s_width
{
	int					width;
	int					pos;
};

struct					s_prec_data
{
	const char			*string;
	int					position;
	struct s_info		info;
	int					prec_value;
	int					start;
	char				*s;
};

struct					s_handler_info
{
	char				*str;
	struct s_info		info;
};

int						ft_printf(const char *format, ...);
struct s_info			flag_checker(const char *string, int position,
							struct s_info info, va_list args);
struct s_info			flag_handler(struct s_info info, va_list args);
int						arg_counter(const char *string);
t_bool					in_set(char c);
t_bool					in_flag_set(char c);
struct s_info			check_precision(const char *string, int position,
									struct s_info info, va_list args);
int						handle_width(struct s_info info, char *str, int i);
struct s_info			handle_negative(struct s_info info);
struct s_info			print_str(struct s_info info, char *str);
struct s_info			set_info_values(char *str, void *temp,
														struct s_info info);
struct s_info			set_second_info_values(struct s_info info,
													char *str, void *temp);
struct s_info			handle_extras(struct s_info info, void *temp);
void					handle_zeros(struct s_info info, char *str);
void					*set_temp(struct s_info info, va_list args);
struct s_info			handle_initial_info(struct s_info info);
char					*get_str(struct s_info info, void *temp);
char					*flag_c(char c);
char					*flag_s(char *str, struct s_info info);
char					*flag_p(unsigned long ptr, struct s_info info);
char					*flag_di(signed int value);
char					*flag_u(unsigned int value);
char					*flag_x(unsigned int value, t_bool uppercase);
char					*flag_procent();
struct s_width			flag_width(const char *str, int position,
											struct s_width info);
void					width_true(struct s_info info, char *str, int i);
void					width_zero_true(struct s_info info, char *str, int i);
void					width_dash_true(struct s_info info, char *str, int i);
t_bool					check_zero_flag(struct s_info info);
struct s_handler_info	handle_nulls(struct s_info info, char *str);
struct s_handler_info	handle_second_nulls(struct s_info info, char *str);

#endif
