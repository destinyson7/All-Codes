#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char b;
    cin >> b;

    if(b=='A')
    {
        cout << "T" << endl;
    }

    if(b=='C')
    {
        cout << "G" << endl;
    }

    if(b=='T')
    {
        cout << "A" << endl;
    }

    if(b=='G')
    {
        cout << "C" << endl;
    }

    return 0;
}