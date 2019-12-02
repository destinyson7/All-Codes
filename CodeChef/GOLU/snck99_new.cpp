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

ll visit[515];
ll lab[515];
queue<ll>st;

void bfs(auto &ar,ll x){
    queue<pi>q;
    q.push(mk(x,0));
    visit[x]=1;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        visit[p.fi]=1;
        lab[p.fi]=p.se;
        ll f=0;
        for(auto i:ar[p.fi]){
            if(visit[i.fi]==2){
                continue;
            }
            if(visit[i.fi]==1){
                st.push(i.fi);
                visit[i.fi]=2;
                f=1;
                continue;
            }
            visit[i.fi]=1;
            q.push(mk(i.fi,1-p.se));
        }
        if(f){
            st.push(p.fi);
            visit[p.fi]=2;
        }
    }
}


    int main(){
        // clock_t time_req = clock();
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ll n,m;
        cin>>n>>m;
        ve<ll>stb(n+1);
        ve<ll>cst(m+1);
        ve<list<pi> >ar(n+1);
        ve<pi>edge(m+1);
        for(ll i=1;i<=n;i++){
            cin>>stb[i];
        }
        for(ll i=1;i<=m;i++){
            cin>>cst[i];
        }
        for(ll i=1,u,v;i<=m;i++){
            cin>>u>>v;
            ar[u].pb(mk(v,i));
            ar[v].pb(mk(u,i));
            edge[i]=mk(u,v);
        }

        // for(ll i=1;i<=n;i++){
        //  if(visit[i]>=1)
        //      continue;
        //  bfs(ar,i);
        // }
        // if(st.empty()){
        //  cout << -1 << "\n";
        //  for(ll i=1;i<=n;i++){
        //      if(lab[i]==1)
        //          cout << "C";
        //      else
        //          cout << "G";
        //  }
        //  cout << "\n";
        //  return 0;
        // }
        srand(clock());
        for(ll i=1;i<=n;i++){
            lab[i] = rand()%2;
        }

        ve<ll>vi(m+1,0);

        // for(ll i=1;!st.empty() && i<=1000;i++){
        //  ll x = st.front();
        //  st.pop();
        //  ll a=0,b=0;
        //  for(auto it:ar[x]){
        //      if(lab[it.fi]==lab[x]){
        //          a+=min(stb[x]*stb[it.fi],cst[it.se]);
        //      }
        //      else{
        //          b+=min(stb[x]*stb[it.fi],cst[it.se]);
        //      }
        //  }
        //  if(a>b){
        //      for(auto it:ar[x]){
        //          if(lab[it.fi]==lab[x] && visit[it.fi]!=2){
        //              st.push(it.fi);
        //              visit[it.fi]=2;
        //          }
        //      }
        //      lab[x]=1-lab[x];
        //  }
        // }
        // for(ll i=1;i<=n;i++){
        //  ll a=0,b=0;
        //  for(auto it:ar[i]){
        //      if(lab[it.fi]==lab[i]){
        //          a+=min(stb[i]*stb[it.fi],cst[it.se]);
        //      }
        //      else{
        //          b+=min(stb[i]*stb[it.fi],cst[it.se]);
        //      }
        //  }
        //  if(a>b){
        //      lab[i]=1-lab[i];
        //  }
        //  for(auto it:ar[i]){
        //      if(vi[it.se]==0 && lab[it.fi]==lab[i] && stb[i]*stb[it.fi]>cst[it.se]){
        //          cout << it.se << "\n";
        //          vi[it.se]=1;
        //          cout.flush();
        //          ll a,b,c;
        //          cin>>a;
        //          if(a==0){
        //              cin>>b>>c;
        //              stb[b]=c;
        //          }
        //          else if(a==1){
        //              cin>>b>>c;
        //              cst[b]=c;
        //          }
        //      }
        //  }
        // }

                                // 2nd time
        ll B=170;
        while(B--){
            for(ll i=1;i<=n;i++){
                ll x = i;
                ll a=0,b=0;
                for(auto it:ar[x]){
                    if(lab[it.fi]==lab[x]){
                        a+=min(stb[x]*stb[it.fi],cst[it.se]);
                    }
                    else{
                        b+=min(stb[x]*stb[it.fi],cst[it.se]);
                    }
                }
                if(a>b){
                    lab[x]=1-lab[x];
                }
            }
        }
            for(ll i=1;i<=n;i++){
                ll a=0,b=0;
                for(auto it:ar[i]){
                    if(lab[it.fi]==lab[i]){
                        a+=min(stb[i]*stb[it.fi],cst[it.se]);
                    }
                    else{
                        b+=min(stb[i]*stb[it.fi],cst[it.se]);
                    }
                }
                if(a>b){
                    lab[i]=1-lab[i];
                }
                for(auto it:ar[i]){
                    if(vi[it.se]==0 && lab[it.fi]==lab[i] && stb[i]*stb[it.fi]>=cst[it.se]){
                        cout << it.se << "\n";
                        cout.flush();
                        vi[it.se]=1;
                        ll a,b,c;
                        cin>>a;
                        if(a==0){
                            cin>>b>>c;
                            stb[b]=c;
                        }
                        else if(a==1){
                            cin>>b>>c;
                            cst[b]=c;
                        }
                    }
                }
            }
        // while(double(clock() - time_req)/CLOCKS_PER_SEC <= 3.99){
            
        // }

        cout << -1 << "\n";
        for(ll i=1;i<=n;i++){
            if(lab[i]==1)
                cout << "C";
            else
                cout << "G";
            cout.flush();
        }
        cout << "\n";
        cout.flush();
        // time_req = clock() - time_req;
        // cout << double(time_req)/CLOCKS_PER_SEC << "\n";

        return 0;
    }

