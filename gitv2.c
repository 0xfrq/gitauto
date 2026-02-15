#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char command[512];

    if(argc < 3) {
        printf("numero: %s <branch> \"commit message\"\n", argv[0]);
        return 1;
    }

    char *branch = argv[1];
    char *message = argv[2];

    snprintf(command, sizeof(command),
             "git checkout %s", branch);

    if (system(command) != 0) {
        printf("yahh: git checkout failed :(\n");
        return 1;
    }

    if (system("git add .") != 0) {
        printf("yahh: git add failed :(\n");
        return 1;
    }

    snprintf(command, sizeof(command),
             "git commit -m \"%s\"", message);

    if (system(command) != 0) {
        printf("yahh: git commit failed :(\n");
        return 1;
    }

    snprintf(command, sizeof(command),
             "git push origin %s", branch);

    if (system(command) != 0) {
        printf("yahh: git push failed :(\n");
        return 1;
    }

    printf("Sukses cuy \n");
    return 0;
}
