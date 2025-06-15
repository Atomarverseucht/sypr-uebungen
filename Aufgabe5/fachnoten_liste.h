#ifndef FACHNOTE_H
#define FACHNOTE_H

#include "fachnote.h"

class fachnoten_liste final{
    using delete_func = void(*)(fachnote*);
    private:
        class node;
        delete_func deleter;
    public:
        
        fachnoten_liste(delete_func del);
        ~fachnoten_liste();
        node head;

        // illegale Argumente
        fachnoten_liste(const fachnoten_liste & ) = delete;
        fachnoten_liste &operator=(const fachnoten_liste &) = delete;
        fachnoten_liste(fachnoten_liste &&) = delete;
        fachnoten_liste &operator=(fachnoten_liste &&) = delete;

    

};

#endif