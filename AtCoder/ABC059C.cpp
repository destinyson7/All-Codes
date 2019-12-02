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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;

    for(ll i=0; i<n; i++)
    {
        cin >> a[i];
    }

    ll cur = a[0];

    ll ans = 0;
    if(cur==0)
    {
        ans++;
        a[0]++;
    }

    for(ll i=1; i<n; i++)
    {
        if(cur*(cur+a[i])>=0)
        {
            if(cur+a[i]==0)
            {
                if(cur<0)
                {
                    a[i]++;     
                }

                else
                {
                    a[i]--;
                }

                ans++;
            }

            else
            {
                if(cur<0)
                {
                    ll temp = a[i];
                    a[i] = 1-cur;
                    ans+=abs(temp-a[i]);
                }

                else
                {
                    ll temp = a[i];
                    a[i] = -1-cur;
                    ans+=abs(temp-a[i]);
                }
            }
        }

        cur+=a[i];
    }

    cout << ans << endl;

    return 0;
}