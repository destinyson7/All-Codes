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

const ll L = 1e5+5;

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T;
    cin >> T;

    while(T--)
    {
        string s;
        cin >> s;

        ll maxu = 0, maxd = 0, maxl = 0, maxr = 0;
        ll up = 0, right = 0;

        ll len = sz(s);

        for(ll i=0; i<len; i++)
        {
            if(s[i] == 'W')
            {
                up++;

                maxu = max(maxu, up);
            }

            else if(s[i] == 'S')
            {
                up--;
                
                if(up < 0)
                {
                    maxd = max(maxd, -up);
                }
            }

            else if(s[i] == 'A')
            {
                right--;

                if(right < 0)
                {
                    maxl = max(maxl, -right);
                }
            }

            else
            {
                right++;

                maxr = max(maxr, right);
            }

            // cout << up << " " << right << endl;
        }

        // cout << maxu << " " << maxd << " " << maxl << " " << maxr << endl;

        ll ans = (maxu+maxd+1)*(maxr+maxl+1);

        up = 0, right = 0;

        ll firstu = 0, firstd = 0, lastu = 0, lastd = 0;

        for(ll i=0; i<len; i++)
        {
            if(s[i] == 'W')
            {
                up++;
            }

            else if(s[i] == 'S')
            {
                up--;
            }

            if(up == maxu)
            {
                lastu = i;
            }

            if(up == -maxd)
            {
                lastd = i;
            }
        }

        bool f1 = false, f2 = false;

        up = 0;

        for(ll i=0; i<len; i++)
        {
            if(s[i] == 'W')
            {
                up++;
            }

            else if(s[i] == 'S')
            {
                up--;
            }

            if(!f1 && up == maxu)
            {
                firstu = i;
                f1 = true;
            }

            if(!f2 && up == -maxd)
            {
                firstd = i;
                f2 = true;
            }
        }

        if(((lastu < firstd) && maxd)|| ((lastd < firstu) && maxu))
        {
            ans = min(ans, max(2LL, maxu + maxd)*(maxl+maxr+1));
        }

        up = 0, right = 0;

        ll firstr = 0, firstl = 0, lastr = 0, lastl = 0;

        for(ll i=0; i<len; i++)
        {
            if(s[i] == 'A')
            {
                right--;
            }

            else if(s[i] == 'D')
            {
                right++;
            }

            if(right == maxr)
            {
                lastr = i;
            }

            if(right == -maxl)
            {
                lastl = i;
            }
        }

        f1 = false, f2 = false;
        right = 0;

        for(ll i=0; i<len; i++)
        {
            if(s[i] == 'A')
            {
                right--;
            }

            else if(s[i] == 'D')
            {
                right++;
            }

            if(!f1 && right == maxr)
            {
                firstr = i;
                f1 = true;
            }

            if(!f2 && right == -maxl)
            {
                firstl = i;
                f2 = true;
            }
        }

        if(((lastr < firstl) && maxl) || ((lastl < firstr) && maxr))
        {
            ans = min(ans, max(2LL, maxr + maxl)*(maxu+maxd+1));
        }

        cout << ans << endl;
    }

    return 0;
}