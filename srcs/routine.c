/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:50:54 by jinbekim          #+#    #+#             */
/*   Updated: 2021/07/02 16:04:49 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int			pick_a_fork(pthread_mutex_t *fork, t_philo *philo)
{
	pthread_mutex_lock(fork);
	if (philo->survival == DEAD)
		return (1);
	print_fork_time(philo->start_time, philo->id);
	return (0);
}

static int			drop_a_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
	return (0);
}

static int			eating(t_philo *philo)
{
	pick_a_fork(philo->fork_right, philo);
	pick_a_fork(philo->fork_left, philo);
	gettimeofday(&philo->start_eat_time, NULL);
	if (philo->survival == DEAD)
		return (1);
	print_eating_time(philo->start_time, philo->id);
	ft_usleep(philo->arg->tte);
	philo->eat_time++;
	drop_a_fork(philo->fork_left);
	drop_a_fork(philo->fork_right);
	return (0);
}

void				*routine(void *data)
{
	t_philo			*philo;

	philo = data;
	gettimeofday(&philo->start_eat_time, NULL);
	while (philo->survival == ALIVE)
	{
		eating(philo);
		if (philo->survival == DEAD)
			break ;
		print_sleeping_time(philo->start_time, philo->id);
		ft_usleep(philo->arg->tts);
		if (philo->survival == DEAD)
			break ;
		print_thinking_time(philo->start_time, philo->id);
	}
	return (NULL);
}
