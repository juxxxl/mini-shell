#include <stdio.h>

int main() {
    char command[100];
    while (1) {
        printf("mini-shell> ");
        fgets(command, sizeof(command), stdin);
        // Remove newline character from the end of the command
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0) {
            break;
        }

        system(command);
    }
    return 0;
}

int ls(int argc, char *argv[]) {

  
  
  return 0;
}

