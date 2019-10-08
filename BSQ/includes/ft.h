/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: oslussot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/21 17:28:12 by oslussot     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 19:43:44 by coscialp    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>

typedef struct	s_setup
{
	char		empty;
	char		obs;
	char		full;
	int			length;
	int			height;

}				t_setup;

typedef struct	s_save
{
	int line;
	int col;
	int val;
}				t_save;

struct s_save	ft_init(t_save save, t_setup setup, char **board);
int				ft_map_zero(char **map);
void			pre_main_arg(char **av, int i);
void			pre_main_input(void);
void			bsq(char **map);
char			*ft_strcat(char *dest, char *src, int len, int oct);
int				ft_str_only_char(char **str, t_setup setup);
char			*ft_realloc(char *old, int len, char *src, int oct);
struct s_save	ft_fbplus(t_save save, t_setup setup, int **tab, int line);
char			*open_standard(void);
void			ft_print_error(void);
int				ft_str_is_ok(char **str, t_setup setup);
struct s_save	ft_save_pos(t_save save, int line, int col, int val);
void			display_char_tab(char **board, t_save save, t_setup setup);
int				str_is_ok(char **str);
int				ft_strlen(char *str);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				*ft_range(int min, int max);
char			*ft_strdup(char *src);
int				*ft_str_translate(int *dest, char *src);
char			**ft_split(char *str, char *charset);
char			*ft_strcpy(char *dest, char *src);
char			*open_map(char *str);
int				**create_map(char **map, t_setup setup);
void			init_map(int **map, t_setup setup);
t_setup			create_setup(char **map);
int				check_map(char **map);
int				ft_checker(int **tab, int line, int col);
void			ft_display_int_tab(int **board, t_setup setup);
struct s_save	ft_board(t_save save, t_setup setup, char **board, int **tab);
int				char_in_string(char c, char *str);
char			*ft_copy(char *dest, char *src, char *charset);
int				ft_size(char *str, char *charset);
void			ft_cpy_tab(char **split, char *str, char *charset);

#endif
