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

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll q;
    cin >> q;

    while(q--)
    {
        ll n;
        cin >> n;

        vector <ll> a;
        map <ll, ll> m;
        set <ll> s;
        // map <ll, bool> done;

        for(ll i=0; i<n; i++)
        {
            ll t;
            cin >> t;

            m[t]++;

            a.pb(t);
        }

        for(ll i=1; i<=n; i++)
        {
            s.insert(i);
        }

        ll ans = 0;

        for(auto i: m)
        {
            if(s.count(i.ss))
            {
                ans+=i.ss;
                s.erase(i.ss);
            }

            else if(!s.empty())
            {
                auto it = s.lower_bound(i.ss);

                if(it != s.begin())
                {
                    it--;

                    ans+=*it;

                    s.erase(*it);
                }
            }
        }
        

        cout << ans << endl;

        // sort(all(a));
    }

    return 0;
}