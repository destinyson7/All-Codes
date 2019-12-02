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

ll sum(ll n)
{
    if(n<0)
    {
        return 0;
    }

    return (n*(n+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, k;
    cin >> n >> k;

    n--;
    k--;

    if(!n)
    {
        cout << n << endl;
        return 0;
    }

    if(sum(k) < n)
    {
        cout << -1 << endl;
        return 0;
    }


    ll low = 1;
    ll high = k;

    ll ans = sum(k)+1;

    while(low <= high)
    {
        ll mid = low + (high-low)/2;

        ll cal = sum(k) - sum(mid-1);
        
        if(cal > n)
        {
            low = mid+1;
        }

        else if(cal < n)
        {
            if(n-cal < mid)
            {
                ans = min(ans, k-(mid-1)+1);
            }

            high = mid-1;
        }

        else
        {
            ans = min(ans, k-(mid-1));
            break;
        }
    }

    cout << ans << endl;


    return 0;
}