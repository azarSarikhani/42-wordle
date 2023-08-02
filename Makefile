# Meta

NAME := wordle

SRCDIR := ./src
OBJDIR := ./obj
INCDIR := ./includes

SRC :=\
	main.cpp \
	word.cpp \
	game.cpp\
	Guess_class.cpp

OBJ := $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))
DEP := $(OBJ:%.o=%.d)

ARCH := $(shell uname)

# Compilation and linking

CPP := c++
CPPFLAGS := -Wall -Werror -Wextra -std=c++17 -I$(INCDIR)

# Rules

all: $(NAME)

debug: CPPFLAGS+= -g -fsanitize=address,undefined
debug: LDFLAGS+= -g -fsanitize=address,undefined
debug: $(NAME)

$(NAME): $(OBJ)
	$(CPP) -o $(NAME) $(OBJ) $(LDFLAGS)

# Include dependency info
-include $(DEP)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@$(shell [ ! -d $(@D) ] && mkdir -p $(@D))
	$(CPP) $(CPPFLAGS) -MMD -c $< -o $@ 

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
