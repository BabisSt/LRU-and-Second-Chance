#include "../headers/list.h"

void InitializeList(ListPtr L)
{
    L->currSize =0;
    L->head = NULL;
    L->tail = NULL;

}

int isListEmpty(ListPtr L)
{
    return L->currSize;

}

void appendList(ListPtr L, IptAddress data)
{
    ListNodePtr new_node ;
    if((new_node = malloc(sizeof(ListNode))) == NULL)
    {
        perror("cant malloc node");
        return;

    }
    // if(CompareDataList(L->head->data,new_node->data) == 0)
    // {
    //     new_node->second_c = 1;
    // }
    new_node->data = data;
    new_node->next = NULL;
    if(L->currSize)
    {
        L->tail->next =new_node;
        L->tail = new_node;
    }
    else
    {
        L->head = new_node;
        L->tail = new_node;
    }
   
    L->currSize++;

}

IptAddressPtr PopList(ListPtr L)
{
    if(L->head == NULL)
    {
        return NULL;
    }
    ListNodePtr tmpNode = L->head;
    IptAddressPtr data = malloc(sizeof(IptAddress));
    data->isDirty = tmpNode->data.isDirty;
    data->page = tmpNode->data.page;
    data->pid = tmpNode->data.pid;


   
    if(L->currSize !=0)
    {
        if(L->currSize ==1)
        {
            L->head=NULL;
            L->tail=NULL;
        }
        else
        {
            while (L->head->next != NULL)
            {
                if(L->head->second_c == 1)
                {
                    L->head->second_c = 0;
                    L->head->next = L->head;
                    L->head = L->tail->next;

                }
                else
                {
                    L->head = L->tail->next;
                }
            }
        }
    }
    L->currSize--;
    free(tmpNode);

    return data;

}

void destroyList(ListPtr L, statistics* stats)
{
    IptAddressPtr tmp;
    for (int i = 0; i < L->currSize + 10; i++)
    {
        tmp = PopList(L);
        if(tmp->isDirty)
        {
            stats->writes++;
        }
        free(tmp);
    }

}


int CompareDataList(IptAddress data1, IptAddress data2)
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