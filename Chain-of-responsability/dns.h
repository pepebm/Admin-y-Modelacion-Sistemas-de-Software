#pragma once
#include <iostream>
#include <string>


class dns
{
private:
	dns *next;
public:
	dns() { next = 0; }

	//void setNext(dns *n) { next = n; }
	void add(dns *n){
		if(next)
			next->add(n);
		else
			next = n;
	}

	virtual std::string getName() = 0;
	virtual void search(std::string dir) = 0;
	void chain(std::string dir)
	{
		if(next == nullptr)
			return;

		std::string domain;

		for(int i = dir.length()-1; i >= 0; i--)
		{
			if(dir[i] == '.')
			{
				domain = dir.substr(i+1, dir.length());
				break;
			}
		}
		if(domain == next->getName())
			next->search(dir);

		next->chain(dir);
	}
};
