#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv){

	printf("Sou o processo %d e estou executando o meu proprio programa.\n",getpid());
	sleep(10); //Função que faz o programa dormir durante 10 segundos
	
	
	}
