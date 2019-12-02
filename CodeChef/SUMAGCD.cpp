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

ll a[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll N;
        cin >> N;

        ll minn = 1e15;
        ll maxx = -1e15;

        set <ll> first;
        set <ll> second;

        for(ll i=0; i<N; i++)
        {
            cin >> a[i];
            
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
        }

        ll ans1;
        ll ans2;

        for(ll i=0; i<N; i++)
        {
            if(a[i]%minn == 0)
            {
                first.insert(a[i]);
            }

            else
            {
                second.insert(a[i]);
            }
        }

        ll secmax = -1e15;

        vector <ll> f;
        vector <ll> s;

        if(sz(second) > 1)
        {
            for(auto i: second)
            {
                secmax = max(secmax, i);
            }

            for(auto i: second)
            {
                if(i == secmax)
                {
                    s.pb(i);
                }

                else
                {
                    f.pb(i);
                }
            }

            for(auto i: first)
            {
                f.pb(i);
            }

            ll gf = 0;
            ll gs = 0;

            for(auto i: f)
            {
                gf = gcd(gf, i);
            }

            for(auto i: s)
            {
                gs = gcd(gs, i);
            }

            ans1 = gf + gs;
        }

        else if(sz(second) == 1)
        {
            ll g1 = 0;
            ll g2 = 0;

            for(auto i: first)
            {
                g1 = gcd(g1, i);
            }

            for(auto i: second)
            {
                g2 = gcd(g2, i);
            }

            ans1 = g1 + g2;
        }

        else
        {
            ll m1 = 1e15;
            ll m2 = -1e15;
            for(auto i: first)
            {
                m1 = min(m1, i);
                m2 = max(m2, i);
            }

            ans1 = m1+m2;
        }

        ll g3 = 0;
        ll g4 = maxx;

        for(ll i=0; i<N; i++)
        {
            if(a[i]!=maxx)
            {
                g3 = gcd(g3, a[i]);
            }
        }

        if(g3 == 0)
        {
            g3 = maxx;
        }

        ans2 = g3+g4;

        cout << max(ans1, ans2) << endl; 
    }

    return 0;
}