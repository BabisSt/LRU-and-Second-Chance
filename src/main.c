#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/Simulator.h"

int main(int argc, char* argv[])
{
    if (argc < 7)
    {
        printf("Wrong input\n");
    }

    char* algorithm;
    int quantity = 0, maxReferences = 1000000, frames = 0;

    for (int i = 0; i < argc; i++)              //diabazoume ta orismata
    {
        if(strcmp(argv[i], "-f") == 0)
        {
            frames = atoi(argv[++i]);
        }
        else if(strcmp(argv[i], "-q") == 0)
        {
            quantity = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-m") == 0)
        {
            maxReferences = atoi(argv[++i]);
        }
        else if (strcmp(argv[i], "-a") == 0)
        {
            i++;
            if((algorithm = malloc(sizeof(argv[i]))) == NULL)
            {
                perror("cant malloc");
                return -1;
            }
            strcpy(algorithm,argv[i]);
            
        }
        
        
    }

    simulatorRun(algorithm,frames,quantity,maxReferences);      //trexome to simulation
    free(algorithm);
    return 0;
    
}