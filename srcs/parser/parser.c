/*
** parser.c for parser in /home/walrav_j/rendu/SBMLparser/srcs/parser
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Tue Jun 14 15:02:39 2016 Jean Walrave
** Last update Wed Jun 15 13:04:58 2016 Jean Walrave
*/

#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "SBMLparser.h"

static int	parse(t_SBML **stack, char *str)
{
  t_SBML_attribute	*attrs;
  int			i;
  char			*str_u[4];
  char			side_sep[2];

  i = -1;
  str_u[0] = strdup(str);
  while ((str_u[1] = strtok((!++i) ? str : NULL, SBML_BASIC_PATTERN)))
    {
      side_sep[0] = str_u[0][str_u[1] - str - 1];
      side_sep[1] = str_u[0][str_u[1] - str + strlen(str_u[1])];
      if (IS_CHAR(side_sep[0], '<') && IS_CHAR(side_sep[1], '>'))
	add_elem_to_sbml_stack(stack, str_u[1], NULL, tag);
      else if (IS_CHAR(side_sep[0], '<') && IS_CHAR(side_sep[1], ' '))
	{
	  if ((attrs = init_sbml_attr_stack()) == NULL)
	    return (1);
	  while ((str_u[2] = strtok(NULL, SBML_ATTR_PATTERN)) &&
		 (str_u[3] = strtok(NULL, SBML_ATTR_VALUE_PATTERN)))
	    add_elem_to_sbml_attr_stack(&attrs, str_u[2], str_u[3]);
	  add_elem_to_sbml_stack(stack, str_u[1], &attrs, element);
	}
    }
  free(str_u[0]);
  return (0);
}

t_SBML		**get_parsed(const int fd)
{
  static t_SBML	*sbml_stack;
  char		*str;

  if ((sbml_stack = init_sbml_stack()) == NULL || fd < 0)
    return (NULL);
  while ((str = get_next_line(fd)))
    {
      parse(&sbml_stack, str);
      free(str);
    }
  return (&sbml_stack);
}
