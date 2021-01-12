.PHONY: all clean fclean re bonus libft obj_directory

NAME = libftprintf.a
LIBFT_NAME = libft.a

CC = gcc

CFLAGS			= -Wall -Wextra -Werror
LIB_FLAGS		= -L $(LIBFT_DIR) -lft
INCLUDE_FLAGS 	= -I $(INCLUDES_DIR) -I $(LIBFT_DIR)

GREEN =	\033[32m
RED	  =	\033[31m
RESET =	\033[0m

INCLUDES_DIR = include
LIBFT_DIR 	 = libft
SRC_DIR		 = src
OBJ_DIR		 = obj

SOURCES =	ft_utils.c \
			ft_check.c \
			ft_printf.c \
			ft_print_int.c \
			ft_print_chars.c \
			ft_print_flags.c \
			ft_print_floats.c \
			ft_print_itoa_base.c \
			ft_print_increment.c \
			ft_is_type_chr.c \
			ft_is_type_num.c \
			ft_is_type_pos.c \
			ft_set_defaults.c \
			ft_get_arguments.c \
			ft_get_parameters.c \
			ft_modify_parameters.c
		
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))
HEADERS = $(INCLUDES_DIR)/*.h

all: libft obj_directory $(NAME)

obj_directory:
	@mkdir -p $(OBJ_DIR)

libft:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIBFT_DIR)/$(LIBFT_NAME)
	@$(CC) $(CFLAGS) -c $< $(LIB_FLAGS) $(INCLUDE_FLAGS) -o $@

$(NAME): $(OBJECTS) $(HEADERS)
	@cp $(LIBFT_DIR)/$(LIBFT_NAME) $(NAME)
	@ar rcs $@ $(OBJECTS)
	@echo "[o] $(GREEN)$(NAME)$(RESET) created."

see:
	ar -t $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory 
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory
	@rm -rf $(NAME)
	@echo "[x] $(RED)$(NAME)$(RESET) has been deleted."

re: fclean all