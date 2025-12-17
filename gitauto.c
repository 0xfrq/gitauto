#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char command[512];

    if(argc < 2) {
        printf("Usage: %s \"commit message\"\n", argv[0]);
        return 1;
    }

    if (system("git add .") != 0) {
        printf("Error: git add failed :( \n");
        return 1;
    }

    snprintf(command, sizeof(command),
    "git commit -m \"%s\"", argv[1]);

    if (system(command) != 0) {
        printf("Error: git commit failed\n");
        return 1;
    }

    if (system("git push origin master") != 0) {
        printf("Error: git push failed\n");
        return 1;
    }

    printf("sukses cuy\n");
    return 0;
}