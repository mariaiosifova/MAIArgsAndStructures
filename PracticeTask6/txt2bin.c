#include <stdio.h>
#include "schema.h"

int main(int argc, char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    Team team;
    char line[128];
    FILE *f = fopen(argv[2], "wb");
    for(int i = 0; i < 20; i++) {
        fgets(line, sizeof(line), in);
        sscanf(line, "%[^,],%[^,],%d,%d,%d,%d",
            team.name, 
            team.projectName, 
            &team.membersCount,
            (int *)&team.created, 
            (int *)&team.checked, 
            (int *)&team.finished);
            
            fwrite(&team, sizeof(Team), 1, f);
    }
    fclose(f);
    fclose(in);
    
    return 0;
}