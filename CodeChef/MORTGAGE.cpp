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

ll n, m;
double t;
double s[L];
double p[L];

double eps = 1e-7;

priority_queue<pair<double,ll>, vector<pair<double,ll>>, greater<pair<double,ll>>> pq;
queue<pair<double,ll>> q;

bool possible(double x)
{
    vector <double> loan(n+5, (double)0.0);

    double req = x;

    queue <pair<double, ll>> temp = q;
    stack <ll> loans;
    vector <ll> last(n+5, 0);

    while(req)
    {
        if(s[temp.front().ss] > req)
        {
            loan[temp.front().ss] = req;
            loans.push(temp.front().ss);
            req = 0.0;
            break;
        }

        else
        {
            loan[temp.front().ss] = s[temp.front().ss];
            req -= s[temp.front().ss];
            loans.push(temp.front().ss);
        }

        temp.pop();
    }

    ll days = 1;

    double can = t;
    
    while(!loans.empty() && days <= m)
    {
        ll bank = loans.top();
        loan[bank] *= (pow(((double)1.0 + p[bank]), days-last[bank]));

        if(loan[bank] > can)
        {
            loan[bank] -= can;
            last[bank] = days;
            days++;
            can = t;
        }

        else
        {
            can -= loan[bank];
            loan[bank] = 0;
            last[bank] = days;
            loans.pop();
        }
    }

    return (days <= m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> t;

    ll sum = 0;

    for(ll i=0; i<n; i++)
    {
        cin >> s[i];
        
        sum += (ll)s[i];
    }

    for(ll i=0; i<n; i++)
    {
        cin >> p[i];

        p[i] /= (double)(1000000);

        pq.push(mp(p[i], i));
    }

    while(!pq.empty())
    {
        q.push(pq.top());
        pq.pop();
    }

    double low = (double)0.0, high = (double)sum;
    double ans = low;

    ll iter = 0;

    while((high-low > eps) && iter <= 70)
    {
        iter++;

        double mid = ((high+low)/(double)(2.0));

        // cout << low << " " << mid << " " << high << " " << ans << endl;

        if(possible(mid))
        {
            ans = mid;
            low = mid;
        }

        else
        {
            high = mid;
        }
    }

    cout << fixed << setprecision(7) << ans << endl;

    return 0;
}