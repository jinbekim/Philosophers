#include "philo.h"

static int	print_time_sleeping(t_philo *philo, int whoami, int tts)
{
	print_timestamp(philo, whoami);
	write(1, "is sleeping", 11);
	usleep(tts);
}

int	sleeping(t_philo *philo, int whoami)
{
	print_time_sleeping(philo, whoami, philo->tts);
}
