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

const ll L = 5e4+5;

ll a[L];

typedef struct segTree
{
    ll prefix, suffix, sum, maxx;
} segTree;

segTree seg[4*L];

void make(ll i, ll tl, ll tr)
{
    if(tl == tr)
    {
        seg[i].sum = a[tl];
        seg[i].prefix = a[tl];
        seg[i].suffix = a[tl];
        seg[i].maxx = a[tl];

        return;
    }

    ll mid = tl + (tr-tl)/2;

    make(i<<1, tl, mid);
    make(i<<1|1, mid+1, tr);

    seg[i].sum = seg[i<<1].sum + seg[i<<1|1].sum;
    seg[i].prefix = max(seg[i<<1].prefix, seg[i<<1].sum + seg[i<<1|1].prefix);
    seg[i].suffix = max(seg[i<<1|1].suffix, seg[i<<1].suffix + seg[i<<1|1].sum);
    seg[i].maxx = max(seg[i<<1].maxx, max(seg[i<<1|1].maxx, seg[i<<1].suffix+seg[i<<1|1].prefix));
}

void update(ll i, ll tl, ll tr, ll idx, ll val)
{
    if(tl == tr)
    {
        seg[i] = {val, val, val, val};
        return;
    }

    ll mid = tl + (tr-tl)/2;

    if(tl<=idx && idx<=mid)
    {
        update(i<<1, tl, mid, idx, val);
    }

    else
    {
        update(i<<1|1, mid+1, tr, idx, val);
    }

    seg[i].sum = seg[i<<1].sum + seg[i<<1|1].sum;
    seg[i].prefix = max(seg[i<<1].prefix, seg[i<<1].sum + seg[i<<1|1].prefix);
    seg[i].suffix = max(seg[i<<1|1].suffix, seg[i<<1].suffix + seg[i<<1|1].sum);
    seg[i].maxx = max(seg[i<<1].maxx, max(seg[i<<1|1].maxx, seg[i<<1].suffix+seg[i<<1|1].prefix));
}

segTree query(ll i, ll tl, ll tr, ll l, ll r)
{
    if(l>tr || r<tl)
    {
        ll m = -1e15;
        return {0, m, m, m};
    }

    if(l<=tl && tr<=r)
    {
        return seg[i];
    }

    ll mid = tl + (tr-tl)/2;

    segTree le = query(i<<1, tl, mid, l, r);
    segTree ri = query(i<<1|1, mid+1, tr, l, r);

    segTree temp;

    temp.sum = le.sum + ri.sum;
    temp.prefix = max(le.prefix, le.sum + ri.prefix);
    temp.suffix = max(ri.suffix, le.suffix + ri.sum);
    temp.maxx = max(le.maxx, max(ri.maxx, le.suffix + ri.prefix));

    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    for(ll i=1; i<=N; i++)
    {
        cin >> a[i];
    }

    ll M;
    cin >> M;

    make(1, 1, N);

    while(M--)
    {
        ll type, x, y;
        cin >> type >> x >> y;

        if(!type)
        {
            update(1, 1, N, x, y);
        }

        else
        {
            cout << query(1, 1, N, x, y).maxx << endl;
        }
    }

    return 0;
}