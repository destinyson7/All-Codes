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

bool visited[10][10];
ll dis[10][10];

ll bfs(pll src, pll trgt)
{
    queue <pll> q;

    q.push(src);

    dis[src.ff][src.ss] = 0;

    visited[src.ff][src.ss] = true;

    while(!q.empty())
    {
        pll top = q.front();
        q.pop();

        ll f = top.ff;
        ll s = top.ss;

        if(top == trgt)
        {
            return dis[f][s];
        }

        visited[f][s] = true;

        if(f+1<=8 && s-2>0)
        {
            if(!visited[f+1][s-2])
            {
                q.push(mp(f+1, s-2));
                dis[f+1][s-2] = dis[f][s]+1;
            }
        }

        if(f+2<=8 && s-1>0)
        {
            if(!visited[f+2][s-1])
            {
                q.push(mp(f+2, s-1));
                dis[f+2][s-1] = dis[f][s]+1;
            }
        }

        if(f+2<=8 && s+1<=8)
        {
            if(!visited[f+2][s+1])
            {
                q.push(mp(f+2, s+1));
                dis[f+2][s+1] = dis[f][s]+1;
            }
        }

        if(f+1<=8 && s+2<=8)
        {
            if(!visited[f+1][s+2])
            {
                q.push(mp(f+1, s+2));
                dis[f+1][s+2] = dis[f][s]+1;
            }
        }

        if(f-1>0 && s+2<=8)
        {
            if(!visited[f-1][s+2])
            {
                q.push(mp(f-1, s+2));
                dis[f-1][s+2] = dis[f][s]+1;
            }
        }

        if(f-2>0 && s+1<=8)
        {
            if(!visited[f-2][s+1])
            {
                q.push(mp(f-2, s+1));
                dis[f-2][s+1] = dis[f][s]+1;
            }
        }

        if(f-2>0 && s-1>0)
        {
            if(!visited[f-2][s-1])
            {
                q.push(mp(f-2, s-1));
                dis[f-2][s-1] = dis[f][s]+1;
            }
        }

        if(f-1>0 && s-2>0)
        {
            if(!visited[f-1][s-2])
            {
                q.push(mp(f-1, s-2));
                dis[f-1][s-2] = dis[f][s]+1;           
            }
        }
    }

    assert(false);
    return -1;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    string f, s;

    map <char, ll> m;

    ll cnt = 1;

    for(char i='a'; i<='h'; i++)
    {
        m[i] = cnt++;
    }

    while(cin >> f >> s)
    {
        for(ll i=1; i<=8; i++)
        {
            for(ll j=1; j<=8; j++)
            {
                visited[i][j] = false;
            }
        }

        pll a, b;

        a = mp(m[f[0]], f[1]-48);
        b = mp(m[s[0]], s[1]-48);

        ll req = bfs(a, b);

        cout << "To get from " << f << " to " << s << " takes " << req << " knight moves." << endl;
    }


    return 0;
}