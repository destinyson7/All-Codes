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
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll f = a;
    ll s = c;

    if(f>s)
    {
        cout << f << endl;
        return 0;
    }

    while(true)
    {
        f+=b;

        if(f>s)
        {
            cout << s << endl;
            return 0;
        }

        s-=d;

        if(s<f)
        {
            cout << f << endl;
            return 0;
        }

    }


    return 0;
}