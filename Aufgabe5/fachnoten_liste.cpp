#include "fachnoten_liste.h"

class fachnoten_liste::node{
    public:
        const fachnote* value;
        node* next;
        ~node(){
            
        }
}

fachnoten_liste::fachnoten_liste(delete_func del): deleter(del)
{

}



