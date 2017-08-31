#include <iostream>

using namespace std;

class Computadora
{
public:
	virtual void impresionConsola() = 0;
	virtual Computadora* clonar() = 0;
	
};

template <class Computadora, class SubClase>
class clon : public Computadora
{
public:
	using Computadora::Computadora;

	virtual Computadora* clonar()
	{
		return new SubClase(dynamic_cast<SubClase&>(*this));
	}
};

class desktop : public clon<Computadora, desktop>
{
private:
	desktop() {}
public:
	static desktop * newDesktop()
	{
		return new desktop;
	}
	void impresionConsola()
	{
		cout << "Seleccionando los compenentes para la desktop" << endl;
		cout << "Ensamblado los componentes." << endl;
		cout << "Insatalndo y configurado los softwares" << endl;
		cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
	}
};

class laptop : public clon<Computadora, laptop>
{
private:
	laptop() {}
public:
	static laptop * newLaptop()
	{
		return new laptop;
	}
	void impresionConsola()
	{
		cout << "Seleccionando los compenentes para la laptop" << endl;
		cout << "Ensamblado los componentes." << endl;
		cout << "Insatalndo y configurado los softwares" << endl;
		cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
	}
};

class tablet : public clon<Computadora, tablet>
{
private:
	tablet() {}
public:
	static tablet * newTablet()
	{
		return new tablet;
	}
	void impresionConsola()
	{
		cout << "Seleccionando los compenentes para la tablet" << endl;
		cout << "Ensamblado los componentes." << endl;
		cout << "Insatalndo y configurado los softwares" << endl;
		cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
	}
};

class notebook : public clon<Computadora, notebook>
{
private:
	notebook() {}
public:
	static notebook * newNotebook()
	{
		return new notebook;
	} 
	void impresionConsola()
	{
		cout << "Seleccionando los compenentes para la notebook" << endl;
		cout << "Ensamblado los componentes." << endl;
		cout << "Insatalndo y configurado los softwares" << endl;
		cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
	}
};

//------------------------------------------

class creator
{
public:
	virtual Computadora * factoryMethod(std::string) = 0;

	Computadora * crearCompu(std::string ans)
	{
		Computadora* miCompu = factoryMethod(ans);
		miCompu->impresionConsola();
		return miCompu;
	}
	
};

class concreteCreator : public creator
{
private:
	concreteCreator() {}
	static concreteCreator * singelton;
public:
	static concreteCreator *  instancia()
	{
		if(!singelton)
			singelton = new concreteCreator;
		return singelton;
	}

	Computadora * factoryMethod(std::string ans)
	{
		if (ans == "desktop")
			return desktop::newDesktop();
		else if (ans == "laptop")
			return laptop::newLaptop();
		else if (ans == "notebook")
			return notebook::newNotebook();
		else if (ans == "tablet")
			return tablet::newTablet();
	}
};

concreteCreator * concreteCreator::singelton = 0;

//-------------------------------------


