#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int valor=100;
int main(int argc, char **argv)
{
pid_t pid=fork(); // Funcao usada para criar um novo processo
if(pid==0){// Processo filho
valor+=100;
exit(0); // Funcao que encerra o processo
}else if(pid>0){ // Processo pai
wait(NULL); // O pai vai esperar a conclusao do filho
}
printf("Valor da variável e %d\n",valor);
return 0;
}
