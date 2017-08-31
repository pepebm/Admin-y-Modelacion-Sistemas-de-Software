#include "A01021716-Act2.h"

int main () 
{
	std::string ans;
	Computadora* n = desktop::newDesktop()->clonar();

	cout<<"Que desea pedir?"<<endl;
	cin>>ans;

	
	Computadora * compu = concreteCreator::instancia()->crearCompu(ans);
	return 0;
}