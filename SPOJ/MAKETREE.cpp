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

const ll L = 1e5+5;

queue <ll> order;
vector <ll> above[L];
bool visited[L];
ll par[L];

void dfs(ll s)
{
    visited[s] = true;

    for(auto i: above[s])
    {
        if(!visited[i])
        {
            dfs(i);

            order.push(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    for(ll i=1; i<=k; i++)
    {
        ll w;
        cin >> w;

        for(ll j=0; j<w; j++)
        {
            ll a;
            cin >> a;

            above[a].pb(i);
        }
    }

    for(ll i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);

            order.push(i);
        }
    }

    ll boss = 0;

    while(!order.empty())
    {
        ll t = order.front();
        order.pop();

        par[t] = boss;
        boss = t;
    }

    for(ll i=1; i<=n; i++)
    {
        cout << par[i] << endl;
    }


    return 0;
}