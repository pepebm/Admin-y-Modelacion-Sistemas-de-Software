#include <iostream>

class Persona{
public:
	Persona(int edad) : edad(edad) {}
	int getEdad() {return edad;}

	Persona () {}

private: 
	int edad;
};