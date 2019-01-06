/*
** requirement.c for requirement in /home/walrav_j/rendu/SBMLparser
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Mon Jun 13 10:09:07 2016 Jean Walrave
** Last update Tue Jun 14 14:56:12 2016 Jean Walrave
*/

#include <stdlib.h>
#include "include/requirement.h"

static int	my_is_alphanumeric(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9'))
    return (0);
  return (1);
}

static char	*my_strncpy(char *dest, const char *str, int size, int is_allocated)
{
  int		i;

  i = 0;
  if (str == NULL || (is_allocated && (dest = malloc(size + 1)) == NULL))
    return (NULL);
  while (str[i] && i < size)
    {
      dest[i] = str[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}

static int		add_to_stack(t_parser_stack **stack, const char *str)
{
  t_parser_stack	*new_elem;
  t_parser_stack	*tmp;

  if ((new_elem = malloc(sizeof(*new_elem))) == NULL)
    return (1);
  new_elem->str = str;
  new_elem->next = NULL;
  if (*stack)
    {
      tmp = *stack;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new_elem;
    }
  else
    *stack = new_elem;
  return (0);
}

static char		**stack_to_tab(t_parser_stack **stack)
{
  int			i;
  char			**tab;
  t_parser_stack	*tmp;

  if (*stack == NULL)
    return (NULL);
  tmp = *stack;
  i = 0;
  while (tmp)
    {
      tmp = tmp->next;
      i += 1;
    }
  if ((tab = malloc(sizeof(tab) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  while ((*stack))
    {
      tmp = *stack;
      tab[++i] = (char *)(*stack)->str;
      *stack = (*stack)->next;
      free(tmp);
    }
  tab[i + 1] = 0;
  return (tab);
}

char			**my_strtowordtab_synthesis(char *str)
{
  int			i;
  int			size;
  int			is_in_word;
  static t_parser_stack	*stack = NULL;

  i = -1;
  is_in_word = 0;
  while (str && str[++i])
    {
      if (my_is_alphanumeric(str[i]))
	is_in_word = 0;
      else if (!is_in_word)
	{
	  size = 0;
	  while (str + i && str[i + size] && !my_is_alphanumeric(str[i + size]))
	    ++size;
	  if (add_to_stack(&stack, my_strncpy(NULL, str + i, size, 1)) == 1)
	    return (NULL);
	  i += size - 1;
	}
    }
  return (stack_to_tab(&stack));
}
