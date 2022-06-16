#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../headers/Simulator.h"
#include "../headers/InvertedPageTable.h"
#include "../headers/queue.h"
#include "../headers/LRU.h"
#include "../headers/SC.h"
#include "../headers/list.h"

int simulatorRun(char* algorithm, int frames, int quantity, int maxReferences)
{
    IptPtr ipt = NULL;                                  //arxikopoihseis
    statistics* stats = malloc(sizeof(statistics));
    stats->reads = 0;
    stats->writes = 0;
    stats->pageRequest = 0;
    stats->pageFaults = 0;

    if((ipt = malloc(sizeof(Ipt))) == NULL)
    {
        perror("cant malloc");
        return -1;
    }
    ipt->currSize = 0;
    ipt->maxSize  = frames;
    
    if((ipt->array = malloc(frames*sizeof(IptAddressPtr))) == NULL)
    {
        perror("cant malloc \n");
        return -1;
    }

    for (int i = 0; i < ipt->maxSize; i++)
    {
        ipt->array[i] = NULL;
    }

    if(!strcmp(algorithm, "LRU") || !strcmp(algorithm, "lru"))          //kaloume ton algorithmo pou exei zhthuei
    {
        LruHandler(ipt,algorithm,frames,quantity,maxReferences,stats);
    }
    else if(!strcmp(algorithm, "SC") || !strcmp(algorithm, "sc"))
    {
        ScHandler(ipt,algorithm,frames,quantity,maxReferences,stats);
    }
    
    for (int i = 0; i < ipt->maxSize; i++)                          //frees
    {
        if (ipt->array[i] != NULL)
        {
            free(ipt->array[i]);
        }
        
    }
    
    free(stats);
    free(ipt->array);
    free(ipt);
    return 0;
}
