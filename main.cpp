#include <iostream>
#include "Nod.h"
#include "PQueue.h"
#include "Nod.cpp"
#include "PQueue.cpp"
using namespace std;

int main()
{
    PQueue a,b;
    cout<<"Prima coada: "<<endl;
    cin>>a;
    cout<<a<<'\n';
    cout<<"Lungimea este "<<a.length()<<endl;
    cout<<"Elementul maxim din coada (ca valoare) este "<<a.getMax()<<endl;
    cout<<"Valorea prioritatii maxime din coada este "<<a.getMaxPriority()<<endl;
    a.insert(9,1);
    cout<<"Dupa inserare "<<a<<endl;
    a--;
    cout<<"Dupa decrementare "<<a<<endl;
    a++;
    cout<<"Dupa incrementare "<<a<<endl;
    cout<<"A doua coada: "<<endl;
    cin>>b;
    cout<<"Dupa fuziune "<<a+b<<endl;
    cin.get();
    return 0;
}
