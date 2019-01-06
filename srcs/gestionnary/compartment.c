/*
** compartment.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs/gestionnary
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 18:38:55 2016 Jean Walrave
** Last update Wed Jun 15 19:37:54 2016 Jean Walrave
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SBMLparser.h"

int			is_compartment_id(t_SBML **stack, const char *id)
{
  t_SBML		*tmp;
  t_SBML_attribute	*tmp_attr;

  tmp = (*stack)->next;
  while (tmp != (*stack))
    {
      if (!strcmp(tmp->element, "compartment"))
	{
	  if (tmp->attributes && (tmp_attr = (tmp->attributes)->next))
	    while (tmp_attr != tmp->attributes)
	      {
		if (!strcmp(tmp_attr->name, "id") &&
		    !strcmp(tmp_attr->value, id))
		  return (0);
		tmp_attr = tmp_attr->next;
	      }
	}
      tmp = tmp->next;
    }
  return (1);
}
