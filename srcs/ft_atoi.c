/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinbekim <jinbekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:50:51 by jinbekim          #+#    #+#             */
/*   Updated: 2021/06/25 17:31:47 by jinbekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int			ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int			ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int					ft_atoi(const char *s)
{
	size_t			i;
	int				c;
	int				neg;

	i = 0;
	c = 0;
	neg = 1;
	if (s == NULL)
		return (0);
	while (ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		c = (c * 10) + neg * (s[i] - '0');
		i++;
	}
	return (c);
}

void				ft_usleep(uint64_t ms)
{
	struct timeval	check;
	uint64_t		time;
	uint64_t		now;

	gettimeofday(&check, NULL);
	now = check.tv_sec * 1000 + check.tv_usec / 1000;
	time = ms + now;
	while (now < time)
	{
		gettimeofday(&check, NULL);
		now = check.tv_sec * 1000 + check.tv_usec / 1000;
		usleep(1000);
	}
}
