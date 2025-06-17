/*
 * fachnoten_liste.cpp
 *
 * Author Tom Bonsiep
 * Erstellt am: 17.06.2025
 * Zuletzt geändert: 17.06.2025
 */

#include "fachnoten_liste.h"

class fachnoten_liste::node final
{
    node *next;
    fachnote *n;

    node(node *e, fachnote *m) : next(e), n(m) {}

    friend class fachnoten_liste;
    friend class fachnoten_liste::iterator;
};

// Iterator-Funktionen
fachnoten_liste::iterator::iterator(node *e) : current(e) {}

bool fachnoten_liste::iterator::operator!=(const iterator &i) const
{
    return this->current != i.current;
}

fachnote *&fachnoten_liste::iterator::operator*() const
{
    return this->current->n;
}

fachnoten_liste::iterator &fachnoten_liste::iterator::operator++()
{
    this->current = this->current->next;
    return *this;
}

// fachnotenliste-Funktionen
fachnoten_liste::fachnoten_liste(delete_func deleter) : deleter(deleter), head(nullptr)
{

}

fachnoten_liste::~fachnoten_liste()
{
    node* n = head;
    while (n)
    {
        node* nd = n;
        n = n->next;
        deleter(nd->n);
        delete nd;
    }
}

fachnoten_liste &fachnoten_liste::insert(fachnote *n)
{
    this->head = new node(this->head, n);
    return *this;
}

fachnoten_liste::iterator fachnoten_liste::begin()
{
    return fachnoten_liste::iterator(this->head);
}

fachnoten_liste::iterator fachnoten_liste::end()
{
    return fachnoten_liste::iterator(nullptr);
}

