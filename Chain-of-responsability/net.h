#include <iostream>
#include <string>
#include "dns.h"

class net: public dns
{
private:
	std::string address[5] = { "www.hola.net", "www.adios.net", "www.como.net", "www.estas.net", "www.bien.net" };
	std::string ip[5] = {"10.4.124.12", "10.4.0.255", "35.65.32.122", "120.1.19.189", "167.145.127.12"};
public:
	net() {}
	void search(std::string dir);
	std::string getName() { return "net"; }
};

void net::search(std::string dir)
{
	bool found = false;
	for(int i = 0; i < ( sizeof(address)/sizeof(address[0]) ); i++)
	{
		if(dir == address[i])
		{
			std::cout<<"Address was found in domain net with the ip: "<< ip[i] <<std::endl;
			found = true;
		}
	}
	if(!found)
		std::cout<<"Couldn't find the address entered in this DNS Server."<<std::endl;
}
