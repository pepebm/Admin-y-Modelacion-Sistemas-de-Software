#include "Persona.h"
#include "Iterator.h"
#include "Aggregate.h"

int main (int argc, const char *argv[])
{
	Persona p1(20);
	Persona p2(30);
	Aggregate<Persona> lista;
	lista.add(p1);
	lista.add(p2);

	for(Iterator<Persona> i = lista.getIterator(); i.hasNext(); )
		cout << i.next();

	
	return 0;
}