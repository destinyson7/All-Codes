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

const ll L = 3e5+5;
const ll mod = 1e9+7;

ll S[L];
ll pro[L];
ll fact[L];
ll fact2[L];

map <ll, ll> cnt;

ll modmul(ll a, ll b, ll c)
{
    ll ans = 0;

    a%=mod;

    while(b)
    {
        if(b&1)
        {
            ans = (ans+a)%c;
        }

        a = (a+a)%mod;
        b>>=1;
    }

    return ans;
}

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;

    a%=mod;

    while(b)
    {
        if(b&1)
        {
            ans = (ans*a)%c;
        }

        a = (a*a)%mod;
        b>>=1;
    }

    return ans;
}

void factorial()
{
    fact[0] = 1;
    fact2[0] = modexp(fact[0], mod-2, mod);

    for(ll i=1; i<L; i++)
    {
        fact[i] = modmul(fact[i-1], i, mod);

        fact2[i] = modexp(fact[i], mod-2, mod);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    factorial();

    ll N, Q;
    cin >> N >> Q;

    pro[0] = 1;

    for(ll i=0; i<N; i++)
    {
        cin >> S[i];

        cnt[S[i]]++;

        if(i)
        {
            if(cnt[S[i]] > 1)
            {
                pro[i] = modmul(pro[i-1], modexp(cnt[S[i]], mod-2, mod), mod);
            }

            else
            {
                pro[i] = pro[i-1];
            }
        }
    }

    ll ans = 0;

    while(Q--)
    {
        ll L1, L2, R1, R2;
        cin >> L1 >> L2 >> R1 >> R2;

        ll l = (L1*ans + L2)%N;
        ll r = (R1*ans + R2)%N;
        // cout << ans << " " << l << " " << r << endl;
        if(l > r)
        {
            swap(l, r);
        }

        ll t = r-l+1;

        ans = fact[t];

        // cout << l << " " << r << " " << ans << endl;

        if(l)
        {
            ans = modmul(ans, pro[l-1], mod);
            // cout << "if " << ans << endl;
        }

        ll temp = modexp(pro[r], mod-2, mod);
        // cout << temp << endl;

        ans = modmul(ans, temp, mod);

        cout << ans << endl;

        // cout << endl << endl;
    }


    

    return 0;
}