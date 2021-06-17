#include "philo.h"

static int	print_time_taken_fork(t_philo *philo, int whoami)
{
	print_timestamp(philo, whoami);
	write(1, "has taken a fork", 16);
}

static int	print_time_eating(t_philo *philo, int whoami, int tte)
{
	print_timestamp(philo, whoami);
	write(1, "is eating", 9);
	usleep(tte);
}

static void	whats_fork_next_to_me(int **fork, int whoami, int num)
{
	*(fork[RIGHT]) = whoami;
	*(fork[LEFT]) = whoami + 1;
	if (whoami == num)
		*(fork[LEFT]) == 0;
}

static int	pick_a_fork(pthread_mutex_t *fork, t_philo *philo, int whoami)
{
	pthread_mutex_lock(fork);
	print_time_taken_fork(philo, whoami);
	return (1);
}

static int	drop_a_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
	return (1);
}

int	eating(t_philo *philo, int whoami)
{
	int	num_of_hold_fork;
	int	fork[2];

	whats_fork_next_to_me(&fork, whoami, philo->p_num);
	num_of_hold_fork = 0;
	num_of_hold_fork += pick_a_fork(fork[RIGHT], philo, whoami);
	num_of_hold_fork += pick_a_fork(fork[LEFT], philo, whoami);
	if (num_of_hold_fork == 2)
		print_time_eating(philo, whoami, philo->tte);
	num_of_hold_fork -= drop_a_fork(fork[RIGHT]);
	num_of_hold_fork -= drop_a_fork(fork[LEFT]);
}
