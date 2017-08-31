#include<iostream>
using namespace std;

class ArrayPositiveInts;

class Proxy
{
private:
    ArrayPositiveInts& arr;
    int idx;

public:
    Proxy(ArrayPositiveInts& arr, int idx)
    : arr(arr), idx(idx){}

    Proxy& operator=(int value);
};

class ArrayPositiveInts
{
private:
    int* values;
    int size;
public:
    friend class Proxy;
    ArrayPositiveInts()
    {
        size = 100;
        values = new int[size];
    }
    Proxy operator[](int idx) //se devuelve un elemento del arreglo por referencia
    {
        return Proxy(*this, idx); //ejecuto el proxy

    }
    int get(int pos)
    {
        return values[pos];
    }
};

Proxy& Proxy::operator=(int value)
{
        if(value>=0)
        {
            *(arr.values + idx) = value;
            return *this;
        }
        else
        {
            cout << "error" << endl;
            return *this;
        }
}

int main()
{
    ArrayPositiveInts a;
    a[0]=-1;
    a[0] = 1;
    cout << a.get(0) << endl;
}
