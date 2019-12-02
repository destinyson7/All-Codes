#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

vector <ll> h1(L);
vector <ll> h2(L);

vector < pair <ll, ll> > v1;
vector < pair <ll, ll> > v2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll a;
        cin >> a;

        if(i%2==0)
        {
            h1[a]++;
        }

        else
        {
            h2[a]++;
        }
    }

    for(ll i=0; i<L; i++)
    {
        v1.pb(mp(h1[i], i));
        v2.pb(mp(h2[i], i));
    }

    sort(all(v1));
    reverse(all(v1));

    sort(all(v2));
    reverse(all(v2));

    if(v1[0].ss!=v2[0].ss)
    {
        cout << n - min(n/2,v1[0].ff) - min(n/2, v2[0].ff) << endl;
    }
    
    else
    {
        cout << n - min(n/2, v1[0].ff) - min(n/2, max(v1[1].ff, v2[1].ff)) << endl;
    }   

    return 0;
}