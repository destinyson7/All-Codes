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

const ll L = 1e5+5;

void dfs(ll i, ll j, char c, vector <string>& maze)
{
    if(maze[i][j] == c || maze[i][j] == '#')
    {
        return;
    }

    maze[i][j] = '#';

    dfs(i+1, j, c, maze);
    dfs(i-1, j, c, maze);
    dfs(i, j+1, c, maze);
    dfs(i, j-1, c, maze);
}

void solve()
{
    string s, end;

    vector <string> maze;

    while(true)
    {
        getline(cin, s);

        if(s[0] == '_')
        {
            end = s;
            // cout << end << endl;
            break;
        }

        // cout << s << endl;

        maze.pb(s);
    }

    // cout << "haha" << endl;

    ll rows = sz(maze);

    if(rows == 0)
    {
        return;
    }

    // ll columns = sz(maze[0]);

    char c = ' ';

    for(ll i=0; i<rows; i++)
    {
        for(ll j=0; maze[i][j] != '\0'; j++)
        {
            if(maze[i][j] != '*' && maze[i][j] != ' ' && maze[i][j] != '_')
            {
                c = maze[i][j];
                break;
            }
        }

        if(c != ' ')
        {
            break;
        }
    }

    // cout << "**********" << endl;

    // cout << c << " " << rows << endl;

    for(ll i=0; i<rows; i++)
    {
        for(ll j=0; maze[i][j] != '\0'; j++)
        {
            if(maze[i][j] == '*')
            {
                dfs(i, j, c, maze);
            }
        }
    }

    for(ll i=0; i<rows; i++)
    {
        // cout << "** ";
        if(maze[i][0])
            cout << maze[i] << endl;
    }
    cout << end << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t;
    cin >> t;

    // cout << "haha" << endl;

    while(t--)
    {
        solve();
    }

    return 0;
}