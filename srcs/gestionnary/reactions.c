/*
** reactions.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs/gestionnary
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 21:04:38 2016 Jean Walrave
** Last update Wed Jun 15 21:07:21 2016 Jean Walrave
*/

#include <string.h>
#include "SBMLparser.h"

void			*get_reaction_id(t_SBML *elem)
{
  t_SBML_attribute	*tmp_attr;

  if (elem->attributes && (tmp_attr = (elem->attributes)->next))
    while (tmp_attr != elem->attributes)
      {
	if (!strcmp(tmp_attr->name, "id"))
	  return (tmp_attr->value);
	tmp_attr = tmp_attr->next;
      }
  return (NULL);
}
