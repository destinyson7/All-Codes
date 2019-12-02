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

const ll L = 20;

ll adj[L][L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, M;
    cin >> N >> M;

    for(ll i=0; i<M; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    vector <ll> permute;

    ll fact = 1;

    for(ll i=1; i<=N; i++)
    {
        permute.pb(i);
        fact*=i;
    }

    ll ans = 0;

    for(ll i=1; i<=fact; i++)
    {
        if(permute[0]==1)
        {   
            ll flag = 0;
            for(ll j=1; j<sz(permute); j++)
            {
                if(adj[permute[j-1]][permute[j]]==0)
                {
                    flag = 1;
                    break;
                }   
            }

            if(!flag)
            {
                ans++;
            }

            next_permutation(all(permute));
        }
    }

    cout << ans << endl;

    return 0;
}