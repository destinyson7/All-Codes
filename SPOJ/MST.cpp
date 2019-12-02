#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl "\n"

const ll L = 1e5+5;

vector <ll> parent(L);
vector <ll> unionSize(L);
vector < pair <ll, pair <ll, ll> > > weights;

ll find(ll s)
{
    if(parent[s]==s)
    {
        return s;
    }

    return parent[s] = find(parent[s]);
}

void unionSet(ll x, ll y)
{
    ll a = find(x);
    ll b = find(y);
    
    if (unionSize[a] > unionSize[b])
    {
        unionSet(y, x);      
        return;
    }  
    
    parent[a] = b;

    unionSize[b] += unionSize[a];
}

ll kruskals(ll M)
{
    sort(weights.begin(), weights.end());
    
    ll ans = 0;

    for(ll i=0; i<M; i++)
    {
        ll u = weights[i].ss.ff;
        ll v = weights[i].ss.ss;

        ll w = weights[i].ff;

        if(find(u)!=find(v))
        {
            ans+=w;
            unionSet(u, v);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for(ll i=0; i<L; i++)
    {
        parent[i] = i;
    }
    
    ll N, M;
    cin >> N >> M;

    for(ll i=0; i<M; i++)
    {
        ll a, j, k;
        cin >> a >> j >> k;

        weights.pb(mp(k, mp(a-1, j-1)));
    }    

    cout << kruskals(M) << endl;

    return 0;
}