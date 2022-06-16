#include "../headers/queue.h"

void InitializePQ(PQPtr Q)
{
    Q->currSize = 0;
    Q->head = NULL;
    Q->tail = NULL;

}

int isPQEmpty(PQPtr Q)
{
    return Q->currSize;

}

int PushPQ(PQPtr Q, IptAddress data)
{
    nodePtr tmpNode;

    if((tmpNode = malloc(sizeof(node))) == NULL)
    {
        perror("cant malloc node");
        return -1;

    }
    
    tmpNode->data = data;
    tmpNode->next = NULL;
    
    if(Q->currSize)
    {
        Q->tail->next = tmpNode;
        Q->tail = tmpNode;
    }
    else
    {
        Q->head = tmpNode;
        Q->tail = tmpNode;
    }

    Q->currSize++;
    
    return 0;
}


IptAddressPtr PopPQ(PQPtr Q)
{
    nodePtr tmpNode = Q->head;
    IptAddressPtr data = malloc(sizeof(IptAddress));

    data->isDirty = tmpNode->data.isDirty;
    data->page = tmpNode->data.page;
    data->pid = tmpNode->data.pid;

    if(Q->currSize !=0)
    {
        if(Q->currSize == 1)
        {
            Q->head = NULL;
            Q->tail = NULL;
        }
        else
        {
            Q->head = Q->head->next;
        }
    }
    Q->currSize--;
    free(tmpNode);

    return data;
}

void destroyPQ(PQPtr Q, statistics* stats)
{
    IptAddressPtr tmp;
    for (int i = 0; i < Q->currSize + 10; i++)
    {
        tmp = PopPQ(Q);
        if(tmp->isDirty)
        {
            stats->writes++;
        }
        free(tmp);
    }
    

}

void givePriority(PQPtr Q,IptAddress data)
{
    nodePtr fastPtr, slowPtr;
    fastPtr = Q->head;
    if(fastPtr != NULL)
    {
        while(CompareData(fastPtr->data,data) && fastPtr->next != NULL)
        {
            slowPtr = fastPtr;
            fastPtr = fastPtr->next;
        }
        if(fastPtr == Q->head)
        {
            Q->head = Q->head->next;
        }
        else if (fastPtr->next == NULL)  //it is already in tail
        {
            return;
        }
        else
        {
            slowPtr->next = fastPtr->next;
        }
        Q->tail->next = fastPtr;
        Q->tail =fastPtr;
        fastPtr->next = NULL;
        
    }

}

int CompareData(IptAddress data1, IptAddress data2)
{
    if(data1.page == data2.page && data1.isDirty == data2.isDirty && data1.pid == data2.pid)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    

}
