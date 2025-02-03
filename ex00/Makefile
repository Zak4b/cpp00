NAME = megaphone

FLAGS = -Wall -Wextra -Werror -g

SOURCES = \
        megaphone.cpp

OBJS = $(SOURCES:.cpp=.o)

$(NAME): $(OBJS)
	c++ $(FLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

$(OBJDIR)/%.o: srcs/%.c | $(OBJDIR)
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
