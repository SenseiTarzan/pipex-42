# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcaptari <gcaptari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:44:09 by sgabsi            #+#    #+#              #
#    Updated: 2024/06/26 13:07:01 by gcaptari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################
# Sources
LIBDIR		=	./lib
SRC_DIR		=	./src
SRC			=	pipex.c \
				parse.c \
				utils.c	\
				exec.c	\
				proto_array.c \
				command.c	\
				testing.c

# Objects
OBJDIR		=	obj
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)
BOBJ			= $(SRC_BONUS:%.c=$(OBJDIR)/%.o)

LIBFT_DIR 	=	$(LIBDIR)/libft
LIBFT 		=	$(LIBFT_DIR)/libft.a

# Includes
INC			=	./includes
# Output
NAME		=	pipex

# Compiler
CFLAGS		=	-Wall -Wextra -Werror -g3
COPTIMISE	=	-O2 -ffreestanding -nostdlib -fno-builtin
CC			=	clang
OPTIONS		=	-I $(INC) -I $(LIBFT_DIR)/includes
LDFLAGS		=	-L $(LIBFT_DIR) -lft

#################
##  TARGETS    ##
#################
#-nostartfiles -fPIC $(COPTIMISE)

all: pre $(LIBFT) $(NAME)

pre:
	@echo "pipex compiling..."

libaries:
	@mkdir -p ./libs/compile
	make -C ./libs/libft
	make -C ./libs/ft_printf
	@find ./libs -name "*.a" -exec cp {} ./libs/compile > /dev/null 2>&1 \;

$(NAME): $(OBJ)
	@echo $^
	$(CC) $(CFLAGS) $(OPTIONS) $^ $(LDFLAGS) -o $@
	@echo "pipex compiled"

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ -c $<

$(LIBFT):
	@make -sC $(LIBFT_DIR)

clean:
	@make -sC $(LIBFT_DIR) fclean
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@make -sC $(LIBFT_DIR) fclean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
