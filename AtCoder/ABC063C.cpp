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

const ll L = 1e2+5;

vector <ll> s(L);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N;
    cin >> N;

    ll sum = 0;
    ll flag = 0;

    for(ll i=0; i<N; i++)
    {
        cin >> s[i];
        sum+=s[i];
        
        if(s[i]%10!=0)
        {
            flag=1;
        }
    }

    if(flag)
    {
        if(sum%10!=0)
        {
            cout << sum << endl;
        }       

        else
        {
            ll ans = 0;
            for(ll i=0; i<N; i++)
            {
                if(s[i]%10!=0)
                {
                    ans = max(ans, sum-s[i]);
                }
            }

            cout << ans << endl;
        }
    }

    else
    {
        cout << 0 << endl;
    }

    return 0;
}