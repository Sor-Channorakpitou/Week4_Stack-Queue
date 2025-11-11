#include"Stack.hpp"
using namespace std;
int main(){
    string cases[7] = {
        "()[]{}", "([{}])",          
        "([)]", "(((",              
        "())))", "'<''>{'",  
        "<<<<{})"
    };
    for ( int i = 0; i < 7; i++ ) {
        cout << cases[i] << " -> ";
        Checking(cases[i]);
    }

    return 0;
}