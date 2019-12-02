#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define endl "\n"

const ll L = 1e5+5;

vector <ll> a(L);
// vector <ll> b(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, x;
    cin >> N >> x;

    for(ll i=0; i<N; i++)
    {
        cin >> a[i];
        // b[i] = a[i];
    }

    ll cnt = 0;
    if(a[0]>x)
    {
        cnt+=(a[0]-x);
        a[0] = x;
    }
    for(ll i=1; i<N; i++)
    {
        if(a[i]+a[i-1]>=x)
        {
            cnt+=(a[i]-x+a[i-1]);
            a[i] = x-a[i-1];
        }
    }

    // for(ll i=0; i<N; i++)
    // {
    //     cout << a[i] << endl;
    // }

    cout << cnt << endl;

    return 0;
}