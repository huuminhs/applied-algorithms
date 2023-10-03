#include <bits/stdc++.h> 
#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* child[26];
    bool isEndOfWord;
    Node() {
        for (int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        isEndOfWord = false;
    }
};

Node* root = new Node();

bool add_string(string str) {
    int i, j, strlen = str.length();
    Node* cur = root;
    for (i = 0; i < strlen; i++) {
        j = str[i] - 'a';
        if (cur->child[j] == NULL) {
            cur->child[j] = new Node();
        }
        cur = cur->child[j];
    }
    if (cur->isEndOfWord == false) {
        cur->isEndOfWord = true;
        return true;
    } else return false;
}

bool find_string(string str) {
    int i, j, strlen = str.length();
    Node* cur = root;
    for (i = 0; i < strlen; i++) {
        j = str[i] - 'a';
        if (cur->child[j] == NULL) return false;
        else cur = cur->child[j];
    }
    if (cur->isEndOfWord == true) return true;
    else return false;
}

void freeMem(Node* myNode) {
    if (myNode != NULL) {
        for (int i = 0; i < 26; i++)
            freeMem(myNode->child[i]);
        free(myNode);
    }
    return;
}

int main() {
    int i, strlen;
    string tmp;
    while (true) {
        cin >> tmp;
        if (tmp.compare("*") == 0) {
            break;
        } else {
            add_string(tmp);
        }
    };

    fflush(stdin);

    while (true) {
        getline(cin, tmp);
        strlen = tmp.length();
        if (tmp.compare("***") == 0) break;
        if (strlen < 6) continue;
        else {
            if (tmp.substr(0, 4).compare("find") == 0) {
                cout << find_string(tmp.substr(5, strlen)) << endl;
            } else {
                cout << add_string(tmp.substr(7, strlen)) << endl;
            }
        }
    }

    freeMem(root);

    return 0;
}