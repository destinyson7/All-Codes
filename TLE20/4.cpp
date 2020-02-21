#include<bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define inlld2(x, y) scanf("%lld%lld", &x, &y)
#define inlld3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define ind2(x, y) scanf("%d%d", &x, &y)
#define ind3(x, y, z) scanf("%d%d%d", &x, &y, &z)

const int N=1e3+5;
const int MOD=1e9+7;

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, arr[N][N], c, t;
vector<ll>state, ans;

ll cost_fn() 
{
    ll answer = 0;
    for (int i = 0; i < t; i++)
        for (int j = 0; j < c; j++)
            for (int k = j + 1; k < c; k++)
                answer += arr[state[i * c + j]][state[i * c + k]];
    return answer;
}

int main()
{
    inlld2(n, t);
    c=n/t;
    for(ll a=1; a<=n; a++)
        for(ll b=1; b<=n; b++)
            inlld(arr[a][b]);
    state.resize(n);
    iota(state.begin(), state.end(), 1);
    ans.resize(n);
    iota(ans.begin(), ans.end(), 1);
    ll maxi=cost_fn();
    srand(time(NULL));
    for(ll a=1; a<=16000; a++)
    {
        random_shuffle(state.begin(), state.end());
        ll x=cost_fn();
        if(x>maxi)
        {
            maxi=x;
            for(ll b=0; b<n; b++)
                ans[b]=state[b];
        }
        // printf("%d\n", x);
    }
    for(ll a=0; a<n; a++)
        printf("%lld ", ans[a]-1);
    printf("\n");
    printf("%lld\n", maxi);
    return 0;
}