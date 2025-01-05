/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:50:21 by engiacom          #+#    #+#             */
/*   Updated: 2025/01/05 12:51:52 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) {
    printf("Signal %d (SIGINT) reçu. Interruption ignorée.\n", signum);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = signal_handler;  // Définir le gestionnaire
    sigemptyset(&sa.sa_mask);        // Aucun signal bloqué
    sa.sa_flags = 0;                 // Pas d'options spécifiques

    // Installer le gestionnaire pour SIGINT
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    printf("Appuyez sur Ctrl+C. Le signal sera géré par le programme.\n");
    while (1) {
        pause();  // Attente d'un signal
    }

    return 0;
}
