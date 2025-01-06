/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:51:59 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/06 20:51:47 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <signal.h>

volatile sig_atomic_t	g_ack_received = 0;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
	else if (sig == SIGUSR2)
		ft_printf("Message complet reçu par le serveur.\n");
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
			usleep(42);
		i--;
	}
}

void	send_string(pid_t pid, const char *str)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		send_char(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	const char			*message;
	pid_t				pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	sa.sa_handler = ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	message = argv[2];
	send_string(pid, message);
	return (0);
}
