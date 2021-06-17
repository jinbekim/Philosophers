#include "philo.h"

static int	print_time_thinking(t_philo *philo, int whoami)
{
	print_timestamp(philo, whoami);
	write(1, "is thinking", 11);
}

int		thinking(t_philo *philo, int whoami)
{
	print_time_thinking(philo, whoami);
}
