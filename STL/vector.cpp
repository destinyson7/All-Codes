#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector <int> v;

    v.push_back(5);
    v.push_back(10);
    v.push_back(7);
    v.push_back(6);
    v.push_back(-5);

    int n = v.size();

    cout << "Unsorted order" << endl;
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());

    cout << endl << "Sorted order" << endl;
    for(int i=0; i<n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}