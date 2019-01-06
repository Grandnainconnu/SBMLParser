/*
** displayer.c for SBMLparser in /home/walrav_j/rendu/SBMLparser/srcs
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Wed Jun 15 12:58:28 2016 Jean Walrave
** Last update Wed Jun 15 20:15:33 2016 Jean Walrave
*/

#include <stdio.h>
#include <string.h>
#include "SBMLparser.h"

void			display_sbml_sorted(t_SBML **stack)
{
  t_SBML		*tmp;
  t_SBML_attribute      *tmp_attr;

  sbml_sort_alphabeticaly(stack);
  tmp = (*stack)->next;
  while (tmp != (*stack))
    {
      if (tmp->type != tag && (tmp->prev->element == NULL ||
			       (tmp->prev->element &&
				strcasecmp(tmp->prev->element, tmp->element))))
        {
          printf("%s\n", tmp->element);
          if (tmp->attributes)
            {
              sbml_attr_sort_alphabeticaly(&(tmp->attributes), 0);
              tmp_attr = (tmp->attributes)->next;
              while (tmp_attr != (tmp->attributes))
                {
                  printf("----->%s\n", tmp_attr->name);
                  tmp_attr = tmp_attr->next;
                }
            }
        }
      tmp = tmp->next;
    }
}
