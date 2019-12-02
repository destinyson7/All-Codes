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
    
    ll l, r;
    cin >> l >> r;

    ll a, b, c;

    if(l&1)
    {
        a = l+1;
    }

    else
    {
        a = l;
    }

    b = a+1;
    c = b+1;

    if(c>r)
    {
        cout << -1 << endl;
    }

    else
    {
        cout << a << " " << b << " " << c << endl;
    }



    return 0;
}