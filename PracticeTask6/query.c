#include <stdio.h>
#include "schema.h"

int main(int argc, char *argv[]) {

    FILE *f = fopen(argv[1], "rb");
    Team team;

    while(fread(&team, sizeof(Team), 1, f) == 1) {
        if (team.finished == true) {
            printf("%-20s | %-20s | FINISHED\n", team.name, team.projectName);
        }
    }
    fclose(f);
    return 0;
}