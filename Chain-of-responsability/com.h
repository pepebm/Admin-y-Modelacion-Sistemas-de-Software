#include <iostream>
#include <string>
#include "dns.h"

class com : public dns
{
private:
	std::string address[5] = { "www.google.com", "www.facebook.com", "www.pinterest.com", "www.cplusplus.com", "www.netflix.com" };
	std::string ip[5] = {"8.8.8.8", "10.4.123.257", "35.87.90.29", "120.0.9.89", "67.45.127.1"};
public:
	com(){}
	void search(std::string dir);
	std::string getName() { return "com" ;}
};

void com::search(std::string dir)
{
	bool found = false;
	for(int i = 0; i < ( sizeof(address)/sizeof(address[0]) ); i++)
	{
		if(dir == address[i])
			std::cout<<"Address was found in domain com with the ip: "<< ip[i] <<std::endl;
	}
	if(!found)
		std::cout<<"Couldn't find the address entered in this DNS Server."<<std::endl;
}
