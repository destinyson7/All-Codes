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

const ll L = 26 + 5;

typedef struct node 
{
    vector <node*> next = vector <node *>(L);
    ll cnt = 0;
} node;

node *head = new node;
string s;

ll f(char ch)
{
    if(ch == '#')
    {
        return (L - 5);
    }

    else
    {
        return ch - 'A';
    }
}

void insert(node* cur, ll pos)
{
    if(cur == NULL)
    {
        cur = head;
        s += "#";
    }

    (cur -> cnt)++;

    if(pos >= sz(s))
    {
        return;
    }

    if(cur->next[f(s[pos])] == NULL)
    {
        cur->next[f(s[pos])] = new node;   
    }

    insert(cur->next[f(s[pos])], pos+1);
}

ll N, K;

pll dfs(node* cur, ll d)
{
    pll ans = mp(0, 0);

    for(ll i=0; i<L-5; i++)
    {
        if(cur->next[i] != NULL)
        {
            pll temp = dfs(cur->next[i], d+1);
            ans.ff += temp.ff;
            ans.ss += temp.ss;
        }
    }

    if(cur->next[L-5] != NULL)
    {
        ans.ss += cur->next[L-5]->cnt;
    }

    ans.ff += ((ans.ss/K) * d);
    ans.ss %= K;

    return ans;
}

void solve(ll tc)
{
    cin >> N >> K;   
    head = new node;

    for(ll i=0; i<N; i++)
    {
        cin >> s;
        insert(NULL, 0);
    }

    cout << "Case #" << tc << ": " << dfs(head, 0).ff << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll T = 1;
    T = nxt();

    for(ll i=1; i<=T; i++)
    {
        solve(i);
    }

    return 0;
}