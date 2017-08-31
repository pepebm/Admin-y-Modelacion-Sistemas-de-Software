/*
	Ivan Aram Gonzalez Su A01022584
	Jose Manuel Beauregard Mendez A01021716
	Angel Ivan Tellez
*/
#pragma once 
#include "Alumno.h"
#include "Clase.h"
#include <iostream>

class Ing : public Alumno{
private:
	Ing(){}
	std::string name;
public:
	Ing(Clase* clase, std::string _name) : name(_name) { clase->addAlumno(this); }
	void update(int num){ std::cout << name << " fue notificado de la tarea " << num; }
};