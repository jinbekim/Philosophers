/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:50:42 by jinbekim          #+#    #+#             */
/*   Updated: 2021/06/25 08:52:18 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_fork_time(struct timeval *start, int who)
{
	struct timeval	now;
	uint64_t		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec) / 1000;
	time -= (start->tv_sec) * 1000 + (start->tv_usec) / 1000;
	printf("%llums %d has taken a fork\n", time, who);
	return (0);
}

int	print_eating_time(struct timeval *start, int who)
{
	struct timeval	now;
	uint64_t		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec) / 1000;
	time -= (start->tv_sec) * 1000 + (start->tv_usec) / 1000;
	printf("%llums %d is eating\n", time, who);
	return (0);
}

int	print_sleeping_time(struct timeval *start, int who)
{
	struct timeval	now;
	uint64_t		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec) / 1000;
	time -= (start->tv_sec) * 1000 + (start->tv_usec) / 1000;
	printf("%llums %d is sleeping\n", time, who);
	return (0);
}

int	print_thinking_time(struct timeval *start, int who)
{
	struct timeval	now;
	uint64_t		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec) / 1000;
	time -= (start->tv_sec) * 1000 + (start->tv_usec) / 1000;
	printf("%llums %d is thinking\n", time, who);
	return (0);
}

int	print_died_time(struct timeval *start, int who)
{
	struct timeval	now;
	uint64_t		time;

	gettimeofday(&now, NULL);
	time = (now.tv_sec * 1000) + (now.tv_usec) / 1000;
	time -= (start->tv_sec) * 1000 + (start->tv_usec) / 1000;
	printf("%llums %d died\n", time, who);
	return (0);
}
