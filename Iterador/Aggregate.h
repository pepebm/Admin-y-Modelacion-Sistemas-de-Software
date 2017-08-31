#include <iostream>


template <class T>
class Iterator;

template <class T>
class Aggregate
{
	friend class Iterator<T>;


	Aggregate() :  lista(new T[size]), pos(0) {}
	~Aggregate()
	{
		delete [] lista;
	}

	void add(T element)
	{
		//validar que hay espacio
		lista[pos++] = element;
	}

	Iterador<T> getIterator()
	{
		return new Iterator<T> (*this);
	}
	
	T getElementAt(int pos)
	{
		return lista[pos];
	}

private:
	T* lista;
	int size = 10;
	int pos;
	virtual void addPersona(T persona);
	virtual bool findPersona(T persona);
	virtual void deletePersona(T persona);
	virtual int maxSize();
	virtual int currentElements();
	
};