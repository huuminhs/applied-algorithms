#include <iostream>
#include <string>
#include <queue>
#include <bits/stdc++.h> 
using namespace std;

const string POP = "POP";

int main() {
    queue<int> myQueue;
    string tmp;
    while (true) {
        getline(cin, tmp);
        if (tmp[0] == '#') break;
        else {
            if (tmp.compare(POP) == 0) {
                if (myQueue.size() == 0) {
                    cout << "NULL" << endl;
                } else {
                    cout << myQueue.front() << endl;
                    myQueue.pop();
                }
            } else {
                myQueue.push(stoi(tmp.substr(5)));
            }
        }
    }
    return 0;
}