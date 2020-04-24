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

// vector <ll> can[10];

void solve()
{
    ll n = nxt(), kk = nxt();   

    // can[0] = {0, 8, -1, -1, -1, -1, -1, -1};
    // can[1] = {1, 7, 4, 3, 9, 8, -1, -1};
    // can[2] = {2, -1, 8, -1, -1, -1, -1, -1};
    // can[3] = {3, 9, 8, -1, -1, -1, -1, -1};
    // can[4] = {4, -1, 9, 8, -1, -1, -1, -1};
    // can[5] = {5, 9, 8, -1, -1, -1, -1, -1};
    // can[6] = {6, 8, -1, -1, -1, -1, -1, -1};
    // can[7] = {7, -1, 3, 9, 8, -1, -1, -1};
    // can[8] = {8, -1, -1, -1, -1, -1, -1, -1};
    // can[9] = {9, 8, -1, -1, -1, -1, -1, -1};

    // map <string, ll> m;
    // m["1110111"] = 0;
    // m["0010010"] = 1;
    // m["1011101"] = 2;
    // m["1011011"] = 3;
    // m["0111010"] = 4;
    // m["1101011"] = 5;
    // m["1101111"] = 6;
    // m["1010010"] = 7;
    // m["1111111"] = 8;
    // m["1111011"] = 9;

    vector <vector<ll>> cur(n, vector <ll>(10, 0));
    vector <vector<bool>> can(n+1, vector<bool>(kk+1, false));
    can[n][0] = true;

    vector <string> check = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

    for(ll i=0; i<n; i++)
    {
        string s;
        cin >> s;
        
        for(ll j=0; j<10; j++)
        {
            for(ll k=0; k<7; k++)
            {
                if(check[j][k] == '1' && s[k] == '0')
                {
                    cur[i][j]++;
                }

                else if(check[j][k] == '0' && s[k] == '1')
                {
                    cur[i][j] = -1;
                    break;
                }
            }

            // cout << cur[i][j] << endl;
        }
    }
    // cout << "**" << endl;

    for(ll i=n-1; i>=0; i--)
    {
        set <ll> possibles;

        for(ll j=0; j<10; j++)
        {
            if(cur[i][j] >= 0)
            {
                possibles.insert(cur[i][j]);
            }
        }

        for(auto j: possibles)
        {
            for(ll k=0; k+j <= kk; k++)
            {
                can[i][k+j] = can[i][k+j] || can[i+1][k];
                // cout << (can[i][k+j] == true) << endl;
            }
        }
    }

    // for(ll i=0; i<n; i++)
    // {
    //     ll ma = nums[i];
    //     ll req = 0;

    //     for(ll j=0; j<=min(k, 7LL); j++)
    //     {
    //         if(can[nums[i]][j] > ma)
    //         {
    //             ma = can[nums[i]][j];
    //             req = j;
    //         }

    //     }
        
    //     k -= req;
    //     nums[i] = ma;


    //     cout << k << " " << nums << endl;

    //     if(k == 0)
    //     {
    //         break;
    //     }
    // }

    // if(k > 0)
    // {
    //     for(ll i=n-1; i>=0; i--)
    //     {
    //         if(nums[i] == 9)
    //         {
    //             k--;
    //             nums[i] = 8;
    //         }

    //         if(k == 0)
    //         {
    //             break;
    //         }
    //     }
    // }

    // assert(k >= 0);

    // if(k > 0)
    // {
    //     cout << -1 << endl;
    //     return;
    // }

    // for(ll i=0; i<n; i++)
    // {
    //     cout << nums[i];
    // }
    // cout << endl;

    if(!can[0][kk])
    {
        cout << -1 << endl;
        return;
    }

    string ans = "";

    for(ll i=0; i<n; i++)
    {
        for(ll j=9; j>=0; j--)
        {
            if(cur[i][j] >= 0)
            {
                if(cur[i][j] <= kk)
                {
                    if(can[i+1][kk-cur[i][j]])
                    {
                        kk -= cur[i][j];
                        ans += (j+48);
                        break;
                    }
                }
            }
        }
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