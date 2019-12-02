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

ll k[L];

vector <ll> adj[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n, m;
    cin >> n >> m;

    ll moneyNeeded = 0;
    for(ll i=0; i<n; i++)
    {
        cin >> k[i];
        moneyNeeded+=(2*k[i]);
    }

    for(ll i=0; i<m; i++)
    {
        ll d, t;
        cin >> d >> t;

        adj[t-1].pb(d-1);
    }

    ll low = 0;
    ll high = moneyNeeded;

    while(low < high)
    {
        ll mid = low + (high-low)/2;

        vector <ll> sales(mid);

        for(ll t=0; t<n; t++)
        {
            ll latest = -1;

            for(auto i: adj[t])
            {
                // i is 0 indexed so '<' and not '<='
                if(i < mid)
                {
                    latest = max(latest, i);
                }
            }

            if(latest!=-1)
            {
                sales[latest]+=k[t];
            }
        }

        // sort(all(sales));
        // reverse(all(sales));

        ll cur = mid;
        ll savings = 0;

        for(ll i=mid-1; i>=0; i--)
        {
            if(sales[i] < cur)
            {
                cur-=sales[i];
                savings+=sales[i];
            }

            cur--;
        }

        for(ll i=0; i<mid; i++)
        {
            cur++;

            if(sales[i] <= cur)
            {
                cur-=sales[i];
                savings+=sales[i];
            }
        }

        ll nowMoney = moneyNeeded - savings;

        // cout << savings << " " << nowMoney << " " << mid << endl;

        if(nowMoney <= mid)
        {
            high = mid;
        }

        else
        {
            low = mid+1;
        }
    }

    cout << low << endl;

    return 0;
}