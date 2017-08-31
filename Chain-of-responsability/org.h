#include <iostream>
#include <string>
#include "dns.h"

class org: public dns
{
private:
	std::string address[5] = { "www.perro.org", "www.gato.org", "www.oso.org", "www.lobo.org", "www.caballo.org" };
	std::string ip[5] = {"190.89.2.3", "120.45.12.27", "135.8.190.29", "120.100.19.89", "167.145.127.11"};
public:
	org() {}
	void search(std::string dir);
	std::string getName() { return "org"; }
};

void org::search(std::string dir)
{
	bool found = false;
	for(int i = 0; i < ( sizeof(address)/sizeof(address[0]) ); i++)
	{
		if(dir == address[i])
		{
			std::cout<<"Address was found in domain org with the ip: "<< ip[i] <<std::endl;
			found = true;
		}
	}
	if(!found)
		std::cout<<"Couldn't find the address entered in this DNS Server."<<std::endl;
}
