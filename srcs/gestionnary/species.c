/*
** species.c for species in /home/walrav_j/rendu/SBMLparser/srcs/gestionnary
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 19:37:29 2016 Jean Walrave
** Last update Wed Jun 15 20:27:42 2016 Jean Walrave
*/

#include <string.h>
#include "SBMLparser.h"

int			is_species_id(t_SBML **stack, const char *id)
{
  t_SBML		*tmp;
  t_SBML_attribute	*tmp_attr;

  tmp = (*stack)->next;
  while (tmp != (*stack))
    {
      if (!strcmp(tmp->element, "species"))
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

static void		extract_species(t_SBML **stack, t_SBML *elem,
					  const char *id, int is_cpt_id)
{
  t_SBML_attribute	*tmp_attr;

  if (elem->attributes && (tmp_attr = (elem->attributes)->next))
    while (tmp_attr != elem->attributes)
      {
	if (is_cpt_id || (!strcmp(tmp_attr->name, "compartment") &&
			  !strcmp(tmp_attr->value, id)))
	  {
	    while (tmp_attr->next != tmp_attr)
	      {
		if (!strcmp(tmp_attr->name, "name"))
		  {
		    add_elem_to_sbml_stack(stack, elem->element,
					   &(tmp_attr), element);
		    break;
		  }
		tmp_attr = tmp_attr->next;
	      }
	    break;
	  }
	tmp_attr = tmp_attr->next;
      }
}

t_SBML			**get_species(t_SBML **stack, const char *id)
{
  static t_SBML		*species_stack;
  t_SBML		*tmp;
  int			is_cpt_id;

  if ((species_stack = init_sbml_stack()) == NULL)
    return (NULL);
  is_cpt_id = is_compartment_id(stack, id);
  tmp = (*stack)->next;
  while (tmp != (*stack))
    {
      if (!strcmp(tmp->element, "species"))
	extract_species(&species_stack, tmp, id, is_cpt_id);
      tmp = tmp->next;
    }
  return (&species_stack);
}
