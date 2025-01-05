/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:38:22 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/05 12:39:03 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "src/ft_printf.h"

char received_string[1024];
int current_bit = 0;
int current_char = 0;
static char current_byte = 0;

void handle_sigusr(int sig) 
{
    // Ajouter le bit reçu au byte en cours
    if (sig == SIGUSR1)
        current_byte = (current_byte << 1); // Bit 0
    else if (sig == SIGUSR2)
        current_byte = (current_byte << 1) | 1; // Bit 1
	
    current_bit++;
	
    // Si un caractère complet est reçu (8 bits)
    if (current_bit == 8)
	{
        received_string[current_char++] = current_byte;
        if (current_byte == '\0') 
		{ // Fin de la chaîne
            ft_printf("Chaîne reçue : %s\n", received_string);
            current_char = 0; // Réinitialisation pour une nouvelle réception
        }
        current_bit = 0; // Réinitialisation du compteur de bits
        current_byte = 0;
    }
}


int main()
{
    struct sigaction sa;

    // Initialisation de la structure sigaction
    sa.sa_handler = handle_sigusr;  // Associer le gestionnaire de signal
    // sa.sa_flags = SA_RESTART;      // Reprendre les appels bloquants après un signal
    // sigemptyset(&sa.sa_mask);      // Ne pas bloquer d'autres signaux pendant l'exécution du gestionnaire

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    // Associer les signaux SIGUSR1 et SIGUSR2 au gestionnaire
    // if (sigaction(SIGUSR1, &sa, NULL) == -1) {
    //     perror("Erreur sigaction SIGUSR1");
    //     exit(EXIT_FAILURE);
    // }

    // if (sigaction(SIGUSR2, &sa, NULL) == -1) {
    //     perror("Erreur sigaction SIGUSR2");
    //     exit(EXIT_FAILURE);
    // }
	
    ft_printf("Récepteur prêt. PID : %d\n", getpid());

    // Boucle infinie pour attendre les signaux
    while (1)
        pause(); // Attendre un signal
    return 0;
}


// int	main()
// {
// 	ft_printf("%d\n", getpid());
// 	while(1)
// 		pause();
// }