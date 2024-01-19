# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcaptari <gabrielcaptari@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 13:44:09 by sgabsi            #+#    #+#              #
#    Updated: 2024/01/18 22:10:50 by gcaptari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################
# Sources
SRC_DIR		=	./
SRC			=	pipex.c \
				parse.c \
				utils.c

# Objects
OBJDIR		=	obj
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)
BOBJ			= $(SRC_BONUS:%.c=$(OBJDIR)/%.o)

# Includes
INC			=	./includes
# Output
NAME		=	pipex

# Compiler
CFLAGS		=	-Wall -Wextra -Werror -g3
COPTIMISE	=	-O2 -ffreestanding -nostdlib -fno-builtin
CC			=	cc
OPTIONS		=	-I $(INC)
LDFLAGS		=	-L./libs/compile  -lft -lftprintf

#################
##  TARGETS    ##
#################
#-nostartfiles -fPIC $(COPTIMISE)

all: pre libaries $(NAME)

pre:
	@echo "pipex compiling..."
	@find ./libs -name "*.h" -exec cp {} ./includes > /dev/null 2>&1 \;

libaries:
	echo "compiling libs..."
	@mkdir -p ./libs/compile
	@make all -sC ./libs/libft
	@make all -sC ./libs/ft_printf
	@find ./libs -name "*.a" -exec cp {} ./libs/compile > /dev/null 2>&1 \;
	@echo "libs compiled"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OPTIONS) $(OBJ) $(LDFLAGS) -o $(NAME) 
	@echo "pipex compiled"

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ -c $< 

clean:
	@make clean -sC ./libs/libft
	@make clean -sC ./libs/ft_printf
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@make fclean -sC ./libs/libft
	@make fclean -sC ./libs/ft_printf
	@/bin/rm -rf ./libs/compile/
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus