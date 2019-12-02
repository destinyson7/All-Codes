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
    
    ll n;
    cin >> n;

    string se;
    cin >> se;

    ll f = 0, s = 0;

    for(ll i=0; i<sz(se); i++)
    {
        if(se[i] == '1')
        {
            f++;
        }

        else
        {
            s++;
        }
    }

    if(f != s)
    {
        cout << 1 << endl;
        cout << se << endl;
    }

    else
    {
        cout << 2 << endl;
        cout << se.substr(0, n-1) << " " << se.substr(n-1, 1) << endl;
    }


    return 0;
}