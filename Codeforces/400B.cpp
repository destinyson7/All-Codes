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
    
    ll n, m;
    cin >> n >> m;

    set <ll> dis;

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;

        bool f = false;
        ll pos = -1;

        for(ll j=0; j<m; j++)
        {
            if(s[j] == 'G')
            {
                if(f)
                {
                    cout << -1 << endl;
                    return 0;
                }

                pos = j;
            }

            else if(s[j] == 'S')
            {
                f = true;

                dis.insert(j-pos);
            }
        }
    }

    cout << sz(dis) << endl;

    return 0;
}