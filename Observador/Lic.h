/*
	Ivan Aram Gonzalez Su A01022584
	Jose Manuel Beauregard Mendez A01021716
	Angel Ivan Tellez
*/
#pragma once
#include "Alumno.h"
#include "Clase.h"
#include <iostream>

class Lic : public Alumno{
private:
	Lic(){}
	std::string name;
public:
	Lic(Clase* clase, std::string _name) : name(_name) { clase->addAlumno(this); }
	void update(int num){ std::cout << name << " fue notificado de la tarea " << num; }
};