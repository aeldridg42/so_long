NAME		=	so_long

SRCS		= 	base/main.c \
				sources/imageimport/images.c \
				sources/exiting.c \
				sources/parser.c \
				sources/mapdraw.c \
				sources/measuring.c \
				sources/movedraw.c \
				sources/movehook.c \
				sources/get_next_line/get_next_line.c \
				sources/get_next_line/get_next_line_utils.c \

BONUSSRCS	=	base/main_bonus.c \
				bonus/imageimport/images1_bonus.c \
				bonus/imageimport/images2_bonus.c \
				bonus/animations/animatecoins_bonus.c \
				bonus/animations/animateplayer1_bonus.c \
				bonus/animations/animateplayer2_bonus.c \
				bonus/animations/animating_bonus.c \
				bonus/animations/animatingenemy_bonus.c \
				bonus/animations/animatingexit_bonus.c \
				bonus/exiting_bonus.c \
				bonus/parser_bonus.c \
				bonus/mapdraw_bonus.c \
				bonus/measuring_bonus.c \
				bonus/movedraw_bonus.c \
				bonus/movehook_bonus.c \
				bonus/libft/ft_itoa.c \
				sources/get_next_line/get_next_line.c \
				sources/get_next_line/get_next_line_utils.c \

OBJS		= 	${SRCS:.c=.o}

BONUSOBJS	= 	${BONUSSRCS:.c=.o}

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

MLX 		= 	-lmlx -framework OpenGL -framework AppKit

INCLUDES	= 	includes/so_long.h

RM			= 	rm -rf

NORMIN		= 	norminette

all: 			$(NAME)

$(NAME): 		$(OBJS)
				$(MAKE) -C ./mlx/minilibx_mms_20200219
				$(MAKE) -C ./mlx/minilibx_opengl_20191021
				cp mlx/minilibx_mms_20200219/libmlx.dylib .
				cp mlx/minilibx_opengl_20191021/libmlx.a .
				@${CC} ${OBJS} ${CFLAGS} ${MLX} libmlx.dylib libmlx.a -o ${NAME}

bonus:			$(BONUSOBJS)
				$(MAKE) -C ./mlx/minilibx_mms_20200219
				$(MAKE) -C ./mlx/minilibx_opengl_20191021
				cp mlx/minilibx_mms_20200219/libmlx.dylib .
				cp mlx/minilibx_opengl_20191021/libmlx.a .
				@${CC} $(BONUSOBJS) ${CFLAGS} ${MLX} -o ${NAME}

%.o : %.c 		${INCLUDES}
				${CC} ${CFLAGS} -c $< -I ${INCLUDES} -o ${<:.c=.o}

clean:
				$(MAKE) clean -C ./mlx/minilibx_mms_20200219
				$(MAKE) clean -C ./mlx/minilibx_opengl_20191021	
				${RM} ${OBJS} $(BONUSOBJS)

fclean:			clean
				${RM} libmlx.dylib
				${RM} libmlx.a
				${RM} ${NAME}

re:				fclean all

norm:		
			$(NORMIN) bonus/
			$(NORMIN) sources/
			$(NORMIN) includes/
			$(NORMIN) base/

.PHONY:			all clean fclean re bonus norm
