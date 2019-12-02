    #include <bits/stdc++.h>
    #include<ext/pb_ds/assoc_container.hpp>
    #include<ext/pb_ds/tree_policy.hpp>
     
    using namespace std ;
    using namespace __gnu_pbds;
     
    template <typename T> // *s.find_by_order(0), s.order_of_key(2) ;
    using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
     
    #define lint long long
     
    #define sz(x) (int)x.size()
    #define all(x) begin(x), end(x)
     
    #define reMin(a, b) a = min(a, b)
    #define reMax(a, b) a = max(a, b);
     
    typedef vector < int > vi ;
    typedef pair < int, int > pii ;
     
    // template <typename T>
    int modpow(int base, int exp, int modulo) {
      base %= modulo;
      int result = 1;
      while (exp > 0) {
        if (exp & 1) result = (result * base) % modulo;
        base = (base * base) % modulo;
        exp >>= 1;
      }
      return result;
    }
     
    const int N = 2e5 + 2 ;
    const int MOD = 1e9 + 7 ;
    const lint INF = 1e18 ;
     
    int cnt[N] ;
    int main()
    {
        int  t; cin >>t ;
        while(t--)
        {
            /*
            lint x, y ; cin >>x >> y ;
            lint two = 2 ;
            if( (x-y) >= two or x == y) cout << "YES\n" ;
            else cout << "NO\n" ;
                */
            int n, r ; cin >> n >> r; int x, last = 0 ; memset(cnt, 0, sizeof(cnt));
            for(int i = 0; i < n; i++)
            {
                cin >> x;
                cnt[x]++ ; reMax(last, x);
            }
            int ans = 0, delta = 0 ; ;
            for(int z = last; z > 0; z--)
            {
                int pos = z + delta ;
                if(pos <= 0) break ;
                if(cnt[z])
                {
                    delta -= r ;
                    ans++ ;
                }
            }
            cout << ans << "\n" ;
        }
    }