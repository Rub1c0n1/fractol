NAME	=	fractol

SRCS =	keys_control/keys.c \
	render_and_loops/render_and_loops.c \
	libft/ft_strncmp.c \
	libft/ft_atoi.c \
	fractals/julia.c \
	fractals/mandelbrot.c \
	main.c \

HEADER	=	fractol.h

OBJS	=	$(patsubst %.c, %.o, $(SRCS))
CC	=		cc
CFLAGS	=	-Wall -Wextra -Werror

MLX_FLAGS = -I libmlx/ -L libmlx/ -lmlx -framework OpenGL -framework AppKit

.PHONY	:	all clean fclean re

all	:	$(NAME)

${NAME}:	${OBJS}
	@ $(CC) $(MLX_FLAGS) $(CFLAGS) -o $@ $^

%.o	:	%.c $(HEADER)
	@ $(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)

fclean	:	clean
	@$(RM) $(NAME)

re	:	fclean all