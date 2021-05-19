SOURCES = ft_printf.c handler.c cases.c parser.c \
		  ft_bzero.c ft_calloc.c ft_isdigit.c \
		  ft_memset.c ft_strchr.c ft_strlcat.c \
		  ft_strlen.c ft_revers.c ft_toupper.c \

FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

OBJECT = $(SOURCES:%.c=%.o)
GREEN ='\033[0;32m'
RED ='\033[0;31m'
all: $(NAME)
$(NAME) : $(OBJECT) ft_printf.h
	@echo "$(GREEN)Compiling lib ---->>>> $(OBJECT) OK!"
	@ar -rcs $(NAME) *.o $(OBJECT)
	@echo "$(GREEN)libftprintf.a greated!"
%.o : %.c 
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(GREEN)Compiling code ---->>>> $< OK"

clean:
	@echo "$(RED)Delete objects !"
	@rm -f -v $(OBJECT) 

test:
	@gcc $(FLAGS) $(SOURCES) test.c
	@echo "$(GREEN)Compiling code ---->>>> $(SOURCES) + test.c OK"
del:
	@echo "$(RED)Delete objects!"
	@rm -f -v $(OBJECT)  
fclean:
	@echo "$(RED)Delete objects and libs!"
	@rm -f -v $(NAME) $(OBJECT)
re: fclean all

.PHONY: all clean fclean re del test