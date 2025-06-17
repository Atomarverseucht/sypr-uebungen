#ifndef FACHNOTENLISTE_H
#define FACHNOTENLISTE_H

#include "fachnote.h"
using delete_func = void(*)(fachnote*);

class fachnoten_liste final{
    
    private:
        class node;
        delete_func deleter;
        node* head;
    public:
        
        fachnoten_liste(delete_func del);
        ~fachnoten_liste();

        // illegale Argumente
        fachnoten_liste(const fachnoten_liste & ) = delete;
        fachnoten_liste &operator=(const fachnoten_liste &) = delete;
        fachnoten_liste(fachnoten_liste &&) = delete;
        fachnoten_liste &operator=(fachnoten_liste &&) = delete;
        
        fachnoten_liste& insert(fachnote*);
   
        class iterator final
        {
            private:
                node *current;
                explicit iterator(node*);
            public:
                bool operator!=(const iterator&) const;
                fachnote*& operator*() const;
                iterator& operator++();
    
           friend class fachnoten_liste;
      };
   
       iterator begin();
       iterator end();
    

};

#endif