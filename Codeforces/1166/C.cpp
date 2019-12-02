#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define pll pair <ll, ll>
#define gcd __gcd
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 2e5+5;

ll a[L];

ll binSearch(ll start, ll end, ll n)
{
    if(start > end)
    {
        return -1;
    }

    ll mid = start + (end - start)/2;

    if(a[mid]<=n)
    {
        if(mid == end || a[mid+1]>n)
        {
            return mid;
        }

        else
        {
            return binSearch(mid+1, end, n);
        }
    }

    return binSearch(start, mid-1, n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(a, a+n);

    ll res = 0;

    for(ll i=0; i<n; i++)
    {
        ll t = binSearch(i+1, n-1, a[i]*2);

        if(t!=-1)
        {
            res+=(t-i);
        }
    }

    cout << res << endl;

    return 0;
}