#ifndef FACHNOTE_H
#define FACHNOTE_H

class fachnoten_liste final{

    public:
        using delete_func = void(*)(fachnote*);
        fachnoten_liste(delete_func del);
        node head;

    private:
        class node;
        delete_func deleter;

}

#endif