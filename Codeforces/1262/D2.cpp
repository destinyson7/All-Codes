#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key(val): returns the number of values less than val
// find_by_order(k): returns an iterator to the kth largest element (0-based)

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) 
{
    os << "{ ";
    for(auto& y : x) 
    {
        os << y << " ";
    }
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) 
{
    return os << "[" << p.ff << ", " << p.ss << "]";
}

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

ll modexp(ll a, ll b, ll c)
{   
    a%=c;

    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%c;
        b >>= 1;
    }

    return ans;
}

const ll L = 2e5+5;

bool cmp(pll a, pll b)
{
    if(a.ff == b.ff)
    {
        return a.ss < b.ss; 
    }

    return a.ff > b.ff;
}

ll kd[30][L] , a[L] , pos[L] , Real[L];
 
void init(ll d,ll b,ll e){
    if(b == e){
        kd[d][b] = pos[b];
        return;
    }
    ll m = (b + e) >> 1;
    init(d + 1,b,m);
    init(d + 1,m+1,e);
    ll i = b , j = m + 1;
    ll ptr = 0;
    while(i <= m && j <= e){
        if(kd[d + 1][i] < kd[d + 1][j]){
            kd[d][b + (ptr++)] = kd[d + 1][i++];
        }else{
            kd[d][b + (ptr++)] = kd[d + 1][j++];
        }
    }
    while(i <= m) kd[d][b + (ptr++)] = kd[d + 1][i++];
    while(j <= e) kd[d][b + (ptr++)] = kd[d + 1][j++];
}
 
inline ll find(ll d,ll b,ll e,ll x1,ll x2){
    return upper_bound(kd[d] + b,kd[d] + e + 1,x2) - lower_bound(kd[d] + b,kd[d] + e + 1,x1);
}
 
ll get(ll n,ll x1,ll x2,ll k){
    ll d = 0 , b = 1 , e = n;
    while(b != e){
        ll lll = find(d + 1,b,(b+e)/2,x1,x2);
        ll mm = ((b + e) >> 1LL);
        if(lll >= k){
            e = mm;
        }else{
            b = mm + 1;
            k -= lll;
        }
        ++d;
    }
    return b;
}

ll copy_it[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    vector <ll> a(n, 0);
    // vector <ll> copy_it(n, 0);

    // priority_queue <pll> pq;
    vector <pll> pq;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        copy_it[i] = t;
        // a.pb(t);

        pq.pb(mp(t, i));
    }

    sort(all(pq), cmp);

    vector <ll> vals;
    for(ll i=1; i<=n; i++)
    {
        a[i] = pq[i-1].ss;
        vals.pb(a[i]);
    }

    sort(all(vals));

    for(ll i=1; i<=n; i++)
    {
        ll old = a[i];
        a[i] = lower_bound(all(vals), a[i]) - vals.begin() + 1;
        pos[a[i]] = i;
        Real[a[i]] = old;

        // cout << a[i] << " " << pos[a[i]] << " " << Real[a[i]] << endl;
    }

    init(0, 1, n);

    ll m;
    cin >> m;

    while(m--)
    {
        ll k, which;
        cin >> k >> which;

        cout << copy_it[Real[get(n, 1, k, which)]] << endl;
        // cout << pq[Real[get(n, 1, k, which)]].ff << endl;

        // vector <pll> temp;

        // for(ll i=0; i<k; i++)
        // {
        //     temp.pb(mp((ll)1e9 - pq.top().ss, pq.top().ff));
        //     pq.pop();
        // }

        // for(ll i=0; i<k; i++)
        // {
        //     pq.push(mp(temp[i].ss, (ll)1e9 - temp[i].ff));
        // }

        // sort(all(temp));

        // cout << temp[pos-1].ss << endl;
    }

    return 0;
}