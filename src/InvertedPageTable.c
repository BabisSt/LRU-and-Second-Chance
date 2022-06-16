#include "../headers/InvertedPageTable.h"
#include "../headers/queue.h"

void fillAddress(IptAddressPtr address, char* line)             //kommatiasma address kai apothkeush ths
{
    char* hexNum;
    char* operation;
    
    hexNum = strtok(line, " ");
    operation =strtok (NULL, "\n");
    address->page = strtoul(hexNum, NULL, 16)/ FRAME_SIZE;

    if(!strcmp(operation,"R"))
    {
        address->isDirty = false;
    }
    else
    {
        address->isDirty = true;
    }
    
}

IptAddressPtr addressInIpt(IptPtr ipt, IptAddressPtr address)       //elenxei an einai h address sto ipt
{
    for (int i = 0; i < ipt->maxSize; i++)
    {
        if(ipt->array[i] != NULL)
        {
            if(ipt->array[i]->isDirty == address->isDirty && ipt->array[i]->page == address->page && ipt->array[i]->pid == address->pid )
            {

                return address;
            }
        }
    }
    return NULL;
    
}

void insertAtFreeSpace(IptPtr ipt, IptAddressPtr address)       //eisagwgh ston free xwro
{
    for (int i = 0; i < ipt->maxSize; i++)
    {
        if(ipt->array[i] == NULL)
        {
            ipt->array[i] = address;
            return;
        }
    }
    
}

void removeIpt(IptPtr ipt, IptAddressPtr address)               //diagrafh address
{
    for (int i = 0; i < ipt->maxSize; i++)
    {
        if(ipt->array[i]->isDirty == address->isDirty && ipt->array[i]->page == address->page && ipt->array[i]->pid == address->pid )
        {
            
            free(ipt->array[i]);
            ipt->array[i] = NULL;
            ipt->currSize--;
           
            
        }

    }
    

}

void setWrite(IptPtr ipt, IptAddressPtr address)            //grapsimo ths dirty selidas ston disko
{
    for (int i = 0; i < ipt->currSize; i++)
    {
        if(!CompareData(*(ipt->array[i]), *address))
        {
            ipt->array[i]->isDirty = true;
            break;
        }
    }
    
}