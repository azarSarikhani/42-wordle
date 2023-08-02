# Meta

NAME := wordle

SRCDIR := ./src
OBJDIR := ./obj
INCDIR := ./includes

SRC :=\
	main.cpp \

OBJ := $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))
DEP := $(OBJ:%.o=%.d)

ARCH := $(shell uname)

# Compilation and linking

CC := cc
CFLAGS := -Wall -Werror -Wextra -I$(INCDIR)

# Rules

all: $(NAME)

debug: CFLAGS+= -g -fsanitize=address,undefined
debug: LDFLAGS+= -g -fsanitize=address,undefined
debug: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

# Include dependency info
-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CC) $(CFLAGS) -MMD -c $< -o $@ 

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
