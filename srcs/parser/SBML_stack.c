/*
** SBML_stack.c for SBML_stack in /home/walrav_j/rendu/SBMLparser/srcs/parser
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Tue Jun 14 15:19:43 2016 Jean Walrave
** Last update Wed Jun 15 20:02:38 2016 Jean Walrave
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SBMLparser.h"

t_SBML		*init_sbml_stack(void)
{
  t_SBML	*stack;

  if ((stack = malloc(sizeof(*stack))) != NULL)
    {
      stack->element = NULL;
      stack->attributes = NULL;
      stack->type = none;
      stack->prev = stack;
      stack->next = stack;
    }
  else
    stack = NULL;
  return (stack);
}

int		add_elem_to_sbml_stack(t_SBML **stack, char *element,
				       t_SBML_attribute **attributes,
				       t_SBML_type type)
{
  t_SBML	*new_stack;

  if ((new_stack = malloc(sizeof(*new_stack))) != NULL)
    {
      new_stack->element = strdup(element);
      new_stack->attributes = attributes ? (*attributes) : NULL;
      new_stack->type = type;
      new_stack->prev = (*stack)->prev;
      new_stack->next = (*stack);
      ((*stack)->prev)->next = new_stack;
      (*stack)->prev = new_stack;
      return (0);
    }
  return (1);
}

void	delete_sbml_stack_elem(t_SBML **elem)
{
  (*elem)->prev->next = (*elem)->next;
  (*elem)->next->prev = (*elem)->prev;
  free((*elem)->element);
  delete_sbml_attr_stack(&((*elem)->attributes));
  free((*elem));
}

void		delete_sbml_stack(t_SBML **stack)
{
  t_SBML	*curr;
  t_SBML	*next;

  if ((*stack) == NULL)
    return ;
  curr = (*stack)->next;
  while (curr != (*stack))
    {
      next = curr->next;
      free(curr->element);
      delete_sbml_attr_stack(&(curr->attributes));
      free(curr);
      curr = next;
    }
  free((*stack)->element);
  delete_sbml_attr_stack(&((*stack)->attributes));
  free((*stack));
}
