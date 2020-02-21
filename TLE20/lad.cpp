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
     
    const ll L = 1e3+5;
     
    ll f[L][L];
    ll ans[L];
     
    void ini(ll n)
    {
        set <ll> p;

        for(ll i=1; i<=n; i++)
        {
            p.insert(i);
        }

        // random_shuffle(all(p));

        for(ll i = 0; i < n; i++)
        {
            if(i & 1)
            {
                ans[i] = *p.begin();
                p.erase(p.begin());
            }

            else
            {
                ans[i] = *--p.end();
                p.erase(ans[i]);
            }
        }
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
     
        ll n, t;
        cin >> n >> t;
     
        ini(n);
     
        for(ll i = 1; i <= n; i++)
        {
            for(ll j = 1; j <= n; j++)
            {
                cin >> f[i][j];
            }
        }
     
        ll each = n/t;
        
        for(ll i = 1; i <= n; i++)
        {
            ll store = 0;
     
            for(ll j = 0; j < n; j++)
            {
                if(ans[j] == i)
                {
                    store = j;
                    break;
                }
            }
     
            ll ma = 0, ind = -1;
            
            for(ll j = 0; j < n; j++)
            {
     
                if((j/each) != (store/each))
                {
                    ll start = each * (j/each);
                    ll end = each * (j/each + 1) - 1;
     
                    ll cur = 0;
     
                    for(ll k = start; k <= end; k++)
                    {
                        if(j == k)
                        {
                            continue;
                        }
     
                        cur += (f[i][ans[k]] + f[ans[k]][i]);
                        cur -= (f[ans[j]][ans[k]] + f[ans[k]][ans[j]]);
                    }
     
                    start = each * (store/each);
                    end = each * (store/each + 1) - 1;
                
                    for(ll k = start; k <= end; k++)
                    {
                        if(store == k)
                        {
                            continue;
                        }
     
                        cur += (f[ans[k]][ans[each]] + f[ans[each]][ans[k]]);
                        cur -= (f[i][ans[k]] + f[ans[k]][i]);
                    }
     
                    if(cur > ma)
                    {
                        ind = j;
                        ma = cur;
                    }
     
                    // cout << cur << " " << ind << " " << ma << endl;
                }
            }
     
            if(ma != 0)
            {
                swap(ans[ind], ans[store]);
            }
        }
     
        for(ll i = 0; i < n; i++)
        {
            cout << ans[i] - 1 << " ";
     
            if(i % t == (t - 1))
            {
                cout << endl;
            }        
        }
        cout << endl;
     
        ll cost = 0;
     
        for(ll i = 0; i < t; i++)
        {
            for(ll j = 0; j < each; j++)
            {
                for(ll k = j + 1; k < each; k++)
                {
                    cost += f[ans[each * i + j]][ans[each * i + k]];
                }
            }
        }
     
        cout << cost << endl;
     
     
        return 0;
    }