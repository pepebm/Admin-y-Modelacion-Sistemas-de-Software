#pragma once

#include "Node.h"

template <class T>
class LinkedList{
protected:
    Node<T>* head = nullptr;
    int length = 0;
    void print_recursive(Node<T>* _head,int c);
    int search_recursive(Node<T>* element,T data,int c);
public:
    //Constructors and Destructor
    LinkedList(){}
    LinkedList(Node<T>* first):head(first){ length++; }
    ~LinkedList();
    
    //Insertion
    void insertHead(Node<T>* new_node);
    void insertHead(T data);
    void insertTail(Node<T>* new_node);
    void insertTail(T data);
    void insertAtPos(Node<T>* new_node, int pos);
    void insertAtPos(T data, int pos);
    void insertOrdered(Node<T>* new_node);
    void insertOrdered(T data);
    
    //Deletion
    Node<T>* deleteHead();
    Node<T>* deleteTail();
    Node<T>* deleteFromPos(int pos);
    
    //Search
    int searchIterative(T data);
    int searchRecursive(T data);
    
    //Other methods
    int getLength();
    void clear();
    void printListIterative();
    void printListRecursive();
    void operator= (const LinkedList<T>& other);
    Node<T>* at(int idx);
    
    T operator[] (int idx);
    const T operator[] (int idx) const;
    
    template <class S>
    friend std::ostream& operator<< (std::ostream& stream, const LinkedList<S>& list);
};

//__________DESTRUCTOR__________//

template <class T>
LinkedList<T>::~LinkedList(){ clear(); }

//__________INSERTION__________//

template <class T>
void LinkedList<T>::insertHead(Node<T>* new_node){
    new_node->setNext(head);
    head = new_node;
    length++;
}

template <class T>
void LinkedList<T>::insertHead(T data){
    Node<T>* new_node = new Node<T>(data);
    insertHead(new_node);
}

template <class T>
void LinkedList<T>::insertTail(Node<T>* new_node){
    if(head == nullptr) head = new_node;
    else{
        Node<T>* element = head;
        while(element->getNext() != nullptr) element = element->getNext();
        element->setNext(new_node);
    }
    length++;
}

template <class T>
void LinkedList<T>::insertTail(T data){
    Node<T>* new_node = new Node<T>(data);
    insertTail(new_node);
}

template <class T>
void LinkedList<T>::insertAtPos(Node<T>* new_node, int pos){
    if(pos<0 || pos>length){
        std::cout<<"Invalid position. Position must be between 0 and "<<length<<std::endl;
        return;
    }
    else if(pos==0) insertHead(new_node);
    else if(pos==length) insertTail(new_node);
    else{
        Node<T>* element = head;
        for(int i=0; i<pos-1; i++){
            element = element->getNext();
        }
        new_node->setNext(element->getNext());
        element->setNext(new_node);
        length++;
    }
}

template <class T>
void LinkedList<T>::insertAtPos(T data, int pos){
    Node<T>* new_node = new Node<T>(data);
    insertAtPos(new_node, pos);
}

template <class T>
void LinkedList<T>::insertOrdered(Node<T>* new_node){
    if(head==nullptr || head->getData()>new_node->getData()){
        new_node->setNext(head);
        head = new_node;
    }
    else{
        Node<T>* previous = head;
        Node<T>* element = head->getNext();
        while(element!=nullptr){
            if(element->getData()>new_node->getData()) break;
            else{
                previous = element;
                element = element->getNext();
            }
        }
        if(element==nullptr) previous->setNext(new_node);
        else{
            previous->setNext(new_node);
            new_node->setNext(element);
        }
    }
    length++;
}

template <class T>
void LinkedList<T>::insertOrdered(T data){
    Node<T>* new_node = new Node<T>(data);
    insertOrdered(new_node);
}

//__________DELETION__________//

template <class T>
Node<T>* LinkedList<T>::deleteHead(){
    if(head == nullptr) return nullptr;
    Node<T>* element = head;
    head = head->getNext();
    element->setNext(nullptr);
    length--;
    return element;
}

template <class T>
Node<T>* LinkedList<T>::deleteTail(){
    if(head == nullptr) return nullptr;
    else if(head->getNext() == nullptr) return deleteHead();
    else{
        Node<T>* previous = head;
        Node<T>* element = head->getNext();
        while(element->getNext() != nullptr){
            previous = element;
            element = element->getNext();
        }
        previous->setNext(nullptr);
        length--;
        return element;
    }
}

template <class T>
Node<T>* LinkedList<T>::deleteFromPos(int pos){
    if(pos<0 || pos > length-1){
        std::cout<<"Invalid position. Position must be between 0 and "<<length-1<<std::endl;
        return nullptr;
    }
    else if(pos==0) return deleteHead();
    else if(pos==length-1) return deleteTail();
    else{
        Node<T>* previous = head;
        Node<T>* element = head->getNext();
        for(int i=1; i<pos; i++){
            previous = element;
            element = element->getNext();
        }
        previous->setNext(element->getNext());
        element->setNext(nullptr);
        length--;
        return element;
    }
}

//__________SEARCH__________//

template <class T>
int LinkedList<T>::searchIterative(T data){
    Node<T>* element = head;
    int counter = 0;
    while(element != nullptr && element->getData()!=data){
        counter++;
        element = element->getNext();
    }
    if(element==nullptr) return -1;
    /* 
    /////---MY SOLUTION---/////
    
    while(true){
        if(element->getData()==data) break;
        else if(element->getNext()==nullptr) return -1;
        else{
            counter++;
            element = element->getNext();
        }
    }
    */
    return counter;
}

template <class T>
int LinkedList<T>::search_recursive(Node<T>* element,T data,int c){
    if(element==nullptr) return -1;
    else if(element->getData() == data) return c;
    return search_recursive(element->getNext(),data,c+1);
}

template <class T>
int LinkedList<T>::searchRecursive(T data){
    return search_recursive(head,data,0);
}

//-----OTHER-----//

template <class T>
int LinkedList<T>::getLength(){
    return length;
}

template <class T>
void LinkedList<T>::clear(){
    Node<T>* element = head;
    while(element != nullptr){
        head = element->getNext();
        delete element;
        element = head;
    }
    length = 0;
}

template <class T>
void LinkedList<T>::printListIterative(){
    Node<T>* element = head;
    int counter=0;
    while(element != nullptr){
        std::cout<<"Element at position "<< counter++ <<" = "<< element->getData()<<std::endl;
        element = element->getNext();
    }
}

template <class T>
void LinkedList<T>::print_recursive(Node<T>* _head,int c){
    if(_head==nullptr) std::cout<<std::endl;
    else{
        std::cout<<"Element at position "<< c <<" = "<<_head->getData()<<std::endl;
        print_recursive(_head->getNext(),c+1);
    }
}

template <class T>
void LinkedList<T>::printListRecursive(){
    print_recursive(head,0);
}

template <class T>
void LinkedList<T>::operator= (const LinkedList<T>& other){
    clear();
    Node<T>* element = other.head;
    while(element!=nullptr){
        insertTail(element->getData());
        element = element->getNext();
    }
}

template <class T>
Node<T>* LinkedList<T>::at(int idx){
	Node<T>* element = head;
	for(int i = 0; i < idx; i++) element = element->getNext();
    return element;
}

template <class S>
std::ostream& operator<< (std::ostream& stream, const LinkedList<S>& list){
    Node<S>* element = list.head;
    stream<<"[";
    while(element != nullptr){
        if(element->getNext()!=nullptr)stream<< element->getData()<<", ";
        else stream<<element->getData();
        element = element->getNext();
    }
    stream<<"]";
}