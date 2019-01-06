/*
** get_next_line.c for get_next_line in /home/walrav_j/rendu/SBMLparser/srcs/get_next_line
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Mon Jun 13 12:45:07 2016 Jean Walrave
** Last update Mon Jun 13 12:51:27 2016 Jean Walrave
*/

#include <unistd.h>
#include <stdlib.h>
#include "SBMLparser.h"

static int	add_to_stack(t_gnl_stack **stack, char c)
{
  t_gnl_stack	*new;
  t_gnl_stack	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (-1);
  new->c = c;
  new->next = NULL;
  if (*stack)
    {
      tmp = *stack;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
    }
  else
    *stack = new;
  return (0);
}

static int	is_line(t_gnl_stack **stack)
{
  t_gnl_stack	*tmp;

  tmp = *stack;
  while (tmp)
    {
      if (tmp->c == '\0' || tmp->c == '\n')
	return (0);
      tmp = tmp->next;
    }
  return (-1);
}

static int		get_line_size(t_gnl_stack **stack)
{
  int			i;
  t_gnl_stack		*tmp;

  i = 0;
  tmp = *stack;
  while (tmp)
    {
      if (tmp->c == '\0' || tmp->c == '\n')
	return (i);
      tmp = tmp->next;
      ++i;
    }
  return (-1);
}

static char		*stack2str(t_gnl_stack **stack)
{
  int			i;
  int			j;
  char			*str;
  t_gnl_stack		*tmp;

  if (*stack == NULL || (str = malloc((j = get_line_size(stack)) + 1)) == NULL)
    return (NULL);
  i = 0;
  while (*stack && i < j)
    {
      tmp = *stack;
      str[i] = (*stack)->c;
      (*stack) = (*stack)->next;
      free(tmp);
      ++i;
    }
  str[i] = '\0';
  if (*stack && (*stack)->c != '\0')
    {
      tmp = *stack;
      *stack = (*stack)->next;
      free(tmp);
    }
  return (str);
}

char			*get_next_line(const int fd)
{
  static t_gnl_stack	*stack = NULL;
  char			buffer[READ_SIZE];
  int			readed;
  int			i;

  if (!is_line(&stack))
    return (stack2str(&stack));
  else if ((readed = read(fd, buffer, READ_SIZE)) <= 0)
    return (NULL);
  else
    {
      i = -1;
      while (++i < readed)
	if (add_to_stack(&stack, buffer[i]) == -1)
	  return (NULL);
      if (!is_line(&stack))
	return (stack2str(&stack));
    }
  return (get_next_line(fd));
}
