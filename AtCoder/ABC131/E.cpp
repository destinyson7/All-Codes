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

const ll L = 1e2+5;

ll adj[L][L];

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll N, K;
    cin >> N >> K;

    ll m = ((N-1)*(N-2))/2;

    if(K>m)
    {
        cout << -1 << endl;
    }

    else
    {
        for(ll i=2; i<=N; i++)
        {
            adj[1][i] = 1;
        }

        ll edges = N-1;
        // K-=m;

        // cout << K << endl;

        ll first = 2;
        ll second = 3;

        while(m>K)
        {
            adj[first][second] = 1;
            edges++;

            second++;

            if(second == N+1)
            {
                first++;
                second = first+1;
            }

            m--;
        }

        cout << edges << endl;

        for(ll i=1; i<=N; i++)
        {
            for(ll j=1; j<=N; j++)
            {
                if(adj[i][j])
                {
                    cout << i << " " << j << endl;
                }
            }
        }
    }



    return 0;
}