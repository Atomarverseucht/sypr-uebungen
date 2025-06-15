#ifndef FACHNOTE_H
#define FACHNOTE_H

class fachnoten_liste final{

    public:
        using delete_func = void(*)(fachnote*);
        fachnoten_liste(delete_func del);
        node head;

        // illegale Argumente
        fachnoten_liste(const fachnoten_liste & ) = delete;
        fachnoten_liste &operator=(const fachnoten_liste &) = delete;
        fachnoten_liste(fachnoten_liste &&) = delete;
        fachnoten_liste &operator=(fachnoten_liste &&) = delete;

    private:
        class node;
        delete_func deleter;

}

#endif