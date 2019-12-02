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

const ll L = 1e3+5;

queue <ll> order;

vector <ll> above[L];
bool visited[L];

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
    
    while(true)
    {
        while(!order.empty())
        {
            order.pop();
        }

        ll n, m;
        cin >> n >> m;

        for(ll i=1; i<=n; i++)
        {
            above[i].clear();
            visited[i] = false;
        }

        if(n+m == 0)
        {
            break;
        }

        for(ll i=0; i<m; i++)
        {
            ll u, v;
            cin >> u >> v;

            above[v].pb(u);
        }

        for(ll i=1; i<=n; i++)
        {
            if(!visited[i])
            {
                dfs(i);

                order.push(i);
            }
        }

        while(!order.empty())
        {
            cout << order.front() << " ";
            order.pop();
        }
        cout << endl;
    }


    return 0;
}