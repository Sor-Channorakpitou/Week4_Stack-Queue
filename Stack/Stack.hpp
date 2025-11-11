#include<iostream>
using namespace std;
template <typename T>
class ArrayStack{
    private:
        T stack[50];
        int top;
    public:
        ArrayStack(){
            top = -1;
        }
        void push( T value ){
            if(top == 49){
                cout << "Stack is Full" << endl;
                return;
            }
            stack[++top] = value;
        }
        void pop(){
            if ( isEmpty() ) {
                cout << "Stack is empty!" << endl;
                return;
            } 
            top--;
        }
        T peek(){
            return stack[top];   
        }
        bool isEmpty(){
            return top == -1;
        }     
};
bool checkMatching(char open, char close){
    return ( open == '(' && close == ')' ) || ( open == '[' && close == ']' ) ||
           ( open == '{' && close == '}' ) || ( open == '<' && close == '>' );
}
bool isOpen(char temp){
    if ( temp == '(' || temp == '[' || temp == '{' || temp == '<' )
    return true;
    else return false;
}
bool isClose(char temp){
    if ( temp == '}' || temp == ']' || temp == ')' || temp == '>' )
    return true;
    else return false;
}
void Checking(string line){
    ArrayStack<char> array;
    int pos;
    bool insideQuote = false;
    for(int i = 0; i < line.length(); i++){
        char temp = line[i];
        if ( temp == '\'') {
            insideQuote = !insideQuote;
            continue;
        }
        if ( insideQuote ) 
        {
            continue;
        }
        if( isOpen(temp) ){
            array.push(temp);
            pos = i+1;
        } 
        else if( isClose(temp) )
        {
            if( array.isEmpty() ){
                cout<<"ERROR at pos=" << i+1 <<" reason = Extra-closing" << endl;
                return;
            }

            char forCheck = array.peek();
            if( !checkMatching(forCheck,temp) ){
                cout<<"ERROR at pos=" << i+1 << " reason = Mismatch"<< endl;
                return;
            }
            array.pop();
        }
    }

    if ( !array.isEmpty() ) {
        cout << "ERROR at pos "<< pos << "reason = Unclosed" << endl;
    } else {
        cout << "OK" << endl;
    }
}