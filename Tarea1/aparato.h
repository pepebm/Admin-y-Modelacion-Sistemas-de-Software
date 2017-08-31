// Jose Manuel Beauregard Mendez A01021716

#include <iostream>
#include <string>

using namespace std;

class aparato
{
public:
	aparato(){};
	~aparato(){};

	int crear(string ans);

private:
	int tipo;

	void desktop();
	void laptop();
	void netbook();
	void tablet();
};

int aparato::crear(string ans)
{
	if (ans == "desktop")
		desktop();
	else if (ans == "laptop")
		laptop();
	else if (ans == "netbook")
		netbook();
	else if (ans == "tablet")
		tablet();
	else
		cout << "No tenemos lo que estas buscando, lo sentimos.";

	return;
}

void aparato::desktop()
{
	cout << "Seleccionando los compenentes para la desktop" << endl;
	cout << "Ensamblado los componentes." << endl;
	cout << "Insatalndo y configurado los softwares" << endl;
	cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
}

void aparato::laptop()
{
	cout << "Seleccionando los compenentes para la laptop" << endl;
	cout << "Ensamblado los componentes." << endl;
	cout << "Insatalndo y configurado los softwares" << endl;
	cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
}

void aparato::netbook()
{
	cout << "Seleccionando los compenentes para la netbook" << endl;
	cout << "Ensamblado los componentes." << endl;
	cout << "Insatalndo y configurado los softwares" << endl;
	cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
}

void aparato::tablet()
{
	cout << "Seleccionando los compenentes para la tablet" << endl;
	cout << "Ensamblado los componentes." << endl;
	cout << "Insatalndo y configurado los softwares" << endl;
	cout << "Empaquetando y puliendo detalles. Gracias!" << endl;
}