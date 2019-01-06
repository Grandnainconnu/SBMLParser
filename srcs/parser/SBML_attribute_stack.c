/*
** SBML_attributes_stack.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs/parser
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Tue Jun 14 17:19:12 2016 Jean Walrave
** Last update Wed Jun 15 20:01:47 2016 Jean Walrave
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SBMLparser.h"

t_SBML_attribute	*init_sbml_attr_stack(void)
{
  t_SBML_attribute	*stack;

  if ((stack = malloc(sizeof(*stack))) != NULL)
    {
      stack->name = NULL;
      stack->value = NULL;
      stack->prev = stack;
      stack->next = stack;
    }
  else
    stack = NULL;
  return (stack);
}

int			add_elem_to_sbml_attr_stack(t_SBML_attribute **stack,
						    char *name, void *value)
{
  t_SBML_attribute	*new_stack;

  if ((new_stack = malloc(sizeof(*new_stack))) != NULL)
    {
      new_stack->name = strdup(name);
      new_stack->value = strdup(value);
      new_stack->prev = (*stack)->prev;
      new_stack->next = (*stack);
      ((*stack)->prev)->next = new_stack;
      (*stack)->prev = new_stack;
      return (0);
    }
  return (1);
}

void	delete_sbml_attr_stack_elem(t_SBML_attribute **elem)
{
  (*elem)->prev->next = (*elem)->next;
  (*elem)->next->prev = (*elem)->prev;
  free((*elem)->name);
  free((*elem)->value);
  free((*elem));
}

void			delete_sbml_attr_stack(t_SBML_attribute **stack)
{
  t_SBML_attribute	*curr;
  t_SBML_attribute	*next;

  if ((*stack) == NULL)
    return ;
  curr = (*stack)->next;
  while (curr != (*stack))
    {
      next = curr->next;
      free(curr->name);
      free(curr->value);
      free(curr);
      curr = next;
    }
  free((*stack)->name);
  free((*stack)->value);
  free((*stack));
}
