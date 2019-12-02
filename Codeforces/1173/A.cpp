#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll x, y, z;
    cin >> x >> y >> z;

    if(x > y+z)
    {
        cout << "+" << endl;
    }

    else if(y > x+z)
    {
        cout << "-" << endl;
    }

    else if(z==0 && x==y)
    {
        cout << 0 << endl;
    }

    else
    {
        cout << "?" << endl;
    }

    return 0;
}