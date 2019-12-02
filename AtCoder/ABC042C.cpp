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

vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, K;
    cin >> N >> K;

    for(ll i=0; i<K; i++)
    {
        ll a;
        cin >> a;

        v.pb(a);
    }

    ll t = N;
    while(1)
    {
        ll temp = t;

        ll flag = 0;
        while(temp)
        {
            flag = 0;
            ll cur = temp%10;

            for(ll i=0; i<sz(v); i++)
            {
                if(cur==v[i])
                {
                    flag = 1;
                    break;
                }
            }

            if(flag)
            {
                break;
            }

            temp/=10;
        }

        if(flag==0)
        {
            cout << t << endl;
            return 0;
        }

        t++;
    }

    return 0;
}