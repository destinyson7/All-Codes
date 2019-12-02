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

const ll L = 2e5+5;

ll ans[L];
multiset < ll, greater<ll> > s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, M;
    cin >> n >> M;

    ll cur = 0;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        cur+=t;


        if(cur <= M)
        {
            ans[i] = 0;
        }

        else
        {
            ll temp = cur;

            for(auto j:s)
            {
                ans[i]++;

                temp-=j;

                if(M >= temp)
                {
                    break;
                }
            }
        }

        s.insert(t);
    }

    for(ll i=0; i<n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}