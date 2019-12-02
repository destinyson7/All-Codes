#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)a.size()
#define endl "\n"

const ll L = 1005;

vector <ll> x(L);
vector <ll> y(L);

map < pair <ll, ll>, set <ll> > mapp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
        {
            if(i==j)
            {
                continue;
            }

            ll a = y[i] - y[j];
            ll b = x[i] - x[j];
            ll m;
            
            if(a==0)
            {
                m = y[i];
                b = 1;
            }

            else if(b==0)
            {
                m = x[i];
                a = 1;
            }

            else
            {
                ll g = __gcd(a, b);
                a/=g;
                b/=g;

                m = b*y[j] - a*x[j];
            }

            mapp[mp(a, b)].insert(m);
        }
    }

    ll ans = 0;
    ll rem = 0;

    for(auto i: mapp)
    {
        ll s = sz(i.ss);
        ans+=s;
        s = s*(s-1)/2;
        rem+=s;
    }

    ll total = ans;
    total = total*(total-1)/2;
    // total/=2;
    total-=rem;

    cout << total << endl;
    return 0;
}