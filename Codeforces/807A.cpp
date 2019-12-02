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

    bool f = false;

    bool m = false;

    ll prev = 1e15;

    for(ll i=0; i<n; i++)
    {
        ll a, b;
        cin >> a >> b;

        if(a!=b)
        {
            f = true;
            break;
        }

        if(a > prev)
        {
            m = true;
        }

        prev = a;
    }   

    if(f)
    {
        cout << "rated" << endl;
    }

    else if(m)
    {
        cout << "unrated" << endl;
    }

    else
    {
        cout << "maybe" << endl;
    }


    return 0;
}