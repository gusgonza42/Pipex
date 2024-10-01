# <-- Program Name --> #
NAME = pipex

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = # -Wall -Werror -Wextra

# <-- Header Flags --> #
CPPFLAGS = -I ./libft -I ./ft_printf

# <-- 	LD Linkers Flags Library--> #
LDLIBS = -lft -lftprintf

# <-- LD Route Flags --> #
LDFLAGS = -L ./libft -L ./ft_printf

# <-- Remove Command -->#
RM = rm -f

# <-- HEADER --> #
HEADER = pipex.h

# <-- MAKEFILE --> #
MAKEFILE = Makefile

# <-- Files --> #
SRC_FILES = ft_main.c ft_childs.c


# <-- Objects --> #
OBJS = $(SRC_FILES:.c=.o)

# <-- Main Target --> #
all: $(NAME)

# <--Program Creation--> #
$(NAME): $(OBJS)
	@make -sC libft
	@make -sC ft_printf
	@echo "✅ 🚀 0bjects created successfully by $(NAME)!"
	@$(CC) -o $@ $(OBJS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "✅ 🛰  $(NAME) created successfully!"

# <-- Objects Creation --> #
%.o: %.c $(HEADER) $(MAKEFILE)
	@echo "🧩 ☁️  Compiling... $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "🔨 🦔 $@ created!"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJS) 
	@make clean -sC libft
	@make clean -sC ft_printf
	@echo "🗑️  🚀 Objects destroyed successfully by $(NAME)!"

# <-- Clean Execution + libft.a Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC libft
	@make fclean -sC ft_printf
	@echo "🗑️  🛰  $(NAME) destroyed successfully by $(NAME)!"

# <-- Re Execution -->
re:
	@make -s fclean
	@make -s all

# <-- Targets Declaration --> #
.PHONY : all clean fclean re
