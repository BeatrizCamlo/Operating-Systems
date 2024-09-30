#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char **argv){
	fork(); // Processo pai (P0) cria um processo filho (P1)
	fork(); // Processo pai (P0) cria um processo filho (P3) e filho (P1) cria um processo filho (P4)
	fork(); // Os processos P0, P1, P2, P3, P4 criamum processo cada 
	printf("Sou o processo %d.\n", getpid());
	return 0;
	}

