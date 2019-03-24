#ifndef PQUEUE_H_INCLUDED
#define PQUEUE_H_INCLUDED
#include "Nod.h"
using namespace std;
class PQueue
{
    private:
        Nod *start, *end;
        unsigned size;
    public:
        PQueue();
        PQueue(int, int);
        PQueue(PQueue&);
        void insert(int, int);
        void printValue();
        void printPriority();
        int getMax();
        int getMaxPriority();
        unsigned length();
        void remove(int);
        PQueue &operator++(int);
        friend PQueue &operator--(PQueue&, int);
        PQueue& operator = (const PQueue&);
        friend ostream &operator<<(ostream& output, const PQueue& pq);
        friend istream &operator>>(istream& input, const PQueue& pq);
        PQueue operator+(const PQueue&) const;
        ~PQueue();
};


#endif // PQUEUE_H_INCLUDED
