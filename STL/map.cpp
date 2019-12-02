#include <bits/stdc++.h>

using namespace std;

int main()
{
    map <char, int> m;

    m['d'] = 25;
    m['a'] = 4;
    m['b'] = 19;

    int n = m.size();

    cout << "Size of map: " << n << endl;
    for(auto it = m.begin(); it != m.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }

    cout << endl << endl;
    cout << m['a'] << endl;
    cout << m['b'] << endl;
    cout << m['c'] << endl;
    cout << m['d'] << endl;

    return 0;
}