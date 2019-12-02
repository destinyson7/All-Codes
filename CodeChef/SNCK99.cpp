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

const ll L1 = 3e5+5;
const ll L2 = 525;

ll S[L2];
ll W[L1];
ll ans[L2];
bool done[L1];

vector <pll> adj[L2];

ll N;

void iterate(ll check1, ll check2, ll N, bool flag)
{
    for(ll j=1; j<=N; j++)
    {
        check1 = 0;
        check2 = 0;

        for(auto v: adj[j])
        {
            ll m = min(W[v.ss], S[v.ff]*S[j]);
            
            if(ans[j] != ans[v.ff])
            {
                check1+=m;
            }

            else
            {
                check2+=m;
            }
        }

        if(flag && (check1 < check2))
        {
            ans[j]^=1;
        }
    }
}

void query(ll N)
{
    for(ll i=1; i<=N; i++)
    {
        iterate(0, 0, N, false);

        for(auto v: adj[i])
        {
            if(W[v.ss]<=S[v.ff]*S[i])
            {
                if(ans[i] == ans[v.ff])
                {
                    if(!done[v.ss])
                    {   
                        done[v.ss] = true;

                        printf("%lld\n", v.ss);
                        fflush(stdout);

                        ll type;
                        cin >> type;

                        if(type == 1)
                        {
                            ll ind, val;
                            cin >> ind >> val;

                            W[ind] = val;
                        }

                        else if(!type)
                        {
                            ll ind, val;
                            cin >> ind >> val;

                            S[ind] = val;
                        }

                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
    }

    printf("%lld\n", -1ll);
    // // cout << "-1" << endl;
}

void process(ll N)
{
    ll check1 = 0;
    ll check2 = 0;

    for(ll i=0; i<100; i++)
    {
        iterate(check1, check2, N, true);
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    ll M;
    scanf("%lld %lld", &N, &M);
    // cin >> N >> M;

    for(ll i=1; i<=N; i++)
    {
        scanf("%lld", &S[i]);

        ans[i] = ((i&1) ? 1:0);
        // cin >> S[i+1];
    }

    for(ll i=1; i<=M; i++)
    {
        scanf("%lld", &W[i]);
        // cin >> W[i+1];
    }

    for(ll i=1; i<=M; i++)
    {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        // cin >> a >> b;

        adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }

    process(N);

    query(N);

    for(ll i=1; i<=N; i++)
    {
        printf("%c", !ans[i] ? 'G':'C');
        // cout << ((!ans[i]) ? "G":"C");
        fflush(stdout);
    }

    printf("\n");
    // cout << endl;
    fflush(stdout);

    return 0;
}