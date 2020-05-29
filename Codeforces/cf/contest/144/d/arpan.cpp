#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo        \
    {              \
        no return; \
    }

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template <typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false)
{
    vector<T> a = vector<T>(n + oneIndexed);

    for (ll i = 0; i < n; i++)
    {
        T p;
        cin >> p;
        a[i + oneIndexed] = p;
    }

    return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1)
{
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++)
    {
        // printf("%lu ", a[i]);
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T, typename A>
void papair(vector<T, A> const &a, ll begin = 0, ll end = -1)
{
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++)
    {
        // printf("%lu ", a[i]);
        cout << a[i].first << " " << a[i].second << endl;
    }
}

priority_queue<pll, vector<pll>, greater<pll>> q;
v parent(5e5, -1);
v distances(5e5, 1e15);
vb visited(5e5, false);
void djikstra(ll src, const vspll &adjList)
{
    distances[src] = 0;
    q.push({0, src});
    ll n = sz(adjList) - 1;

    while (!q.empty())
    {
        auto x = q.top();
        auto node = x.second;
        auto d = distances[node];
        q.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        for (const auto &neigh : adjList[node])
        {
            ll d2 = d + neigh.second;

            if (distances[neigh.first] > d2)
            {
                distances[neigh.first] = d2;
                parent[neigh.first] = node;
                q.push({d2, neigh.first});
            }
        }
    }
}

void solve()
{
    ll n, m, s;
    cin >> n >> m >> s;
    // vector<ll> arr = ga(n);
    // ll n, m;
    // cin >> n >> m;

    vspll adjList(n + 1);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adjList[a].insert({b, c});
        adjList[b].insert({a, c});
    }
    ll l;
    cin >> l;

    djikstra(s, adjList);
    ll count = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (distances[i] == l)
        {
            count++;
            // continue;
        }
        for (auto neigh : adjList[i])
        {
            if (i > neigh.first)
                continue;
            // cout << i << " " << neigh.first << '\n';
            // cout << distances[i] << " " << distances[neigh.first] << " " << neigh.second << " " << count << '\n';
            // cout << (abs(distances[i] - distances[neigh.first]) == neigh.second) << '\n';
            // cout << (distances[i] == l || distances[neigh.first] == l) << '\n';
            if (abs(distances[i] - distances[neigh.first]) == neigh.second && (distances[i] == l || distances[neigh.first] == l))
            {
                continue;
                // cout << "OKKK\n";
            }
            if ((distances[i] > l && distances[neigh.first] < l) || (distances[i] < l && distances[neigh.first] > l))
            {
                count++;
            }
            else
            {
                if (distances[i] < l && neigh.second > (l - distances[i]))
                {
                    if (distances[i] + (neigh.second - (l - distances[neigh.first])) > l)
                    {
                        // cout << "yo1\n";
                        count++;
                    }
                }
                if (distances[neigh.first] < l && neigh.second > (l - distances[neigh.first]))
                {
                    if (distances[i] + (neigh.second - (l - distances[neigh.first])) >= l)
                    {
                        // cout << "yo2\n";
                        count++;
                    }
                }
            }
        }
    }
    cout << count;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}