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

const ll L = 2e5+5;

ll pref[L];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll n, k, q;
    cin >> n >> k >> q;

    for(ll i=0; i<n; i++)
    {
        ll l, r;
        cin >> l >> r;

        l--, r--;

        pref[r+1]--;
        pref[l]++;
    }

    for(ll i=1; i<L; i++)
    {
        pref[i]+=pref[i-1];
    }

    vector <ll> ans(L, 0);

    for(ll i=0; i<L; i++)
    {
        if(!i)
        {
            if(pref[i] >= k)
            {
                ans[i]++;
            }
        }

        else
        {
            ans[i] = ans[i-1] + (pref[i]>=k);
        }
    }

    while(q--)
    {
        ll a, b;
        cin >> a >> b;

        a--, b--;

        ll res = ans[b];

        if(a)
        {
            res-=ans[a-1];
        }

        cout << res << endl; 
    }

    return 0;
}