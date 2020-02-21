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

ll n, t, arr[N][N], c, taken[N];
vector<pair<ll, ll> > vec;
vector<ll>state;

ll cost_fn() {
    ll answer = 0;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = j + 1; k < c; k++) {
                answer += arr[state[i * c + j]]
                                     [state[i * c + k]];
            }
        }
    }
    return answer;
}

int main()
{
    inlld2(n, t);
    assert(n%t==0);
    c=n/t;
    for(ll a=1; a<=n; a++)
        for(ll b=1; b<=n; b++)
            inlld(arr[a][b]);
    for(ll a=1; a<=n; a++)
    {
        ll here=0;
        for(ll b=1; b<=n; b++)
            if(a!=b)
                here-=arr[a][b] + arr[b][a];
        vec.pb({here, a});
    }
    sort(vec.begin(), vec.end());
    ll score=0;
    for(ll a=0; a<n; a++)
    {
        if(taken[vec[a].s])
            continue;
        vector<pair<ll, ll> > here;
        for(ll b=1; b<=n; b++)
            if(!taken[b] && b!=vec[a].s)
                here.pb({-arr[vec[a].s][b]-arr[b][vec[a].s], b});
        sort(here.begin(), here.end());
        state.pb(vec[a].s);
        printf("%lld ", vec[a].s-1);
        taken[vec[a].s]=1;
        for(ll b=0; b<c-1; b++)
        {
            state.pb(here[b].s);
            // here_arr.pb(here[b].s);
            printf("%lld ", here[b].s-1);
            taken[here[b].s]=1;
        }
        // printf("\n");
        // for(ll b=0; 
    }
    printf("\n%lld\n", cost_fn());
    return 0;
}