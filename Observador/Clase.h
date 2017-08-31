/*
	Ivan Aram Gonzalez Su A01022584
	Jose Manuel Beauregard Mendez A01021716
	Angel Ivan Tellez
*/
#pragma once 
#include "Alumno.h"
#include "LinkedList.h"
#include <iostream>

class Clase {
private:
	Clase(){}
	std::string clase;
	int tarea;
	LinkedList<Alumno*> students;  
public:
	Clase(std::string c) : tarea(0), clase(c) {}
	void addAlumno(Alumno* student){ students.insertTail(student); }
	void setTarea(int);
	void notify();
};

void Clase::setTarea(int num){
	tarea = num;
	notify();
}

void Clase::notify(){
	for(int i = 0; i < students.getLength(); i++){
		students.at(i)->getData()->update(tarea);
		std::cout << " de la clase " << clase << "." << std::endl;
	}
}