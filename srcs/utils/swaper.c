/*
** swaper.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs/utils
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 20:01:07 2016 Jean Walrave
** Last update Wed Jun 15 20:22:01 2016 Jean Walrave
*/

#include <string.h>
#include "SBMLparser.h"

static void		swap_sbml_stack(t_SBML *curr, t_SBML *next)
{
  if (curr->prev)
    (curr->prev)->next = next;
  if (next->next)
    (next->next)->prev = curr;
  curr->next  = next->next;
  next->prev = curr->prev;
  next->next = curr;
  curr->prev = next;
}

static void		swap_sbml_attr_stack(t_SBML_attribute *curr,
					     t_SBML_attribute *next)
{
  if (curr->prev)
    (curr->prev)->next = next;
  if (next->next)
    (next->next)->prev = curr;
  curr->next  = next->next;
  next->prev = curr->prev;
  next->next = curr;
  curr->prev = next;
}

void			sbml_attr_sort_alphabeticaly(t_SBML_attribute **stack,
						     int isValue)
{
  t_SBML_attribute	*tmp[2];
  int			h_m;

  h_m = 1;
  while (h_m > 0)
    {
      tmp[0] = (*stack)->next;
      while (tmp[0] != (*stack))
        {
          if (tmp[0]->next && (tmp[1] = tmp[0]->next) != (*stack) &&
              strcasecmp(isValue ? tmp[0]->value : tmp[0]->name,
			 isValue ? tmp[1]->value : tmp[1]->name) > 0 && ++h_m)
	    swap_sbml_attr_stack(tmp[0], tmp[1]);
          tmp[0] = tmp[0]->next;
        }
      h_m = (h_m == 1) ? 0 : 1;
    }
}

void		sbml_sort_alphabeticaly(t_SBML **stack)
{
  t_SBML	*tmp[2];
  int		h_m;

  h_m = 1;
  while (h_m > 0)
    {
      tmp[0] = (*stack)->next;
      while (tmp[0] != (*stack))
        {
          if (tmp[0]->next && (tmp[1] = tmp[0]->next) != (*stack) &&
              strcasecmp(tmp[0]->element, tmp[1]->element) > 0 && ++h_m)
	    swap_sbml_stack(tmp[0], tmp[1]);
          tmp[0] = tmp[0]->next;
        }
      h_m = (h_m == 1) ? 0 : 1;
    }
}

void		sbml_sort_by_attr_alphabeticaly(t_SBML **stack)
{
  t_SBML	*tmp[2];
  int		h_m;

  h_m = 1;
  while (h_m > 0)
    {
      tmp[0] = (*stack)->next;
      while (tmp[0] != (*stack))
        {
          if (tmp[0]->next && (tmp[1] = tmp[0]->next) != (*stack) &&
	      tmp[0]->attributes->value && tmp[1]->attributes->value &&
              strcasecmp(tmp[0]->attributes->value,
			 tmp[1]->attributes->value) > 0 && ++h_m)
	    swap_sbml_stack(tmp[0], tmp[1]);
          tmp[0] = tmp[0]->next;
        }
      h_m = (h_m == 1) ? 0 : 1;
    }
}
