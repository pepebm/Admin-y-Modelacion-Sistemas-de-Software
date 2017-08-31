#include <iostream>

template <class T>
class Aggregate;

template <class T>
class Iterador
{
public:
	Iterator (const Aggregate<T>& lista)
	{
		this->lista = lista;
		index = 0;
	}
	~Iterator()
	{
		delete [] lista;
	}

	T next()
	{
		if(hasNext())
			return lista->getElementAt(index++);
			// return lista->lista[index++]; si se utiliza con friend
		else
			// return *(new T);
			return NULL;
	}

	bool hasNext() { return index < lista->getSize(); }
protected:
	Iterator() {}
	int index;
	int size = 10;
	T first();
	Aggregate<T>* lista;
	
	T isDone();
	T currentItem();
};

