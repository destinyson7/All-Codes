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

vector <ll> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    ll sum = 0;
    ll odd = 0;
    ll even = 0;

    for(ll i=0; i<n; i++)
    {
        ll t;
        cin >> t;

        a.pb(t);
        sum+=t;

        if(t&1)
        {
            odd++;
        }

        else
        {
            even++;
        }
    }

    sort(all(a));

    ll temp = sum;
    ll cnt = 0;

    // cout << "min " << min(odd, even) << endl;

    for(ll i=n-1; i>=0; i--)
    {
        if(cnt == (min(odd, even)+1))
        {
            break;
        }

        if(a[i]&1)
        {
            temp-=a[i];
            cnt++;
        }
        
        // cout << temp << " " << cnt << endl;
    }

    for(ll i=n-1; i>=0; i--)
    {
        if(cnt <= 0)
        {
            break;
        }

        if(!(a[i]&1))
        {
            temp-=a[i];
            cnt--;
        }

        // cout << temp << " " << cnt << endl;
    }

    ll ans = temp;

    temp = sum;
    cnt = 0;

    for(ll i=n-1; i>=0; i--)
    {
        if(cnt == (min(odd, even)+1))
        {
            break;
        }
     
        if(!(a[i]&1))
        {
            temp-=a[i];
            cnt++;
        }

        // cout << temp << endl;
    }

    for(ll i=n-1; i>=0; i--)
    {
        if(cnt <= 0)
        {
            break;
        }
     
        if(a[i]&1)
        {
            temp-=a[i];
            cnt--;
        }
    }

    ans = min(ans, temp);

    cout << ans << endl;

    return 0;
}