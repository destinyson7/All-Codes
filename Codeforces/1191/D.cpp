#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b, a%b);
}

const ll L = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    vector <ll> a;

    map <ll, ll> m;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);

        m[t]++;
    }

    ll check = 0;

    for(auto i: m)
    {
        if(i.ss > 2)
        {
            cout << "cslnb" << endl;
            return 0;
        }

        if(i.ss == 2)
        {
            check++;
        }
    }

    if(check > 1)
    {
        cout << "cslnb" << endl;
        return 0;
    }

    sort(all(a));

    ll cnt = 0;

    if(check == 1)
    {
        ll tell = -1;

        for(ll i=0; i<n-1; i++)
        {
            if(a[i] == a[i+1])
            {
                tell = i;
                break;
            }
        }

        if(a[tell]==0 || m[a[tell]-1] == 1)
        {
            // cout << "herE" << endl;
            cout << "cslnb" << endl;
            return 0;
        }

        a[tell]--;
        cnt++;
    }
    // vector <ll> p(n, 0);
    // p[0] = a[0];

    // for(ll i=1; i<n; i++)
    // {
    //     p[i] = a[i] - a[i-1];
    // }

    cnt += a[0];
    a[0] = 0;

    for(ll i=1; i<n; i++)
    {

        // if(a[i] != a[i-1])
        // {
            cnt+=(a[i]-a[i-1]-1);
            a[i] = a[i-1]+1;
        // }
        // cout << i << " " << cnt << endl;
    }

    // for(ll i=0; i<n; i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << cnt << endl;

    if(cnt&1)
    {
        cout << "sjfnb" << endl;
    }

    else
    {
        cout << "cslnb" << endl;
    }

    return 0;
}