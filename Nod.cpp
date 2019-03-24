#include "Nod.h"

Nod::Nod()
{
	info = 0;
	priority = 0;
	next = NULL;
}

Nod::Nod(int i, int p, Nod* n) {
	info = i;
	next = n;
	priority = p;
}

void Nod::setInfo(int i) {
	info = i;
}

void Nod::setPriority(int p) {
	priority = p;
}

void Nod::setNext(Nod* n) {
	next = n;
}

int Nod::getInfo() {
	return info;
}

int Nod::getPriority() {
	return priority;
}

Nod* Nod::getNext() {
	return next;
}

Nod::~Nod()
{

}
