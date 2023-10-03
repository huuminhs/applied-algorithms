#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> freq;
    string paragraph, word;
    while (true)
    {
        getline(cin, paragraph);
        if (paragraph.length() == 0)
            break;
        word.clear();
        for (char c : paragraph)
        {
            if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')))
                word += c;
            else
            {
                if (word.length() != 0)
                {
                    freq[word]++;
                    word.clear();
                }
            }
        }
        if (word.length() != 0)
            freq[word]++;
    }
    for (auto &[k, v] : freq)
        cout << k << " " << v << endl;
}