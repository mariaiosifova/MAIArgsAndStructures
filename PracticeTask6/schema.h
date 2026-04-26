#ifndef SCHEMA_H
#define SCHEMA_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    char name[64];
    char projectName[64];
    int membersCount;
    bool created;
    bool checked;
    bool finished;
} Team;


#endif