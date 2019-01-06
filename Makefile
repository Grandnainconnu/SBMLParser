##
## Makefile for Makefile in /home/walrav_j/rendu/SBMLparser
##
## Made by Jean Walrave
## Login   <walrav_j@epitech.net>
##
## Started on  Mon Jun 13 10:09:13 2016 Jean Walrave
## Last update Wed Jun 15 20:08:58 2016 Jean Walrave
##

SRCS	= srcs/get_next_line/get_next_line.c \
	  srcs/parser/parser.c \
	  srcs/parser/SBML_stack.c \
	  srcs/parser/SBML_attribute_stack.c \
	  srcs/gestionnary/compartment.c \
	  srcs/gestionnary/species.c \
	  srcs/gestionnary/options.c \
	  srcs/utils/swaper.c \
	  srcs/displayer.c \
	  srcs/SBMLparser.c

OBJS	= $(SRCS:.c=.o)

NAME	= SBMLparser

CFLAGS	+= -W -Wall -Werror -I include

CC	= gcc

RM	= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
