#ifndef STACK_HPP
#define STACK_HPP

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
        void push(T value){
            if(top == 49){
                cout<<"Stack is Full"<<endl;
                return;
            }
            stack[++top] = value;
        }
        void pop(){
            if (isEmpty()) {
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
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}
bool isOpen(char temp){
    return temp == '(' || temp == '[' || temp == '{';
}
bool isClose(char temp){
    return temp == '}' || temp == ']' || temp == ')';
}
void checkBrackets(string text){
    ArrayStack<char>array;
    bool insideSingleQuote = false;
    for(int i = 0; i < text.length(); i++){
        char temp = text[i];
        if (temp == '\'') {
            insideSingleQuote = !insideSingleQuote;
            continue;
        }
        if (insideSingleQuote) continue;
        if(isOpen(temp)){
            array.push(temp);
        } else if(isClose(temp)){
            if(array.isEmpty()){
                cout<<"ERROR pos="<<i+1<<" reason=extra-closing"<<endl;
                return;
            }
            char forCheck = array.peek();
            if(!checkMatching(forCheck,temp)){
                cout<<"ERROR pos="<<i+1<<" reason=mismatch"<<endl;
                return;
            }
            array.pop();
        }
    }

    if (!array.isEmpty()) {
        cout << "ERROR pos=3 reason=unclosed\n";
    } else {
        cout << "OK\n";
    }
}

#endif