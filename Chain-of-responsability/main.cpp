#include <iostream>
#include "dns.h"
#include "com.h"
#include "mx.h"
#include "net.h"
#include "org.h"

int main()
{
	dns *root = new com();
	dns *c = new com();
	dns *n = new net();
	dns *o = new org();
	dns *m = new mx();

	root->add(c);
	root->add(o);
	root->add(n);
	root->add(m);

	int op;
	std::string dir;

	while(true)
	{
		std::cout<<"-------------------------------------------------------------"<<std::endl;
		std::cout<<"Choose an option"<<std::endl;
		std::cout<<"\t1. Get the ip of a website inside this DNS server."<<std::endl;
		std::cout<<"\t2. Exit" << std::endl;
		std::cin>>op;
		if(op == 1)
		{
			std::cout<<"Enter the website: (www.something.something) ";
			std::cin>>dir;
			root->chain(dir);
		}
		else if(op == 2)
			break;
		else
			std::cout<<"Invalid option"<<std::endl;
	}
	return 0;
}
