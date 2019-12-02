#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll x;
    cin >> x;

    if(x%4 == 1)
    {
        cout << 0 << " " << "A" << endl;
    }

    else if(x%4 == 2)
    {
        cout << 1 << " " << "B" << endl;

    }

    else if(x%4 == 3)
    {
        cout << 2 << " " << "A" << endl;
    }

    else
    {
        cout << 1 << " " << "A" << endl;
    }


    return 0;
}