class Order {
public:
    int data;
    Order* next;

    Order( const int Orderdata ) : data(Orderdata), next(nullptr){}
};

class Linkedlist_OrderQueue {
    private: 
    Order* front;
    Order* rear;
    int length;

    public: 
    Linkedlist_OrderQueue(): front(nullptr), rear(nullptr), length(0){};

    ~Linkedlist_OrderQueue() {
        while( !isEmpty() )
        {
            dequeue();
        }
    }

    int getlength()
    {
        return length;
    }
    
    bool isEmpty()
    {
        return length == 0;
    }

    void print()
    {
        Order* cur = front;
        while ( cur )
        {
            std::cout << cur->data << "->"; 
            cur = cur->next;
        }
        std::cout << "NULL" << std::endl;
    }

    void enqueue( int Orderdata )
    {
        Order* newOrder = new Order(Orderdata);
        if( length == 0 )
        {
            front = rear = newOrder;
            length++;
            return;
        }
        rear->next = newOrder;
        rear = newOrder;
        length++;
    }

    int dequeue()
    {
        if( isEmpty() )
        {
            return 0;
        }
        if( length == 1 )
        {
            Order* tmp = front;
            int ID = tmp->data;
            front = rear = nullptr;
            length--;
            delete tmp;
            return ID;
        }

        Order* tmp = front;
        int ID = tmp->data;
        front = front->next;
        length--;
        delete tmp;
        return ID;
    }

    void peekfront(){
        std::cout << "front: "<< front->data << std::endl;
    }

    void peekrear(){
        std::cout << "rear: "<< rear->data << std::endl;
    }

};