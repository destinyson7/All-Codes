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

    set <ll, greater <ll> > s;

    ll cur = n;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        if(a == cur)
        {
            cout << cur << " ";
            cur--;

            while(true)
            {
                if(!s.empty() && *s.begin() == cur)
                {
                    cout << cur << " ";
                    cur--;

                    s.erase(*s.begin());
                }

                else
                {
                    break;
                }
            }
        }

        else
        {
            s.insert(a);
        }

        cout << endl;
    }

    return 0;
}