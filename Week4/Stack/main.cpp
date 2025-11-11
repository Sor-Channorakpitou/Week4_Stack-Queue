#include"Stack.hpp"
using namespace std;

int main(){
    string tests[] = {
        "()[]{}",          // OK
        "([{}])",          // OK
        "([)]",             // mismatch
        "(((",              // unclosed
        "())))",            // extra closing
        "if(a[0] == '{')"   // OK
    };
    for (int i = 0; i < 6; i++) {
        cout << tests[i] << " -> ";
        checkBrackets(tests[i]);
    }

    return 0;
}