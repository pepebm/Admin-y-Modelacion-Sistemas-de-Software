#include <iostream>
#include <string>
#include "dns.h"

class mx: public dns
{
private:
	std::string address[5] = { "www.cdmx.mx", "www.tabasco.mx", "www.puebla.mx", "www.oaxaca.mx", "www.leon.mx" };
	std::string ip[5] = {"127.0.23.4", "59.4.2.12", "135.87.190.29", "99.99.99.99", "34.12.4.127"};
public:
	mx() {}
	void search(std::string dir);
	std::string getName() { return "mx";}
};

void mx::search(std::string dir)
{
	bool found = false;
	for(int i = 0; i < ( sizeof(address)/sizeof(address[0]) ); i++)
	{
		if(dir == address[i])
		{
			std::cout<<"Address was found in domain mx with the ip: "<< ip[i] <<std::endl;
			found = true;
		}
	}
	if(!found)
		std::cout<<"Couldn't find the address entered in this DNS Server."<<std::endl;
}
