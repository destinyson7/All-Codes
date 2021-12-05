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

ll matrices[1000][5][5];
bool done[1000][5][5];
ll row_done[1000][5];
ll col_done[1000][5];

void solve()
{
    ll num;

    vector <ll> queries;

    while(cin >> num)
    {
        if(num == -1)
        {
            break;
        }

        queries.pb(num);
    }

    cout << queries << endl;

    map <ll, vector<pair<ll, pll>>> positions;
    ll cnt_matrices = 0, row_cnt = 0, col_cnt = 0;


    while(cin >> num)
    {
        matrices[cnt_matrices][row_cnt][col_cnt] = num;
        positions[num].pb(mp(cnt_matrices, mp(row_cnt, col_cnt)));

        col_cnt++;

        if(col_cnt == 5)
        {
            col_cnt = 0;
            row_cnt++;

            if(row_cnt == 5)
            {
                row_cnt = 0;
                cnt_matrices++;
            }
        }
    }

    assert(col_cnt == 0);
    assert(row_cnt == 0);

    set <ll> done_matrices;

    for(auto q: queries)
    {
        for(auto i: positions[q])
        {
            ll matrix_ind = i.ff;
            ll row_ind = i.ss.ff;
            ll col_ind = i.ss.ss;

            done[matrix_ind][row_ind][col_ind] = true;

            row_done[matrix_ind][row_ind]++;

            if(row_done[matrix_ind][row_ind] == 5)
            {
                done_matrices.insert(matrix_ind);
            }

            col_done[matrix_ind][col_ind]++;

            if(col_done[matrix_ind][col_ind] == 5)
            {
                done_matrices.insert(matrix_ind);
            }

            if(sz(done_matrices) == cnt_matrices)
            {
                ll sum = 0;

                // for(ll aa = 0; aa < cnt_matrices; aa++)
                // {
                    for(ll bb = 0; bb < 5; bb++)
                    {
                        for(ll cc = 0; cc < 5; cc++)
                        {
                            if(!done[matrix_ind][bb][cc])
                            {
                                sum += matrices[matrix_ind][bb][cc];
                            }
                        }
                    }
                // }

                cout << sum * q << endl;
                exit(0);
            }

        }
    }
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
