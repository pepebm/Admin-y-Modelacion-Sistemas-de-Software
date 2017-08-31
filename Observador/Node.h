#pragma once

template <class T>
class Node{
private:
    T data;
    Node* next = nullptr;
public:
    Node(){}
    Node(T _data):data(_data){}
    ~Node();
    void setData(T _data){ data = _data; }
    T getData(){ return data; }
    void setNext(Node* _next){ next = _next; }
    Node* getNext(){ return next; }
};

template <class T>
Node<T>::~Node(){
    next = nullptr;
}