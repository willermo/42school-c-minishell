# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/12/07 00:55:45 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= minishell
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/ -I./libft/includes/
RM			= rm -f
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
## Base sources section ##
SRC_FILES   = minishell utils env_mgmt path_mgmt path_mgmt_utils expander \
			  parser parser_utils executor executor_utils executor_utils2 \
			  executor_utils3  invoker
SRC_DIR		= ./src/
OBJ_DIR		= ./obj/
## Built-ins sources section ##
BUILTIN_FILES = assign echo cd env exit export pwd unset builtin_utils
BUILTIN_DIR	= ./src/builtins/
BUILTIN_OBJ_DIR= ./obj/builtins/
SRCS		= $(addsuffix .c, $(addprefix $(SRC_DIR), $(SRC_FILES)))           \
$(addsuffix .c, $(addprefix $(BUILTIN_DIR), $(BUILTIN_FILES)))
OBJS		= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(SRC_FILES)))           \
$(addsuffix .o, $(addprefix $(BUILTIN_OBJ_DIR), $(BUILTIN_FILES)))
LIBRARIES	= -L./libft -lft -lpthread -lreadline
DEBUG		= -g

#############
## Targets ##
#############
usage:
	@echo "Usage: make [usage | all | minishell | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Minishell build targets --"
	@echo "\tall: compiles  minishell"
	@echo "\tminishell: compiles minishell"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and program"
	@echo "\tre: fclean and all"

all: $(NAME)

$(NAME):  $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(DEBUG)

#$(OBJS): $(SRCS)

$(LIBFT):
	(cd $(LIBFT_DIR) && make)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(LIBRARIES) $(DEBUG)

$(BUILTIN_OBJ_DIR)%.o: $(BUILTIN_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES) $(LIBRARIES) $(DEBUG)

clean:
	(cd $(LIBFT_DIR) && make clean)
	$(RM) $(OBJS)

fclean: clean
	(cd $(LIBFT_DIR) && make fclean)
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re $(NAME)
