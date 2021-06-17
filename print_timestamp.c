#include "philo.h"

int	print_timestamp(t_philo *philo, int whoami)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	write(1, (philo->start_time->tv_sec - now.tv_sec), 8);
	write(1, " ", 1);
	write(1, whoami, 4);
	write(1, " ", 1);
	return (0);
}
