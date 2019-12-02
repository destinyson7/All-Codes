#include <bits/stdc++.h>

using namespace std;

int main()
{
    set <int> s;

    s.insert(-5);
    s.insert(1);
    s.insert(15);
    s.insert(1);
    s.insert(7);
    s.insert(6);
    s.insert(-5);

    int n = s.size();

    cout << "Size of the set: " << n << endl;

    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}