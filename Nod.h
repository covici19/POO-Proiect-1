#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED

class Nod
{
    private:
        int info, priority;
        Nod* next;

    public:
        Nod();
        Nod(int, int, Nod*);
        void setInfo(int);
        void setPriority(int);
        void setNext(Nod*);
        int getInfo();
        int getPriority();
        Nod* getNext();
        virtual ~Nod();

    friend class PQueue;

};

#endif // NOD_H_INCLUDED
