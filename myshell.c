/****************************************************************
 * Name        :  HOANG MINH DONG                               *
 * Class       :  CSC 415                                       *
 * Date        :  July 22, 2019                                 *
 * Description :  Writing a simple bash shell program          *
 *                that will execute simple commands. The main   *
 *                goal of the assignment is working with        *
 *                fork, pipes and exec system calls.            *
 ****************************************************************/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/* CANNOT BE CHANGED */
#define BUFFERSIZE 256
/* --------------------*/
#define PROMPT "myShell >> "
#define PROMPTSIZE sizeof(PROMPT)
int shell();
int redirection();

int 
main(int argc, char** argv)
{
    printf("pid=%d", getpid());
    shell();
return 0;
}

int
shell()
{
    printf("pid=%d", getpid());
    int myargc = 0;
    char *myargv[7];
    //initialize shell
    //fflush(stdin);
    char buffer[BUFFERSIZE];
    //display prompt
    printf("%s",PROMPT);
    //read in user input
    scanf("%[^\n]",buffer);
    //print back input to user console
    printf("%s\n", buffer);

    //parse user input
    char *command = NULL;
    char *ptr = strtok(buffer," ");
    command = ptr;
    if(command != NULL) {
        printf("command:%s\n", command);
    }

    while(ptr != NULL){
        //printf("myargc=%d\n", myargc
        //compare function with redirection opif(strcmp(ptr))

        myargv[myargc] = ptr;
        //display myargv & myargc
        //printf("myargv[%d]=\"%s\"\n",myargc,myargv[myargc]);printf("&myargv[%d](pointer)=%p\n", myargc, &myargv[myargc]);
        //printf("token=%s
        //

        myargc++;
        ptr = strtok(0, " ");
    }
    myargv[myargc] = NULL;

    //execute commands using exec family function
    printf("execvp, pid=%d", getpid());
    execvp(command,myargv);

    //output redirection >, >>, <

    return 0;
}

//output redirectors
int
redirection(char)
{

    // > creates file


    return 0;
}