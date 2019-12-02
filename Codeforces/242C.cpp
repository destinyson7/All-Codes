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

const ll L = 1e9;

map <pll, bool> visited;
map <pll, ll> ok;
map <pll, ll> dis;

bool isValid(pll p)
{
    if(p.ff>0 && p.ff<=L && p.ss>0 && p.ss<=L && !visited[p] && ok[p])
    {
        return true;
    }

    return false;
}

ll bfs(pll src, pll trgt)
{
    dis[src] = 0;
    visited[src] = true;

    queue <pll> q;
    q.push(src);

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        if(top == trgt)
        {
            return dis[top];
        }

        visited[top] = true;

        ll f = top.ff;
        ll s = top.ss;

        if(isValid(mp(f, s-1)))
        {
            q.push(mp(f, s-1));
            visited[mp(f, s-1)] = true;

            dis[mp(f, s-1)] = dis[top]+1;
        }

        if(isValid(mp(f+1, s-1)))
        {
            q.push(mp(f+1, s-1));
            visited[mp(f+1, s-1)] = true;

            dis[mp(f+1, s-1)] = dis[top]+1;
        }

        if(isValid(mp(f+1, s)))
        {
            q.push(mp(f+1, s));
            visited[mp(f+1, s)] = true;

            dis[mp(f+1, s)] = dis[top]+1;
        }

        if(isValid(mp(f+1, s+1)))
        {
            q.push(mp(f+1, s+1));
            visited[mp(f+1, s+1)] = true;

            dis[mp(f+1, s+1)] = dis[top]+1;
        }

        if(isValid(mp(f, s+1)))
        {
            q.push(mp(f, s+1));
            visited[mp(f, s+1)] = true;

            dis[mp(f, s+1)] = dis[top]+1;
        }

        if(isValid(mp(f-1, s+1)))
        {
            q.push(mp(f-1, s+1));
            visited[mp(f-1, s+1)] = true;

            dis[mp(f-1, s+1)] = dis[top]+1;
        }

        if(isValid(mp(f-1, s)))
        {
            q.push(mp(f-1, s));
            visited[mp(f-1, s)] = true;

            dis[mp(f-1, s)] = dis[top]+1;
        }

        if(isValid(mp(f-1, s-1)))
        {
            q.push(mp(f-1, s-1));
            visited[mp(f-1, s-1)] = true;

            dis[mp(f-1, s-1)] = dis[top]+1;
        }
    }

    // assert(false);
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    pll f, s;
    cin >> f.ff >> f.ss >> s.ff >> s.ss;

    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll r, a, b;
        cin >> r >> a >> b;

        for(ll j=a; j<=b; j++)
        {
            ok[mp(r, j)] = 1;
        }
    }

    cout << bfs(f, s) << endl;

    return 0;
}