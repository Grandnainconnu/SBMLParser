/*
** requirement.h for requirement in /home/walrav_j/rendu/SBMLparser/include
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Tue Jun 14 14:52:25 2016 Jean Walrave
** Last update Tue Jun 14 14:54:26 2016 Jean Walrave
*/

#ifndef REQUIREMENT_H_
# define REQUIREMENT_H_

typedef struct		s_parser_stack
{
  const char            *str;
  struct s_parser_stack *next;
}			t_parser_stack;

char	**my_strtowordtab_synthesis(char *);

#endif /* !REQUIREMENT_H_ */
