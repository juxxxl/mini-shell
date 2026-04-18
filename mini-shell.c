#include <stdio.h>

typedef struct {
  char *name;
  int (*func)(int argc, char **argv) 
} Command;

int main() {
    char command[100];
    char current_path[1024]
    while (1) {
        printf("mini-shell> ");
        fgets(command, sizeof(command), stdin);

        // remove newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }
        

        for (int i = 0; commands[i].name != NULL; i++) {    // idk what i did in this blob :cry:

          if (strcmp(commands[i].name, command) == 0 ) {

            commands[i].func(argc, argv[])

          }

        }

    
    }
    return 0;
}

Command commands[] = {
  { "cd", my_cd},
  {NULL, NULL}
};


void my_cd(int argc, char **argv) {

}


// To do: tokenize user command input /  make the cd command (only command i need to actually implement, for the rest ill fork execv and use built in unix commands, )