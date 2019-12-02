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

const ll M = 1e5+5;
const ll mod = 1e9+7;
int block = 600;

ll S[M];
// ll pro[M];
ll fact[M];
// ll fact2[M];
ll res[M];

map <ll, ll> cnt;

ll answer = 1;

struct node
{
    ll L, R, i;
} q[M];

ll num = 1;

bool cmp(node a, node b)
{
    if(a.L/block != b.L/block)
    {
        return a.L/block < b.L/block;
    }

    return a.L/block%2 ? (a.R < b.R) : (a.R > b.R);
}


ll modmul(ll a, ll b, ll c)
{
    ll ans = 0;

    // a%=mod;

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
    // fact2[0] = modexp(fact[0], mod-2, mod);

    for(ll i=1; i<M; i++)
    {
        fact[i] = (fact[i-1]*i)%mod;
        // fact2[i] = modexp(fact[i], mod-2, mod);
    }
}

void add(ll p)
{
    cnt[S[p]]++;

    answer = (answer*cnt[S[p]])%mod;

    // cout << answer << " add " << p << endl;
}

void remove(ll p)
{
    ll temp = modexp(cnt[S[p]], mod-2, mod);    

    answer = (answer*temp)%mod;
    // cout << answer << " remove " << p << " " << cnt[S[p]] << endl;
    
    cnt[S[p]]--;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    factorial();

    ll N, Q;
    cin >> N >> Q;

    // block = N*N;
    // block/=Q;
    // block = sqrt(block);
    // pro[0] = 1;

    for(ll i=0; i<N; i++)
    {
        cin >> S[i];

        // cnt[S[i]]++;

        // if(i)
        // {
        //     if(cnt[S[i]] > 1)
        //     {
        //         pro[i] = modmul(pro[i-1], modexp(cnt[S[i]], mod-2, mod), mod);
        //     }

        //     else
        //     {
        //         pro[i] = pro[i-1];
        //     }
        // }
    }


    for(ll i=0; i<Q; i++)
    {
        ll L1, L2, R1, R2;
        cin >> L1 >> L2 >> R1 >> R2;

        q[i].L = L2;
        q[i].R = R2;
        q[i].i = i;
    }

    sort(q, q+Q, cmp);

    ll l = 0;
    ll r = 0;

    for(ll i=0; i<Q; i++)
    {
        ll L = q[i].L;
        ll R = q[i].R;

        // cout << i << " " << L << " " << R  << " ";

        while(l > L)
        {
            // cout << "while2 ";
            add(l-1);
            l--;
        }

        while(r <= R)
        {
            // cout << "while3 ";
            add(r);
            r++;
        }

        while(l < L)
        {
            // cout << endl << i << " " << l << " " << L << " abfs " << endl;
            // cout << "while1 ";
            remove(l);
            l++;
        }

        while(r > R+1)
        {
            // cout << "while4 ";
            remove(r-1);
            r--;
        }

        // cout << endl;
       
        // if(l > r)
        // {
        //     swap(l, r);
        // }

        ll t = R-L+1;

        num = fact[t];

        // cout << l << " " << r << " " << ans << endl;

        // if(l)
        // {
        //     ans = modmul(ans, pro[l-1], mod);
        //     // cout << "if " << ans << endl;
        // }

        // ll temp = modexp(pro[r], mod-2, mod);
        // // cout << temp << endl;

        // ans = modmul(ans, temp, mod);

        // cout << ans << endl;

        // cout << endl << endl;

        ll te = modexp(answer, mod-2, mod);

        num = (num*te)%mod;

        res[q[i].i] = num;
    }

    for(ll i=0; i<Q; i++)
    {
        cout << res[i] << endl;
    }
    

    return 0;
}