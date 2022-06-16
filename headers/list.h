#ifndef LIST
#define LIST

#include "InvertedPageTable.h"

typedef struct ListNode
{
    IptAddress data;
    struct ListNode* next;
    bool second_c;

}ListNode;
typedef ListNode* ListNodePtr;

typedef struct List
{
    int currSize;
    ListNodePtr head;
    ListNodePtr tail;
}List;
typedef List* ListPtr;

void InitializeList(ListPtr L);

int isListEmpty(ListPtr L);

void appendList(ListPtr L, IptAddress data);

IptAddressPtr PopList(ListPtr L);

void destroyList(ListPtr L, statistics* stats);

int CompareDataList(IptAddress data1, IptAddress data2);


#endif