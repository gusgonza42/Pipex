# <-- Library's Name --> #
NAME = libftprintf.a

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = -Wall -Werror -Wextra -I ../../includes

# <-- Remove Command -->#
RM = rm -f

# <-- HEADER --> #
HEADER = ft_printf.h

# <-- MAKEFILE --> #
MAKEFILE = Makefile

# <-- AR --> #
AR = ar -rcs

# <-- Files --> #
SRC_FILES = ft_chars.c ft_digits.c ft_hex.c ft_printf.c

# <-- Objects --> #
OBJS = $(SRC_FILES:.c=.o)

# <-- Main Target --> #
all: $(NAME)

# <-- Objects Creation --> #
%.o: %.c $(HEADER) $(MAKEFILE)
	@echo "🧩 ☁️  Compiling... $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔨 🦔 $@ created!"

# <--Library Creation--> #
$(NAME): $(OBJS)
	@echo "✅ 🚀 0bjects created successfully!"
	@$(AR) $@ $(OBJS)
	@echo "✅ 🛰  $(NAME) created successfully!"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJS)
	@echo "🗑️  🚀 Objects destroyed successfully!"

# <-- Clean Execution + libft.a Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@echo "🗑️  🛰  $(NAME) destroyed successfully!"

# <-- Fclean Execution -->
re: fclean all

# <-- Targets Declaration --> #
.PHONY : all clean fclean re
