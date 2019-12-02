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

ll n;

set <ll> s;

ll cal(ll n)
{
    for(ll i=0; i<=n; i++)
    {
        for(ll j=0; j<=n; j++)
        {
            for(ll k=0; k<=n; k++)
            {
                for(ll a=0; a<=n; a++)
                {
                    if(i+j+k+a == n)
                    {
                        s.insert(i+5*j+10*k+50*a);
                    }
                }
            }
        }
    }

    return sz(s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // ll n;
    cin >> n;

    if(n <= 50)
    {
        cout << cal(n) << endl;
    }

    else
    {
        cout << cal(50) + (n-50)*49 << endl;
    }

    return 0;
}