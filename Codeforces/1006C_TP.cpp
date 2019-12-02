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

const ll L = 2e5+5;

vector <ll> d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        d.pb(t);
    }

    if(n==1)
    {
        cout << 0 << endl;
        return 0;
    }

    ll start = 0;
    ll end = n-1;

    ll ans = 0;

    ll sum1 = d[0];
    ll sum3 = d[n-1];

    if(sum1 == sum3)
    {
        ans = sum1;
    }

    while(start < end)
    {
        // if(sum1 == sum3)
        // {
        //     ans = sum1;

        //     start++;
        //     end--;

        //     sum1+=d[start];
        //     sum3+=d[end];
        // }

        if(sum1 > sum3)
        {
            end--;
            sum3+=d[end];
        }

        else if(sum1 < sum3)
        {
            start++;
            sum1+=d[start];
        }

        else if(sum1 == sum3)
        {
            ans = sum1;

            start++;
            end--;

            sum1+=d[start];
            sum3+=d[end];
        }
    }

    cout << ans << endl;

    return 0;
}