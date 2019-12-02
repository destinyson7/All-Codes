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

vector < pair <ll, ll> > v(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, K;
    cin >> N >> K;

    for(ll i=0; i<N; i++)
    {
        cin >> v[i].ff >> v[i].ss;
    }

    sort(v.begin(), v.begin()+N);

    ll cur = 0;
    ll j = 0;

    while(cur < K)
    {
        cur+=v[j].ss;

        if(cur>=K)
        {
            cout << v[j].ff << endl;
            return 0;
        }

        j++;
    }

    return 0;
}