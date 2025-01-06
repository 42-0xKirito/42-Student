/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:38:22 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/06 20:41:12 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "minitalk.h"
#include "src/ft_printf.h"

struct minitalk var = {0, 0};

void	handle_sigusr(int sig, siginfo_t *info, void *context)
{
	static char		str[2048];
	static char		byte;
	static pid_t	client;

	(void)context;
	if (info->si_pid)
		client = info->si_pid;
	if (sig == SIGUSR1)
		byte = (byte << 1) | 0;
	else if (sig == SIGUSR2)
		byte = (byte << 1) | 1;
	var.nb_byte++;
	if (var.nb_byte == 8)
	{
		str[var.index++] = byte;
		if (byte == '\0')
		{
			ft_printf("Chaîne reçue : %s\n", str);
			kill(client, SIGUSR2);
			var.index = 0;
		}
		var.nb_byte = 0;
		byte = 0;
	}
	kill(client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}