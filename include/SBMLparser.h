/*
** SBMLparser.h for SBMLparser in /home/walrav_j/rendu/SBMLparser
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Mon Jun 13 10:12:10 2016 Jean Walrave
** Last update Wed Jun 15 20:28:46 2016 Jean Walrave
*/

#ifndef SBMLPARSER_H_
# define SBMLPARSER_H_
# define OPT_SIZE 3
# define ERR_BAD_OPT "Unknown option '%s' !\n"
# define ERR_OPT_NO_VALUE "Option '%s' need a good value !\n"
# define SBML_EXIT_ERROR 84
# define SBML_BASIC_PATTERN "?< \t=\"'/>"
# define SBML_ATTR_PATTERN "'\"= "
# define SBML_ATTR_VALUE_PATTERN "'\"="
# define IS_CHAR(a, b) (a && a == b)
# define READ_SIZE 1000
# define USAGE "usage: %s SBMLfile [-i ID [-e]] [-json]\n"
# define ERR_INVALID_ARGS "Please enter a file !\n"
# define ERR_COPEN_FILE "Can't open SBML file !\n"

typedef enum {tag, element, none}	t_SBML_type;

typedef struct				s_argument
{
  char					*option;
  int					has_value;
  void					*value;
}					t_argument;

typedef struct				s_gnl_stack
{
  char					c;
  struct s_gnl_stack			*next;
}					t_gnl_stack;

typedef struct				s_SBML_attribute
{
  char					*name;
  void					*value;
  struct s_SBML_attribute		*prev;
  struct s_SBML_attribute		*next;
}					t_SBML_attribute;

typedef struct				s_SBML
{
  char					*element;
  t_SBML_attribute			*attributes;
  t_SBML_type				type;
  struct s_SBML				*prev;
  struct s_SBML				*next;
}					t_SBML;

char			*get_next_line(const int);
t_SBML			**get_parsed(const int);
t_SBML			*init_sbml_stack(void);
int			add_elem_to_sbml_stack(t_SBML **,
					       char *, t_SBML_attribute **,
					       t_SBML_type);
void			delete_sbml_stack_elem(t_SBML **);
void			delete_sbml_stack(t_SBML **);
t_SBML_attribute	*init_sbml_attr_stack(void);
int			add_elem_to_sbml_attr_stack(t_SBML_attribute **,
                                                    char *, void *);
void			delete_sbml_attr_stack_elem(t_SBML_attribute **);
void			delete_sbml_attr_stack(t_SBML_attribute **);
void			sbml_sort_alphabeticaly(t_SBML **);
void			sbml_attr_sort_alphabeticaly(t_SBML_attribute **, int);
void			sbml_sort_by_attr_alphabeticaly(t_SBML **);
void			display_sbml_sorted(t_SBML **);
int			display_sbml_compartment(t_SBML **, const char *);
int			is_compartment_id(t_SBML **, const char *);
int			is_species_id(t_SBML **, const char *);
t_SBML			**get_species(t_SBML **, const char *);
void			options_gestionnary(t_argument *, t_SBML **);

#endif /* !SBMLPARSER_H_ */
