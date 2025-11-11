#ifndef NODE_HPP
#define NODE_HPP
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const int value) : data(value), next(nullptr){}
};
#endif 