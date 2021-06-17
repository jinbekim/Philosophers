/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 21:00:18 by jinbekim          #+#    #+#             */
/*   Updated: 2021/06/17 17:03:00 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	print_time_thinking();

static void	save_argument(t_philo *philo, char **av)
{
	philo->p_num = ft_atoi(av[P_NUM]);
	philo->ttd = ft_atoi(av[TTD]);
	philo->tte = ft_atoi(av[TTE]);
	philo->tts = ft_atoi(av[TTS]);
	philo->opt = ft_atoi(av[OPT]);
}

int			main(int ac, char *av[])
{
	t_philo	*philo;

	if (ac < 5 || ac > 6)
		return (ERR);
	if (philo = malloc(sizeof(t_philo)) == NULL)
		return (ERR);
	save_argument(philo, av);
	if (philo->fork = make_fork(philo->p_num) == NULL)
		return (ERR);
	if (gettimeofday(philo->start_time, NULL) == -1)
		return (ERR);
	if (init_philo(philo->p_num, philo) == NULL)
		return (ERR);
}





// External functs:
//  memset, printf, malloc, free, write,
//  usleep
//	gettimeofday
// 	pthread_create,
//  pthread_detach
// 	pthread_join
// 	pthread_mutex_init,
//  pthread_mutex_destroy
// 	pthread_mutex_lock,
//  pthread_mutex_unlock

