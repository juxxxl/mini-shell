#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int tokenize_command(char *command, char **argv) {

  int argc = 0; 

  char *token = strtok(command, " ");
 
  while (token != NULL) {

    argv[argc] = token;

    argc++;

    token = strtok(NULL, " ");

  }

  argv[argc] = NULL;

  return argc;

}

void exec_command(char **argv) {

  pid_t pid = fork();

  if (pid == 0) {

    execvp(argv[0], argv);

    perror("execvp failed miserably my guy ");

    exit(1) ;

  }

  else if ( pid > 0) {

    wait(NULL);

  }
} 



int main() {
    char command[100];
    char current_path[1024];
    char *user = getlogin();
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
    getcwd(current_path, sizeof(current_path));
    while (1) {
        printf("[%s||%s > %s]", user, hostname, current_path);
        fgets(command, sizeof(command), stdin);

        // remove newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }
        
        char *argv[64];
        
        int argc = tokenize_command(command,argv);

        if (strcmp(argv[0], "cd") == 0) {
          chdir(argv[1]);
          getcwd(current_path, sizeof(current_path));
        }
        else {
          exec_command(argv);
        }


        
    
    }
    return 0;
}


// to do: pipe / autocompletion