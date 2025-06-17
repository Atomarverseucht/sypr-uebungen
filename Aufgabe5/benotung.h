#ifndef BENOTUNG_H
#define BENOTUNG_H


class benotung final{
    private:
        int note;

    public:
        static const benotung beste;
        static const benotung schlechteste;
        benotung(int note);
        int int_value() const;
        bool ist_bestanden() const;
    
    friend bool operator==(const benotung b1, const benotung b2);
};

#endif