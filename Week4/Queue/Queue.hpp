#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Node.hpp"

template <typename T>

class Linkedlist_queue {
    private: 
    Node* front;
    Node* rear;
    int size;

    public: 
    Linkedlist_queue(): front(nullptr), rear(nullptr), size(0){};

    int getSize()
    {
        return size;
    }
    
    bool isEmpty()
    {
        return size == 0 ? true:false;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        if( size == 0 )
        {
            front = rear = newNode;
            size++;
            return;
        }
        rear->next = newNode;
        rear = newNode;
        size++;
    }

    Node* pop()
    {
        if(isEmpty())
        {
            return nullptr;
        }

        if(size==1)
        {
            Node* tmp = front;
            front = rear = nullptr;
            size--;
            return tmp;
        }

        Node* tmp = front;
        front = front->next;
        size--;
        return tmp;
    }

    void peek(){
        std::cout << "front: "<< front->data << std::endl;
        std::cout << "rear: "<< rear->data << std::endl;
    }

};
#endif