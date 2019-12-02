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

const ll L = 3e5+5;

vector <pll> p;

bool check(ll a, ll b)
{
    for(auto i: p)
    {
        if(i.ff != a && i.ss != a && i.ff != b && i.ss != b)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    for(ll i=0; i<m; i++)
    {
        ll a, b;
        cin >> a >> b;

        p.pb(mp(a, b));
    }

    for(auto i: {p[0].ff, p[0].ss})
    {
        if(check(i, -1))
        {
            cout << "YES" << endl;
            return 0;
        }

        for(auto j:p)
        {
            if(i != j.ff && i != j.ss)
            {
                if(check(i, j.ff))
                {
                    cout << "YES" << endl;
                    return 0;
                }

                if(check(i, j.ss))
                {
                    cout << "YES" << endl;
                    return 0;
                }

                break;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}