
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    char* commande = "emacs";
    char * argv[] = { "test.txt", NULL};

    execvp(commande,argv);
    return 0;
}