/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:51:59 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/05 14:50:02 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <signal.h>

void send_char(pid_t pid, char c) 
{
	int	i;

	i = 7;
    while (i >= 0)
	{ // Envoyer bit par bit
        if ((c >> i) & 1)
            kill(pid, SIGUSR2); // Bit 1
        else
            kill(pid, SIGUSR1); // Bit 0
		
        usleep(500); // Pause pour que le récepteur traite le signal
		i--;
    }
}

void send_string(pid_t pid, const char *str)
{
	size_t	i;

	i = 0;
    while (i <= ft_strlen(str))
	{
        send_char(pid, str[i]);
		i++;
    }
}

int main(int argc, char **argv)
{
	const char *message;
	pid_t pid;
	
    if (argc != 3)
	{
        ft_printf("Usage: %s <PID> <message>\n", argv[0]);
        return 1;
    }
	pid = ft_atoi(argv[1]);
	message = argv[2];
    send_string(pid, message);
    return 0;
}


// int main(int ac, char **av)
// {
// 	if (ac != 3)
// 		return(ft_printf("./client \"PID\" \"Msg to send\"\n"));
// }