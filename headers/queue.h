#ifndef QUEUE
#define QUEUE

#include "InvertedPageTable.h"

typedef struct node
{
    IptAddress data;
    struct node* next;

}node;
typedef node* nodePtr;

typedef struct PriorityQueue{
    int currSize;
    nodePtr head;
    nodePtr tail;

}PQ;
typedef PQ* PQPtr;

void InitializePQ(PQPtr Q);

int isPQEmpty(PQPtr Q);

int PushPQ(PQPtr Q, IptAddress data);

IptAddressPtr PopPQ(PQPtr Q);

void destroyPQ(PQPtr Q, statistics* stats);

void givePriority(PQPtr Q,IptAddress data);

int CompareData(IptAddress data1, IptAddress data2);

#endif
