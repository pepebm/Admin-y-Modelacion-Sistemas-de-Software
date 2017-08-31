/*
	Ivan Aram Gonzalez Su A01022584
	Jose Manuel Beauregard Mendez A01021716
	Angel Ivan Tellez
*/
#include <iostream>
#include "Clase.h"
#include "Ing.h"
#include "Lic.h"

int main(){
	Clase sistemasSoftware("Sistemas de Software");
	Ing ivan(&sistemasSoftware,"Ivan");
	Ing pepe(&sistemasSoftware,"Pepe");
	Lic Marko(&sistemasSoftware, "Marko");
	sistemasSoftware.setTarea(1);
} 