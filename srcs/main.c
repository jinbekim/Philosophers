/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:00:18 by jinbekim          #+#    #+#             */
/*   Updated: 2021/07/02 16:05:14 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argument(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (1);
	else if (
	ft_atoi(av[P_NUM]) <= 0 || ft_atoi(av[TTD]) <= 0 ||
	ft_atoi(av[TTE]) <= 0 || ft_atoi(av[TTS]) <= 0)
		return (1);
	return (0);
}

static void	clean_table(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->arg->p_num)
	{
		pthread_mutex_unlock(&env->fork[i]);
		printf("fork: %d\n", pthread_mutex_destroy(&env->fork[i]));
		i++;
	}
	free(env->fork);
	free(env->philo);
	free(env->arg);
	free(env);
}

int			main(int ac, char *av[])
{
	t_env	*env;

	if (check_argument(ac, av))
		return (1);
	if (set_env(&env, av))
		return (1);
	if (pthread_branch(env))
		return (1);
	monitor_philos(env);
	clean_table(env);
	return (0);
}
