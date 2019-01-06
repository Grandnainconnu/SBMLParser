/*
** options.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs/gestionnary
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 19:00:19 2016 Jean Walrave
** Last update Thu Jun 16 00:34:31 2016 Jean Walrave
*/

#include <stdio.h>
#include "SBMLparser.h"

static void	display_species(t_SBML **stack, const char *id, int is_cpt_id)
{
  t_SBML	*tmp;

  sbml_sort_by_attr_alphabeticaly(stack);
  tmp = (*stack)->next;
  if (!is_cpt_id)
    printf("List of species in compartment %s\n", id);
  else
    printf("List of species\n");
  while (tmp != (*stack))
    {
      printf("----->%s\n", (char *)tmp->attributes->value);
      tmp = tmp->next;
    }
}

void	options_gestionnary(t_argument *arguments, t_SBML **stack)
{
  char		*id;
  int		is_cpt_id;
  t_SBML	**species;

  if (arguments[0].value != NULL)
    {
      id = (char *)arguments[0].value;
      is_cpt_id = is_compartment_id(stack, id);
      species = get_species(stack, id);
      display_species(species, id, is_cpt_id);
    }
  else
    display_sbml_sorted(stack);
  delete_sbml_stack(stack);
}
