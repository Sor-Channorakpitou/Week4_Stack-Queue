#ifndef STACK_HPP
#define STACK_HPP
#include "Node.hpp"
template <typename T>
class Linkedlist_stack{
private:
    Node* head;
    Node* cur;
    int size;
public:
    Linkedlist_stack(): head(nullptr), cur(nullptr), size(0){};

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0 ? true : false;
    }

    void push(int data)
    {
        Node* newNode = new Node(data);
        if ( size == 0 )
        {
            head = newNode;
            size++;
            return;
        }
        newNode->next = head;
        head = newNode;
        size++;
    }

    Node* pop(){
        if( isEmpty() )
        {
            return nullptr;
        }
        if( size == 1 )
        {
            head = nullptr;
            size--;
            return nullptr;
        }
        cur = head;
        head = head->next;
        return cur;
    }

    void peek(){
        std::cout << head->data ;
        return;
    }

};

#endif