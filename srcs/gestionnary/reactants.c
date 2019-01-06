/*
** reactants.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs/gestionnary
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 20:32:49 2016 Jean Walrave
** Last update Wed Jun 15 21:10:06 2016 Jean Walrave
*/

#include "SBMLparser.h"

void			*get_stoichiometry(t_SBML *elem, const char *species)
{
  t_SBML_attribute	*tmp_attr;

  if (elem->attributes && (tmp_attr = (elem->attributes)->next))
    while (tmp_attr != elem->attributes)
      {
        if ((!strcmp(tmp_attr->name, "species") &&
	     !strcmp(tmp_attr->value, species)))
          {
            while (tmp_attr->next != tmp_attr)
              {
                if (!strcmp(tmp_attr->name, "stoichiometry"))
		  return (tmp_attr->value);
                tmp_attr = tmp_attr->next;
              }
            break;
          }
        tmp_attr = tmp_attr->next;
      }
  return (NULL);
}

t_SBML			*get_reactants(t_SBML **stack, const char *species)
{
  t_SBML		*reactants_stack;
  t_SBML		*tmp;
  t_SBML_attribute	*tmp_attr;
  char			*tmp_str;

  if ((reactants_stack = init_sbml_stack()) == NULL)
    return (NULL);
  tmp = (*stack)->next;
  while (tmp != (*stack))
    {
      if (!strcmp(tmp->element, "reaction"))
	tmp_str =
      if (!strcmp(tmp->element, "listOfReactants") && (tmp = tmp->next))
	while (tmp != (*stack) && !strcmp(tmp->element, "listOfReactants"))
	  {
	    tmp = tmp->next;
	  }
      tmp = tmp->next;
    }
}
