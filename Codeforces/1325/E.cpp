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
     
    ll nxt()
    {
        ll x;
        cin >> x;
        return x;
    }
     
    const ll L = 1e5+5;
    vector <ll> vals[L];
    vector <ll> adj[L];
     
    map <ll, ll> ind;
    ll cnt_ind = 0;
     
    void solve()
    {
        ll n = nxt();
        basic_string <ll> a(n, 0);
        generate(all(a), nxt);
     
        ll ans = 1e15;
     
        ll maxa = *max_element(all(a));
        ll sq = sqrt(maxa);
     
        basic_string <ll> bfs_start;
     
        for(ll i=0; i<n; i++)
        {
            for(ll j=2; j*j <= a[i]; j++)
            {
                ll num = 0;
     
                while(a[i] % j == 0)
                {
                    a[i] /= j;
                    num++;
                }
     
                if(num & 1)
                {
                    vals[i].pb(j);
                }
            }
     
            if(vals[i].empty() && a[i] == 1)
            {
                cout << 1 << endl;
                return;
            }
     
            else if(a[i] != 1)
            {
                vals[i].pb(a[i]);
            }
     
            if(sz(vals[i]) == 1)
            {
                vals[i].pb(1);
            }
     
            // cout << a << endls;
            // cout << mp(i, vals[i]) << endl;
     
            assert(sz(vals[i]) == 2);
     
            for(auto j: vals[i])
            {
                if(!ind.count(j))
                {
                    ind[j] = cnt_ind;
     
                    if(j <= sq)
                    {
                        // cout << j << "  " << vals[i] << "  " << cnt_ind << endl;
     
                        bfs_start += cnt_ind;
                    }
                    
                    cnt_ind++;
                }
            }
     
            adj[ind[vals[i][0]]].pb(ind[vals[i][1]]);
            adj[ind[vals[i][1]]].pb(ind[vals[i][0]]);
        }
     
        // cout << adj << endl;
        // cout << bfs_start << endl;
     
        for(auto i: bfs_start)
        {
            basic_string <ll> dist(L, -1);
     
            queue <pll> q;
     
            q.push(mp(i, -1));
     
            dist[i] = 0;
     
            while(!q.empty())
            {
                ll node = q.front().ff;
                ll par = q.front().ss;
     
                q.pop();
     
                bool third_time = false;
     
                for(auto j: adj[node])
                {
                    if(j != par || third_time)
                    {
                        if(dist[j] == -1)
                        {
                            q.push(mp(j, node));
                            dist[j] = dist[node] + 1;
                        }
     
                        else
                        {
                            ans = min(ans, dist[j] + dist[node] + 1);
                        }
                    }
     
                    else
                    {
                        third_time = true;
                    }
                }
            
            }
        }
     
        if(ans == 1e15)
        {
            ans = -1;
        }
     
        cout << ans << endl;
        
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        
        ll T = 1;
        // T = nxt();
     
        while(T--)
        {
            solve();
        }
     
        return 0;
    }