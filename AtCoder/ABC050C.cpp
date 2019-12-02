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

vector <ll> A(L);
vector <ll> cnt(L);

ll modexp(ll a, ll b, ll mod)
{
    a%=mod;
    
    ll ans = 1;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%mod;
        }

        a = (a*a)%mod;
        b>>=1;
    }   

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll mod = 1e9+7;

    ll N;
    cin >> N;

    for(ll i=1; i<=N; i++)
    {
        cin >> A[i];

        cnt[A[i]]++;
    }

    if(N&1)
    {
        if(cnt[0]!=1)
        {
            cout << "0" << endl;
            return 0;
        }
        
        for(ll i=1; i<N; i++)
        {
            if(i&1)
            {
                if(cnt[i]!=0)
                {
                    cout << "0" << endl;
                    return 0;
                }
            }

            else
            {
                if(cnt[i]!=2)
                {
                    cout << "0" << endl;
                    return 0;
                }
            }
        }
    }

    else
    {
        for(ll i=0; i<N; i++)
        {
            if(i&1)
            {
                if(cnt[i]!=2)
                {
                    cout << "0" << endl;
                    return 0;
                }
            }
            
            else
            {
                if(cnt[i]!=0)
                {
                    cout << "0" << endl;
                    return 0;
                }

            }
        }
    }

    cout << modexp(2, N/2, mod) << endl;

    return 0;
}