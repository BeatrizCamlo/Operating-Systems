#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int i;

	// Criar 4 processos filhos consecutivos
	for (i = 0; i < 4; i++) {
		pid = fork();
		if (pid < 0) {
			// Se o fork falhar
			perror("Erro ao criar processo filho");
			exit(1);
		} else if (pid == 0) {
			// Processo filho
			printf("Processo filho (PID: %d, Pai PID: %d)\n", getpid(), getppid());
			// Simular algum trabalho no processo filho
			sleep(2 + i);  // Filhos demoram tempos diferentes para terminar
			exit(0);       // Termina o processo filho
		}
		// O processo pai continua o loop e cria o próximo filho
	}

	// Processo pai inicial espera por todos os seus filhos
	for (i = 0; i < 4; i++) {
		pid_t terminated_pid = wait(NULL);  // Espera qualquer filho terminar
		if (terminated_pid > 0) {
			printf("Processo pai detectou que o filho (PID: %d) terminou.\n", terminated_pid);
		}
	}

	printf("Todos os filhos terminaram. Processo pai encerrado.\n");

	return 0;
}
