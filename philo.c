/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:17:54 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:17:56 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_instructions(void)
{
	printf("Insert arguments like this: \n");
	printf("[Number of philoshopers] , [Time to die], [Time to eat] \n");
	printf("[Time to sleep] , (OPTIONAL)");
	printf("[Number of times each philosopher must eat] \n");
}

static int	store_args(int argc, char **argv, t_prg *prg)
{
	prg->n_philo = ft_atoi(argv[1]);
	prg->die = ft_atoi(argv[2]);
	prg->eat = ft_atoi(argv[3]);
	prg->slp = ft_atoi(argv[4]);
	if (argc == 6)
		prg->n_eat = ft_atoi(argv[5]);
	else
		prg->n_eat = -1;
	if (!prg->die || !prg->eat || !prg->slp || !prg->n_eat
		|| prg->n_philo > MAX_PHILO || !prg->n_philo)
	{
		printf("An error has ocurred\n");
		return (0);
	}
	return (1);
}

static int	check_args(int argc, char **argv)
{
	while (--argc)
	{
		if (!ft_error_control(argc, argv))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
		{
			if (!store_args(argc, argv, &prg))
				return (0);
			create_table(&prg);
		}
		else
			printf("An error has ocurred\n");
	}
	else
		print_instructions();
	return (0);
}
