#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define ll long long int
#define ld unsigned long long int
#define pi pair<ll,ll>
#define pb push_back
#define pf push_front
#define pu push
#define po pop
#define fi first
#define se second
#define mk make_pair
#define ve vector
#define lr(n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define be begin

ll ar[100005];
ve<ll>visit(100005);
ll K,MAX;

struct wavelet_tree{
    ll lo,hi;
    wavelet_tree *l,*r;
    ve<ll>b;

    wavelet_tree(ll *from,ll *to,ll x,ll y){
        lo = x,hi = y;
        if(lo == hi || from >= to)return;
        ll mid = (lo+hi)/2;
        auto f = [mid](ll x){
            return x <= mid;
        };
        b.reserve(to-from+1);
        b.pb(0);
        for(auto it = from; it!=to; it++)
            b.pb(b.back() + f(*it));

        auto pivot = stable_partition(from, to, f);
        l = new wavelet_tree(from, pivot, lo, mid);
        r = new wavelet_tree(pivot, to, mid + 1, hi);
    }

    ll LTE(ll le,ll ri,ll k){
        if(le>ri || k <= this->lo) return 0;
        if(this->hi < k) return ri-le+1;
        ll lb = b[le-1],rb = b[ri];
        return this->l->LTE(lb+1,rb,k) + this->r->LTE(le-lb,ri-rb,k);
    }
};

void dfs(auto &gar,auto &deq,ll x){
    for(auto i:gar[x]){
        if(visit[i]==1){
            continue;
        }
        K++;
        deq[x].push(K);
        visit[i]=1;
        ar[K]=i;
        dfs(gar,deq,i);
        deq[x].push(K);
    }
}



    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll t;
        cin>>t;
        ve<ll> p(3);
        ll n;
        ve<queue<ll>>deq(100001);
        while(t--){
            cin>>n;
            K=0;
            lr(n+1){
                visit[i]=0;
            }
            MAX = n;
            lr(3)
                cin>>p[i];
            ve<list<ll>>gar(n+1);
            for(ll i=1,u,v;i<n;i++){
                cin>>u>>v;
                gar[u].pb(v);
                gar[v].pb(u);
            }

            visit[1]=1;
            K=1;
            ar[1]=1;
            dfs(gar,deq,1);
            wavelet_tree T(ar+1,ar+K+1,1,MAX);
            ve<ve<ll>>dar(n+1);
            ve<ve<ll>>dar1(n+1);
            for(ll i=1,a1,b1;i<=n;i++){
                a1=0,b1=0;
                while(!deq[i].empty()){
                    ll a=deq[i].front();deq[i].pop();
                    ll b=deq[i].front();deq[i].pop();
                    ll x = T.LTE(a,b,i);
                    a1+=x;
                    dar[i].pb(x);
                    b1+=b-a+1-x;
                    dar1[i].pb(b-a+1-x);
                }
                dar[i].pb(i-1-a1);
                dar1[i].pb(n-i-b1);
            }

            ll ans1=0,ans2=0,ans3=0;

            for(ll i=1,a,b,c,a1,b1;i<=n;i++){
                a = i-1;b=dar[i].size();
                c=n-i;a1=n-i;b1=i-1;
                for(ll j=0;j<b;j++){
                    a-=dar[i][j];
                    c-=dar1[i][j];
                    ans2+=dar1[i][j]*c;
                    ans1+=dar[i][j]*a;
                    ans3+=(a1-dar1[i][j])*dar[i][j]+(b1-dar[i][j])*dar1[i][j];
                }
            }
            // for(ll i=1,a,b;i<=n;i++){
            //  a = n-i;b=dar1[i].size();
            //  for(ll j=0;j<b;j++){
            //      a-=dar1[i][j];
            //      ans2+=dar1[i][j]*a;
            //  }
            // }
            // for(ll i=1,a,b,c;i<=n;i++){
            //  a=n-i,b=i-1,c=dar[i].size();
            //  for(ll j=0;j<c;j++){
            //      ans3+=(a-dar1[i][j])*dar[i][j]+(b-dar[i][j])*dar1[i][j];
            //  }
            // }
            if(p[1]<p[0] && p[1]<p[2]){
                cout << ans2 << "\n";
            }
            else if(p[1]>p[0] && p[1]>p[2]){
                cout << ans1 << "\n";
            }
            else{
                cout << ans3/2 << "\n";
            }
        }
        return 0;
    }