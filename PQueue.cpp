#include "PQueue.h"
#include "Nod.h"
#include <iostream>
//constructor simplu, construieste o coada vida
PQueue::PQueue()
{
    start = end = NULL;
    size = 0;
}
//construieste o coada cu un singur element x, cu prioritatea p
PQueue::PQueue(int x, int p)
{
    start = end = new Nod(x, p, NULL);
	size = 1;
}
//constructor de copiere
PQueue::PQueue(PQueue& pq) {
	start = end = NULL;
	size = 0;
	Nod* p = pq.start;
	while (p != NULL) {
		insert(p->getInfo(), p->getPriority()   );
		p = p->getNext();
	}
}
//inserarea unui nou element x cu prioritatea pr in coada
void PQueue::insert(int x, int pr)
{
    if(start == NULL)
    {
        start = end = new Nod(x, pr, NULL);
        size = 1;
    }
    else
    {
        Nod* q = new Nod();
        Nod *p = new Nod(x, pr, NULL);
        if(start->getPriority() < pr)
        {
            p->setNext(start);
            start = p;
        }
        else
        {
            q = start;
            while (q->getNext() != NULL && q->getNext()->getPriority() >= pr)  //cautam unde sa inseram elementul in functie de prioritate
            q = q->getNext();                                                  //coada este descrescatoare, primul element are cea mai mare prioritate
            p->setNext(q->getNext());
            q->setNext(p);
        }
        size++;
    }
}
//afisarea valorilor (pt testare)
void PQueue::printValue()
{
    if(start == NULL) std::cout << "Coada vida (printValue)";
    else{
    Nod *p = start;
	while (p != NULL)
	{
		std::cout << p->getInfo() << " ";
		p = p->getNext();
	}
	std::cout << std::endl;
    }
}
//afisarea prioritatilor (pentru testare)
void PQueue::printPriority()
{
    if(start == NULL) std::cout << "Coada vida (printPriority)";
    else{
    Nod *p = start;
	while (p != NULL)
	{
		std::cout << p->getPriority() << " ";
		p = p->getNext();
	}
	std::cout << std::endl;
    }
}
// cel mai mare element din coada (dupa valoare)
int PQueue::getMax()
{
    int max = 0;
    if(start != NULL)
    {
        Nod* p = new Nod();
        p->setNext(start);
        while(p->getNext() != NULL)
        {
            p = p->getNext();
            if(max < p->getInfo()) max = p->getInfo();
        }

    }
    return max;

}
//cea mai mare prioritate din coada
int PQueue::getMaxPriority()
{
    if(size)
        return start->getPriority();
    std::cout<<"Coada vida (getMaxPriority)";
    return -1;
}
//numarul de elemente din coada
unsigned PQueue::length()
{
    if(start == NULL) return 0;
    return size;
}
// stergerea unui element (dupa pozitie) (nu este ilustrata in main, pt ca se foloseste la supraincarcarea operatorului --
void PQueue::remove(int i)
{
	if (i < 0 || i >= size)
	{
		return;
	}
	Nod* p = start;
	if (i == 0)
	{
		if (size <= 1)
		{
			start = end = NULL;
        }
        else
        {
            start = start->getNext();
            delete p;
        }
	}
	else
	{
		for (int j = 1; j < i; j++)
		{
			p = p->getNext();
        }
		Nod* q = p->getNext();
		p->setNext(q->getNext());
		delete q;
	}
	size--;
}
//supraincarcarea operatorului ++
PQueue& PQueue::operator++(int n)
{
    Nod* p = start;
    for(int i = 0; i < size; i ++)
    {
        p->setPriority(p->getPriority()+1);
        p = p->getNext();
    }
    return *this;
}
//supraincarcarea operatorului --
PQueue& operator --(PQueue& pq, int n)
{
    Nod* p = pq.start;
    for(int i = 0; i < pq.size; i ++)
    {
        if(p->getPriority() <= 1)   //eliminam daca prioritatea ajunge la 0 dupa decrementare
        {
            p = p->getNext();
            pq.remove(i);
            i-=1;
        }
        else
        {
            p->setPriority(p->getPriority()-1);
            p = p->getNext();
        }

    }
    return pq;
}
//supraincarcarea operatorului =
PQueue& PQueue::operator = (const PQueue &pq)
{
    if(this != &pq)
    {
        this->start = pq.start;
        this->end = pq.end;
        this->size = pq.size;
    }
    return *this;
}
//supraincarcarea operatorului << pentru afisare
ostream& operator<<(ostream& output, const PQueue& pq)
{
    Nod* p = pq.start;
    std::cout<<"perechile (info, prioritate) sunt: ";
    for(int i = 0; i < pq.size; i++)
    {
        if(i < pq.size-1)
            std::cout<<"("<<p->getInfo()<<","<<p->getPriority()<<"), ";
        else std::cout<<"("<<p->getInfo()<<","<<p->getPriority()<<")"<<std::endl;
        p = p->getNext();
    }
    return output;
}
//supraincarcarea operatorului >> pentru citire
istream& operator>>(istream& input, PQueue& pq)
{
    int x=0, p, c=1;
    std::cout<<"Introduceti perechile (info, prioritate). Oprirea se face la introducerea unei prioritati <= 0 "<<std::endl;
    while(p > 0)
    {
        std::cout<<"Nodul "<<c<<": ";
        std::cin>>x>>p;
        if(p > 0)
        pq.insert(x,p);
        c++;
    }
    std::cout<<std::endl;
    return input;
}
//supraincarcarea operatorului + pentru fuziunea a doua cozi (inseram ambele intr-o a treia)
PQueue PQueue :: operator+(const PQueue &pq) const
{
    PQueue w;
    Nod *p = pq.start;
    for(int i = 0; i < pq.size; i++)
    {
        w.insert(p->getInfo(), p->getPriority());
        p = p->getNext();
    }

    p = this->start;
    for(int i = 0; i < this->size; i++)
    {
        w.insert(p->getInfo(), p->getPriority());
        p = p->getNext();
    }
    return w;

}
//destructor
PQueue::~PQueue()
{
    Nod* p = start;
    Nod* q;
	while (p != NULL) {
		q = p;
		p = p->getNext();
		delete q;
	}
	start = end = NULL;
	size = 0;
}
