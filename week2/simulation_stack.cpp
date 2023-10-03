#include <iostream>
#include <string>
#include <stack>
#include <bits/stdc++.h> 
using namespace std;

const string POP = "POP";

int main() {
    stack<int> myStack;
    string tmp;
    while (true) {
        getline(cin, tmp);
        if (tmp[0] == '#') break;
        else {
            if (tmp.compare(POP) == 0) {
                if (myStack.size() == 0) {
                    cout << "NULL" << endl;
                } else {
                    cout << myStack.top() << endl;
                    myStack.pop();
                }
            } else {
                myStack.push(stoi(tmp.substr(5)));
            }
        }
    }
    return 0;
}