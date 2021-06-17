#include "philo.h"

// ◦ timestamp_in_ms X has taken a fork
// ◦ timestamp_in_ms X is eating
// ◦ timestamp_in_ms X is sleeping
// ◦ timestamp_in_ms X is thinking
// ◦ timestamp_in_ms X died

// static int	ft_pthread_self(pthread_t *all)
// {
// 	int	i;

// 	i = 0;
// 	while (all[i])
// 		i++;
// 	return (i - 1);
// }

static void	*init_routine(void *data)
{
	t_philo	*philo;
	int		whoami;


	philo = data;
	whoami = philo->whoami;
	if (ft_isodd_num(whoami))
		usleep(10);
	// whoami = ft_pthread_self(philo->philo);
	eating(philo, whoami);
	sleeping(philo, whoami);
	thinking(philo, whoami);
	// dead_end(philo, whoami);
}

void	*init_philo(int philo_num, t_philo *philo)
{
	int	i;

	i = 0;
	if ((philo->philo = malloc((philo_num + 1) * sizeof(pthread_t))) == NULL)
		return (0);
	memset(philo->philo, 0, (philo_num + 1) * sizeof(pthread_t));
	while (i < philo_num)
	{
		philo->whoami = i;
		if (pthread_create(&(philo->philo[i]), PTHREAD_CREATE_DETACHED,\
		init_routine, philo) < 0)
			return (0);
		i++;
	}
	return (philo);
}
