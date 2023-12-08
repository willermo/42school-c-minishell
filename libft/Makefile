# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:53:08 by doriani           #+#    #+#              #
#    Updated: 2023/11/02 19:51:39 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./includes/
RM			= rm -f
## Base sources section ##
BASE_FILES = 
BASE_SRC_DIR = ./src/
BASE_OBJ_DIR= ./obj/
## Chars sources section ##
CHARS_FILES = ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_islower\
ft_isupper ft_tolower ft_toupper
CHARS_SRC_DIR = ./src/chars/
CHARS_OBJ_DIR= ./obj/chars/
## Colors sources section ##
COLORS_FILES= colors_hsv_1 colors_rgb_1 colors_rgb_2 colors_rgb_3              \
colors_hsv_to_rgb_1 colors_hsv_to_rgb_2
COLORS_DIR	= ./src/colors/
COLORS_OBJ_DIR= ./obj/colors/
## Strings sources section ##
STRINGS_FILES = ft_strlen ft_strcmp ft_strncmp ft_strcpy ft_strncpy ft_strlcpy \
ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr      \
ft_strrev  ft_strtrim ft_strdel ft_strclr ft_substr ft_strnew ft_strdup        \
ft_strjoin ft_striteri ft_strmapi
STRINGS_SRC_DIR = ./src/strings/
STRINGS_OBJ_DIR= ./obj/strings/
## Memory sources section ##
MEMORY_FILES = ft_calloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel    \
ft_bzero ft_memmove ft_memset
MEMORY_SRC_DIR = ./src/memory/
MEMORY_OBJ_DIR= ./obj/memory/
## Writes sources section ##
WRITES_FILES = ft_putchar_fd ft_putnbr_fd ft_putstr_fd ft_putendl_fd ft_putchar\
ft_putnbr ft_putstr ft_putendl ft_printf ft_printf_utils write_letters         \
write_numbers write_pointers write_numbers_utils
WRITES_SRC_DIR = ./src/writes/
WRITES_OBJ_DIR= ./obj/writes/
## Utils sources section ##
UTILS_FILES = ft_atoi ft_atol ft_atod ft_itoa ft_itoa_16 ft_itoa_8 ft_itoa_base\
ft_uitoa ft_uitoa_base ft_swapc ft_swapi ft_split ft_quoted_split get_next_line\
ft_split_utils
UTILS_SRC_DIR = ./src/utils/
UTILS_OBJ_DIR= ./obj/utils/
## Math sources section ##
MATH_FILES = ft_math_1
MATH_SRC_DIR = ./src/math/
MATH_OBJ_DIR= ./obj/math/
## Data structures sources section ##
DATA_STRUCTS_FILES =
DATA_STRUCTS_SRC_DIR = ./src/data_structures/
DATA_STRUCTS_OBJ_DIR= ./obj/data_structures/
## Stacks sources section ##
STACKS_FILES = stack stack_utils
STACKS_SRC_DIR = ./src/stacks/
STACKS_OBJ_DIR= ./obj/stacks/
## Linked lists sources section ##
LISTS_FILES = sl_list sl_utils cl_list cl_insertions cl_deletions cl_searches  \
cl_additions cl_removals cl_data_management1 cl_data_management2 cl_utils1     \
cl_utils2 cl_utils3    
LISTS_SRC_DIR = ./src/lists/
LISTS_OBJ_DIR= ./obj/lists/
## Trees sources section ##
TREES_FILES =
TREES_SRC_DIR = ./src/trees/
TREES_OBJ_DIR= ./obj/trees/
## Graphs sources section ##
GRAPHS_FILES =
GRAPHS_SRC_DIR = ./src/graphs/
GRAPHS_OBJ_DIR= ./obj/graphs/

## SOURCES ##
SRCS		= $(addsuffix .c, $(addprefix $(BASE_SRC_DIR), $(BASE_FILES)))     \
$(addsuffix .c, $(addprefix $(CHARS_SRC_DIR), $(CHARS_FILES)))                 \
$(addsuffix .c, $(addprefix $(COLORS_DIR), $(COLORS_FILES)))                   \
$(addsuffix .c, $(addprefix $(STRINGS_SRC_DIR), $(STRINGS_FILES)))             \
$(addsuffix .c, $(addprefix $(MEMORY_SRC_DIR), $(MEMORY_FILES)))               \
$(addsuffix .c, $(addprefix $(WRITES_SRC_DIR), $(WRITES_FILES)))               \
$(addsuffix .c, $(addprefix $(UTILS_SRC_DIR), $(UTILS_FILES)))                 \
$(addsuffix .c, $(addprefix $(MATH_SRC_DIR), $(MATH_FILES)))                   \
$(addsuffix .c, $(addprefix $(DATA_STRUCTS_SRC_DIR), $(DATA_STRUCTS_FILES)))   \
$(addsuffix .c, $(addprefix $(STACKS_SRC_DIR), $(STACKS_FILES)))               \
$(addsuffix .c, $(addprefix $(LISTS_SRC_DIR), $(LISTS_FILES)))                 \
$(addsuffix .c, $(addprefix $(TREES_SRC_DIR), $(TREES_FILES)))                 \
$(addsuffix .c, $(addprefix $(GRAPHS_SRC_DIR), $(GRAPHS_FILES)))
## OBJECTS ##
OBJS		= $(addsuffix .o, $(addprefix $(BASE_OBJ_DIR), $(BASE_FILES)))     \
$(addsuffix .o, $(addprefix $(CHARS_OBJ_DIR), $(CHARS_FILES)))                 \
$(addsuffix .o, $(addprefix $(COLORS_OBJ_DIR), $(COLORS_FILES)))               \
$(addsuffix .o, $(addprefix $(STRINGS_OBJ_DIR), $(STRINGS_FILES)))             \
$(addsuffix .o, $(addprefix $(MEMORY_OBJ_DIR), $(MEMORY_FILES)))               \
$(addsuffix .o, $(addprefix $(WRITES_OBJ_DIR), $(WRITES_FILES)))               \
$(addsuffix .o, $(addprefix $(UTILS_OBJ_DIR), $(UTILS_FILES)))                 \
$(addsuffix .o, $(addprefix $(MATH_OBJ_DIR), $(MATH_FILES)))                   \
$(addsuffix .o, $(addprefix $(DATA_STRUCTS_OBJ_DIR), $(DATA_STRUCTS_FILES)))   \
$(addsuffix .o, $(addprefix $(STACKS_OBJ_DIR), $(STACKS_FILES)))               \
$(addsuffix .o, $(addprefix $(LISTS_OBJ_DIR), $(LISTS_FILES)))                 \
$(addsuffix .o, $(addprefix $(TREES_OBJ_DIR), $(TREES_FILES)))                 \
$(addsuffix .o, $(addprefix $(GRAPHS_OBJ_DIR), $(GRAPHS_FILES)))

#############
## Targets ##
#############
all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)

$(BASE_OBJ_DIR)%o: $(BASE_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(CHARS_OBJ_DIR)%o: $(CHARS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(COLORS_OBJ_DIR)%o: $(COLORS_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(STRINGS_OBJ_DIR)%o: $(STRINGS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MEMORY_OBJ_DIR)%o: $(MEMORY_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(WRITES_OBJ_DIR)%o: $(WRITES_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(UTILS_OBJ_DIR)%o: $(UTILS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(MATH_OBJ_DIR)%o: $(MATH_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(DATA_STRUCTS_OBJ_DIR)%o: $(DATA_STRUCTS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(STACKS_OBJ_DIR)%o: $(STACKS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LISTS_OBJ_DIR)%o: $(LISTS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(TREES_OBJ_DIR)%o: $(TREES_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(GRAPHS_OBJ_DIR)%o: $(GRAPHS_SRC_DIR)%c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

usage:
	@echo "Usage: make [usage | all | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Library build targets --"
	@echo "\tall: compile the library"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and library"
	@echo "\tre: fclean and all"
	