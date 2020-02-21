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
    srand(time(NULL));
    random_shuffle(state.begin(), state.end());
    for(int a=1; a<=n; a++)
    {
        ll diff=0, which=-1;
        int idx;
        for(idx=0; idx<n; idx++)
            if(state[idx]==a)
                break;
        for(int b=0; b<n; b++)
        {
            ll here=0;
            if(idx/c==b/c)
                continue;
            for(int d=c*(idx/c); d<c*(idx/c+1); d++)
                if(d!=idx)
                    here-=arr[state[d]][a]+arr[a][state[d]];
            for(int d=c*(b/c); d<c*(b/c+1); d++)
                if(d!=b)
                    here-=arr[state[d]][state[b]]+arr[state[b]][state[d]];
            for(int d=c*(b/c); d<c*(b/c+1); d++)
                if(d!=b)
                    here+=arr[state[d]][a]+arr[a][state[d]];
            for(int d=c*(idx/c); d<c*(idx/c+1); d++)
                if(d!=idx)
                    here+=arr[state[c]][state[d]]+arr[state[d]][state[c]];
            if(here>diff)
            {
                diff=here;
                which=b;
            }
        }
        if(diff)
            swap(state[idx], state[which]);
    }
    for(int a=0; a<n; a++)
        printf("%lld ", state[a]-1);
    printf("\n%lld\n", cost_fn());
    return 0;
}