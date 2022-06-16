# LRU and Second Chance Algorithms

For the lru algorithm: <br/><br/>

In the beginning, the inverted page table is bound and as long as there is space, the traces are stored as structs while copies of the addresses are stored in priority queue.
In case an address exists in the page table then it acquires priority.
If the page table is full then we pop the address with the lowest priority and in its place the new address.<br/>

For the sc algorithm:<br/><br/>

I have not made the algorithm work properly however it uses simple linked list. And if the entry already exists then it renews the second_c to one while if there is no space the pop searches the whole list and if a node has 1 in the second_c then it does 0 otherwise it pops it.<br/><br/><br/>


ΕΡΓΑΣΙΑ 2Η ΛΕΙΤΟΥΡΓΙΚΑ ΣΥΣΤΗΜΑΤΑ 2020
Στεβής Χαράλαμπος-Αντώνιος ΑΜ: 1115201600278

Περιεχόμενο εργασίας:
Ένας φάκελος Assets που περιέχει:
       Tα αρχεία που δώθηκαν
            bzip.trace
            bzip.trace.gz
            gcc.trace
            gcc.trace.gz

Ένας φάκελος bin που περιέχει:
        Το εκτελέσιμο runner

Ένας φάκελος build που περιέχει:
        Όλα τα .ο αρχεία

Ένας φάκελος headers που περιέχει:
        Όλα τα .h αρχεία
            InvertedPageTable.h
            list.h
            LRU.h
            queue.h
            SC.h
            Simulator.h
Ένας φάκελος src που περιέχει:
        Όλα τα .c αρχεία
            InvertedPageTable.c
            list.c
            LRU.c
            main.c
            queue.c
            SC.c
            Simulator.c
Makefile
README

Πως τρέχουμε το πρόγραμμα:

Το πρόγραμμα μεταγλωτίζεται με την εντολή make και εκτελείται με την εντολή make run είτε με την εντολή make valgrind ,αν επιθυμείτε εκτέλεση με valgrind, με τα default ορίσματα που δίνονται στο makefile ( lru ).Τα ορίσματα είναι τα εξής:
-f + αριθμός για τα frames, -q + αριθμός για το quantity δηλαδή ανά πόσες εγγραφές θα διαβάζει εναλλαξ από τα αρχεία, -m + αριθμός για το maxReferences δηλαδή τον μέγιστο αριθμό των εγγραφων από τα αρχεία, -a για τον αλγόριθμο.

Για τον αλγόριθμο lru:

Στην αρχή δεσμεύεται το inverted page table και όσο υπάρχει χώρος αποθηκεύονται τα traces σαν structs ενώ αντίγραφα των διευθύνσεων αποθηκεύονται σε priority queue.
Σε περίπτωση που μια διεύθυνση υπάρχει στον page table τότε αποκτάει προτεραιότητα.
Αν το page table είναι γεμάτο τότε κάνουμε pop την διεύθυνση με το χαμηλότερο priority και στην θέση του βάζουμη την νέα διεύθυνση.

Για τον αλγόριθμο sc:

Δεν έχω κάνει τον αλγόριθμο να λειτουργεί σωστά ωστόσο χρησιμοποιεί simple linked list. Και αν η εγγραφή υπάρχει ήδη τότε ανανεώνει το second_c σε ένα ενώ άν δεν υπάρχει χώρος το pop ψάχνει σε όλη την λίστα και αν ένας κόμβος έχει 1 στο second_c τότε το κάνει 0 αλλιώς τον κάνει pop.

Το αρχείο Simulator κάνει τις κατάλληλες αρχικοποιήσεις και καλεί τον αλγόριθμο σύμφωνα με τα ορίσματα που δώθηκαν.

H main διαβάζει τα ορίσματα που δώθηκαν και καλεί τον simulator

