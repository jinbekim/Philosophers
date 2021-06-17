#include "philo.h"

void	*make_fork(int philo_num)
{
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	if (fork == malloc(sizeof(pthread_mutex_t *) * (philo_num + 1)))
		return (0);
	memset(fork, 0, sizeof(pthread_mutex_t) * (philo_num + 1));
	while (i < philo_num)
	{
		if (pthread_mutex_init(&fork[i], NULL) < 0)
			return (0);
		i++;
	}
	return (fork);
}
