#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>


# define ERR 1

enum	e_fork{
	RIGHT,
	LEFT
};

/*
** number_of_philosophers
** time_to_die
** time_to_eat
** time_to_sleep
** [number_of_times_each_philosopher_must_eat]
*/

enum	e_arg{
	P_NUM = 1,
	TTD,
	TTE,
	TTS,
	OPT
};

typedef struct	s_philo{
	int				whoami;
	int				p_num;
	int				ttd;
	int				tte;
	int				tts;
	int				opt;
	pthread_mutex_t	*fork;
	pthread_t		*philo;
	struct timeval	*start_time;
}				t_philo;

int		ft_atoi(const char *s);
int		ft_isodd_num(int num);
void	*make_fork(int philo_num);
void	*init_philo(int philo_num, t_philo *philo);
int		eating(t_philo *philo, int whoami);
int		sleeping(t_philo *philo, int whoami);
int		thinking(t_philo *philo, int whoami);
int		print_timestamp(t_philo *philo, int whoami);

#endif
