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

ll fact[L];
ll divfact[L];
ll S[L];

set <ll> uniq;
map <ll, ll> cnt;

ll modexp(ll a, ll b, ll c)
{
    ll ans = 1;
    a%=mod;

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

ll check(ll num)
{
    if(num >= mod)
    {
        num%=mod;
    }

    return num;
}

void factorial()
{
    fact[0] = 1;
    divfact[0] = 1;

    for(ll i=1; i<L; i++)
    {
        fact[i] = fact[i-1]*i;
        fact[i] = check(fact[i]);
        divfact[i] = modexp(fact[i], mod-2, mod);
    }
}

void solve(ll N, vector < vector <ll> > &dp, vector < vector <ll> > &ans)
{
    ll root = (ll)sqrt(N);

    for(ll i=root; i<=N; i+=root)
    {
        ll ind = i/root - 1;
        for(ll j=1; j<=N; j++)
        {
            dp[ind][j] = 0;
        }

        ll cur = 1;

        for(ll j=i; j>0; j--)
        {
            dp[ind][S[j]]++;

            cur=(cur*dp[ind][S[j]]);
            cur = check(cur);

            ans[ind][j] = cur;
        }
    }
}

ll store[L];

ll query(ll prev, ll N, vector < vector <ll> > &dp, vector < vector <ll> > &ans)
{
    ll root = (ll)sqrt(N);
    ll L1, L2, R1, R2;
    cin >> L1 >> L2 >> R1 >> R2;

    ll l = (L1*prev + L2)%N + 1;
    ll r = (R1*prev + R2)%N + 1;

    if(l > r)
    {
        swap(l, r);
    }

    ll first = r/root;

    if(r-l<root || !first)
    {
        ll cur = 1;
        
        for(ll i=r; i>=l; i--)
        {
            store[S[i]]++;

            cur = (cur*store[S[i]]);
            cur = check(cur);
        }

        // cout << "if if" << endl;

        ll answer = (modexp(cur, mod-2, mod)*fact[r-l+1]);
        answer = check(answer);

        for(ll i=r; i>=l; i--)
        {
            store[S[i]] = 0;
        }

        return answer;
    }

    else
    {
        ll second = l/root;

        if(l%root)
        {
            second++;
        }

        ll third = r/root;

        for(ll i=second*root; i>=l; i--)
        {
            store[S[i]]++;
        }

        ll cur = ans[third-1][l];

        for(ll i=third*root+1; i<=r; i++)
        {
            store[S[i]]++;
        
            ll temp = dp[third-1][S[i]] + store[S[i]];

            if(second)
            {
                temp-=dp[second-1][S[i]];
            }

            cur = (cur*fact[temp]);
            cur = check(cur);
            cur = (cur*divfact[temp-1]);
            cur = check(cur);
        }

        for(ll i=third*root+1; i<=r; i++)
        {
            store[S[i]] = 0;
        }

        for(ll i=second*root; i>=l; i--)
        {
            // cout << i << endl;
            store[S[i]] = 0;
        }

        cur = modexp(cur, mod-2, mod);

        ll answer = (cur*fact[r-l+1]);
        answer = check(answer);

        return answer;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N, Q;
    cin >> N >> Q;

    ll root = (ll)sqrt(N);

    vector < vector <ll> > dp(root+5);
    vector < vector <ll> > ans(root+5);

    for(ll i=0; i<root+5; i++)
    {
        dp[i] = vector <ll> (N+5);
        ans[i] = vector <ll> (root*(i+1) + 5);
    }

    factorial();

    for(ll i=1; i<=N; i++)
    {
        cin >> S[i];

        uniq.insert(S[i]);
    }

    store[0] = S[1];

    ll res = 0;
    for(auto i: uniq)
    {
        res++;
        cnt[i] = res;
    }

    for(ll i=1; i<=N; i++)
    {
        S[i] = cnt[S[i]];
    }

    solve(N, dp, ans);

    ll prev = 0;

    while(Q--)
    {
        // cout << Q << " ";
        prev = query(prev, N, dp, ans);

        cout << prev << endl;
    }

    return 0;
}