/*
** SBMLparser.c for SBMLparser in /home/walrav_j/rendu/SBMLparser
**
** Made by Jean Walrave
** Login   <walrav_j@epitech.net>
**
** Started on  Mon Jun 13 10:11:34 2016 Jean Walrave
** Last update Wed Jun 15 19:18:58 2016 Jean Walrave
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "SBMLparser.h"

t_argument	arguments[] = {
  {"-i", 1, 0},
  {"-e", 0, NULL},
  {"-json", 0, NULL}
};

static void	put_usage(const char *binname)
{
  fprintf(stderr, USAGE, binname);
}

static int	treat_argument(int opt, int arg, char ***argv)
{
  static int	true_value;

  true_value = 1;
  if (!arguments[opt].has_value)
    arguments[opt].value = &true_value;
  else if (arguments[opt].has_value && (*argv)[arg + 1] &&
	   (*(*argv)[arg + 1]) != '-')
    {
      arguments[opt].value = (*argv)[arg + 1];
      ++(*argv);
    }
  else
    {
      fprintf(stderr, ERR_OPT_NO_VALUE, (*argv)[arg]);
      return (1);
    }
  return (0);
}

static int		get_opt(char **argv)
{
  int			i[2];

  i[0] = 1;
  while (argv[++i[0]])
    {
      i[1] = -1;
      while (++i[1] < OPT_SIZE)
	{
	  if (!strcmp(argv[i[0]], arguments[i[1]].option))
	    {
	      if (treat_argument(i[1], i[0], &argv))
		return (1);
	      else
		break;
	    }
	}
      if (i[1] >= OPT_SIZE)
	{
	  fprintf(stderr, ERR_BAD_OPT, argv[i[0]]);
	  return (1);
	}
    }
  return (0);
}

static int	get_fd(char *filename)
{
  int		fd;
  struct stat	statbuf;

  if (filename == NULL || (stat(filename, &statbuf)) || S_ISDIR(statbuf.st_mode)
      || (fd = open(filename, O_RDONLY)) < 0)
    return (-1);
  else
    return (fd);
}

int		main(int argc, char **argv)
{
  int		fd;
  t_SBML	**stack;

  if (argc < 2 || (argc >= 2 && (fd = get_fd(argv[1])) < 0))
    {
      fprintf(stderr, argc < 2 ? ERR_INVALID_ARGS : ERR_COPEN_FILE);
      put_usage(argv[0]);
      return (SBML_EXIT_ERROR);
    }
  else if (get_opt(argv) != 0)
    {
      put_usage(argv[0]);
      return (SBML_EXIT_ERROR);
    }
  else if ((stack = get_parsed(fd)) == NULL)
    return (SBML_EXIT_ERROR);
  else
    options_gestionnary((t_argument *)arguments, stack);
  return (0);
}
