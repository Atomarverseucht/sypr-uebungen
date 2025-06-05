#ifndef BENOTUNG_H
#define BENOTUNG_H

class benotung final{
    private:
        int note;

    public:
        static const benotung beste;
        static const benotung schlechteste;
        benotung(int note);
        int int_value();
        bool ist_bestanden();
    
    friend bool operator==(benotung b1, benotung b2);
}

#endif