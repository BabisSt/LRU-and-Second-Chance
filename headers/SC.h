#ifndef SC_h
#define SC_h


#include "InvertedPageTable.h"
#include "list.h"

int ScHandler(IptPtr ipt, char* algorithm, int frames, int quantity, int maxReferences, statistics* stats);

int runSC(IptPtr ipt, IptAddressPtr address, ListPtr Q, statistics* stats);

#endif