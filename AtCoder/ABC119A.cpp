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
    
    string s;
    cin >> s;

    string y = s.substr(0, 4);
    string m = s.substr(5, 2);
    string d = s.substr(8, 2);

    if(y>"2019")
    {
        cout << "TBD" << endl;
    }

    else if(m>"04")
    {
        cout << "TBD" << endl;
    }

    else if(d>"30")
    {
        cout << "TBD" << endl;
    }

    else
    {
        cout << "Heisei" << endl;
    }

    return 0;
}