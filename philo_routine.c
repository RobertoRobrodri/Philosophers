/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:17 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/15 17:04:57 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_slp(t_philo *ph)
{
	if (!ph->prg->running || ph->full)
		return ;
	print_action(ph, SLEEPING);
	ft_usleep(ph->prg->slp);
}

static void	action_thk(t_philo *ph)
{
	if (!ph->prg->running || ph->full)
		return ;
	print_action(ph, THINKING);
}

void	*routine(void *tid)
{
	t_philo	*ph;

	ph = (t_philo *)tid;
	if (ph->prg->n_philo == 1)
	{
		print_action(ph, FORK_TAKEN);
		ft_usleep(ph->prg->die);
		return (NULL);
	}
	if (ph->idx % 2)
		usleep(100);
	while (ph->prg->running)
	{
		action_eat(ph);
		if (ph->full)
			break ;
		action_slp(ph);
		action_thk(ph);
	}
	return (NULL);
}
