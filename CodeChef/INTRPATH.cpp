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

const ll L = 3e5+5;

ll ans[L];
ll upto[L];
ll beginn[L];
ll endd[L];

// USED TEMPLATE OF LCA FROM:
// https://cp-algorithms.com/graph/lca.html
// with little modifications

class node
{
public:

    ll N;
    vector <ll> eulerTour;
    vector <bool> visited;
    vector <ll> seg;
    vector <ll> h;
    vector <ll> f;

    node(vector < vector <ll> > &adj, ll s = 0)
    {
        N = sz(adj);
        f.resize(N);
        visited.assign(N, false);
        h.resize(N);
        eulerTour.reserve(N<<1);

        dfslca(s, adj);

        seg.resize(sz(eulerTour)<<2);
        make(0, sz(eulerTour)-1, 1);
    }

    void make(ll start, ll end, ll i)
    {
        if(start == end)
        {
            seg[i] = eulerTour[start];
            return;
        }

        ll mid = start + ((end-start)>>1LL);

        make(start, mid, 2*i);
        make(mid+1, end, 2*i+1);

        if(h[seg[2*i]] < h[seg[2*i+1]])
        {
            seg[i] = seg[2*i];
        }

        else
        {
            seg[i] = seg[2*i+1];
        }
    }

    ll query(ll start, ll end, ll i, ll l, ll r)
    {
        if(end < l || start > r)
        {
            return -1;
        }

        if(start>=l && end<=r)
        {
            return seg[i];
        }

        ll mid = start + (end-start)/2;

        ll le = query(start, mid, 2*i, l, r);
        ll ri = query(mid+1, end, 2*i+1, l , r);

        if(le == -1)
        {
            return ri;
        }

        else if(ri == -1)
        {
            return le;
        }

        if(h[ri] > h[le])
        {
            return le;
        }

        else
        {
            return ri;
        }
    }

    ll lca(ll a, ll b)
    {
        if(f[b] < f[a])
        {
            return query(0, sz(eulerTour)-1, 1, f[b], f[a]);
        }

        else
        {
            return query(0, sz(eulerTour)-1, 1, f[a], f[b]);
        }
    }

    void dfslca(ll s, vector < vector <ll> > &adj, ll lev=0)
    {
        f[s] = sz(eulerTour);
        h[s] = lev;
        visited[s] = true;

        eulerTour.pb(s);

        for(auto i: adj[s])
        {
            if(!visited[i])
            {
                dfslca(i, adj, lev+1);
                eulerTour.pb(s);
            }
        }
    }


}; 

void dfsCheck(ll s, vector < vector <ll> > &adj, auto &ch, vector <bool> &v, ll N)
{
    v[s] = true;

    for(auto u: adj[s])
    {
        if(!v[u])
        {
            ll tim = 1+((endd[u]-beginn[u]-1)>>1LL); 

            ans[u]=ans[s];
            ll temp = N-1-ch[u][0].ss;
            temp+=tim;
            temp+=(tim*(ch[s][0].ss - tim));
            temp+=((N-1-ch[u][0].ss)*ch[u][0].ss);
            ans[u]-=temp;
            ans[u]+=upto[u];

            dfsCheck(u, adj, ch, v, N);

        }
    }
}

void dfsFinal(ll s, vector < vector <ll> > &adj, auto &ch, vector <bool> &v, ll &res, ll N)
{
    queue <ll> ok;

    ll check = 0;
    beginn[s] = res;
    v[s] = true;

    for(auto u: adj[s])
    {
        if(!v[u])
        {
            ok.push(u);
            check++;
            res++;

            dfsFinal(u, adj, ch, v, res, N);
        }
    }

    check++;
    ch[s] = new pll [check];
    endd[s] = ++res;
    upto[s] = N;

    ll temp = N-1;
    check--;

    ch[s][0] = mp(check, 0);

    ll toAssign = 0;

    for(ll i=1; i<=check; i++)
    {
        ll tim = 1+((endd[ok.front()]-beginn[ok.front()]-1)>>1LL); 
        toAssign+=tim;
        temp-=tim;

        ch[s][i] = mp(endd[ok.front()], ok.front());
        upto[s] = temp*tim + upto[s];

        ok.pop();
    }

    ch[s][0].ss = toAssign;
}

ll binSearch(auto &uni, ll first, ll second)
{
    if(first == second)
    {
        return first;
    }

    ll low = 1;
    ll high = uni[0].ff;

    ll cur = endd[first];

    while(low <= high)
    {
        ll mid = low + ((high-low)>>1LL);
        
        if(uni[mid].ff == cur)
        {
            return uni[mid].ss;
        }

        else if((low == mid || uni[mid-1].ff < cur) && uni[mid].ff > cur)
        {
            return uni[mid].ss;
        }

        else if(uni[mid].ff <= cur)
        {
            low = mid+1;
        }

        else
        {
            high = mid-1;
        }
    }

    assert(false);
    // return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T;
    cin >> T;

    while(T--)
    {
        ll N, Q;
        cin >> N >> Q;

        vector < vector <ll> > adj(N+5);
        vector < pll * > ch(N+5);
        vector <bool> v(N+5, false);

        for(ll i=0; i<N-1; i++)
        {
            ll u, v;
            cin >> u >> v;

            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }

        ll res = 0;

        dfsFinal(0, adj, ch, v, res, N);

        for(ll i=0; i<N; i++)
        {
            v[i] = false;
        }

        ans[0] = upto[0];

        dfsCheck(0, adj, ch, v, N);

        node lca(adj);

        while(Q--)
        {
            ll u, v;
            cin >> u >> v;

            if(u == 1)
            {
                cout << ans[v-1] << endl;
            }

            else if(v == 1)
            {
                cout << ans[u-1] << endl;
            }

            else if(u == v)
            {
                cout << upto[u-1] << endl;
            }

            else
            {
                ll cur = lca.lca(u-1, v-1);
                
                u--;
                v--;
                
                if(cur == v)
                {
                    ll var = binSearch(ch[cur], u, cur);

                    ll tim = 1 + ((endd[var] - beginn[var] - 1)>>1LL);

                    ll toPrint = ans[u];
                    toPrint+=upto[cur];

                    ll temp = ((N-1-ch[cur][0].ss)*tim);
                    temp+=ans[cur];

                    cout << toPrint - temp << endl;   
                }

                else if(cur == u)
                {
                    ll var = binSearch(ch[cur], v, cur);

                    ll tim = 1 + ((endd[var] - beginn[var] - 1)>>1LL);

                    ll toPrint = ans[v];
                    toPrint+=upto[cur];

                    ll temp = ((N-1-ch[cur][0].ss)*tim);
                    temp+=ans[cur];

                    cout << toPrint - temp << endl; 
                }

                else
                {
                    ll first = binSearch(ch[cur], u, cur);
                    ll second = binSearch(ch[cur], v, cur);

                    ll tim1 = 1 + ((endd[first] - beginn[first] - 1)>>1LL);
                    ll tim2 = 1 + ((endd[second] - beginn[second] - 1)>>1LL);

                    ll toPrint = ans[u];
                    toPrint+=upto[cur];
                    toPrint+=ans[v];
                    toPrint+=(tim1*tim2);

                    ll temp = ans[cur];
                    temp <<= 1LL;
                    temp+=(tim1*(N-1-ch[cur][0].ss));
                    temp+=(tim2*(N-1-ch[cur][0].ss));

                    cout << toPrint - temp << endl;
                }
            }
        }
    }
    return 0;
}