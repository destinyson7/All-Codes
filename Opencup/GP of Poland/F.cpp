    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    using namespace __gnu_pbds;
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
    #define sz(a) (ll)a.size()
    #define INF 1e18

    typedef tree <ll, null_type, less <ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
    // order_of_key(val): returns the number of values less than val
    // find_by_order(k): returns an iterator to the kth largest element (0-based)

    // ll gcd(ll a, ll b){
    //     if(a<b) swap(a,b);
    //     if(b==0) return a;
    //     return gcd(b,a%b);
    // }

    // ll modexp(ll x, ll y){
    //     ll rem=1;
    //     while(y!=0){
    //         if(y%2==1){
    //             rem=(rem*x);
    //         }
    //         x=(x*x);
    //         y/=2;
    //     }
    //     return rem;
    // }

    ll n,k;

    ll pre[7][25001];
    ll whc;
    bool compare(ll a, ll b){
        // cout << a << " " << b << endl;
        // assert(whc <= a && whc <= b);
        // if(a==0)
        //  return 0;
        // if(b==0)
        //  return 1;
        return pre[whc][(a-whc)/k] <= pre[whc][(b-whc)/k];
        // if(b>a){
        //  return (pre[whc][(b-whc)/k]-pre[whc][(a-whc)/k])<0;
        // }
        // else{
        //  return (pre[whc][(b-whc)/k]-pre[whc][(a-whc)/k])>0;
        // }
    }

    ve<ve<ll>>ans;
    ve<ll>vi(25001,0);
    ll temp[7][25001];
    ve<ll>ar(25001);

    void fun(auto seq, auto bol, ll r){
        if(r==0){
            auto ten = ve<ll>(n);
            for(ll i=1;i<=k;i++){
                for(ll j=0;j<n/k+(n%k>=i);j++){
                    ten[seq[i][j]-1]=temp[i][j];
                }
            }
            ll fl=0;
            for(ll i=0,x;i<n-k+1;i++){
                x=0;
                for(ll j=0;j<k;j++){
                    x+=ten[i+j];
                }
                if(x!=ar[i+1]){
                    fl=1;break;
                }
            }
            if(fl==0)
                ans.pb(ten);
            return;
        }
        ll minn;
        for(ll i=1;i<=n;i++){
            if(vi[i]==0){
                minn=i;
                break;
            }
        }
        for(ll i=1;i<=k;i++){
            if(bol[i]==1)continue;
            bol[i]=1;
            temp[i][0]=minn;
            vi[minn]=1;
            ll fl=0;
            for(ll j=1;j<n/k+(n%k>=i);j++){
                temp[i][j]=temp[i][j-1]+pre[i][(seq[i][j]-i)/k]-pre[i][(seq[i][j-1]-i)/k];
                if(temp[i][j]>n || temp[i][j] < 1 || vi[temp[i][j]]==1){
                    fl=1;
                    bol[i]=0;
                    for(ll k=j-1;k>=0;k--){
                        vi[temp[i][k]]=0;
                    }
                    break;
                }
                else
                    vi[temp[i][j]]=1;
            }
            if(fl==1)continue;
            fun(seq,bol,r-1);
            for(ll j=0;j<n/k+(n%k>=i);j++){
                vi[temp[i][j]]=0;
            }
            bol[i]=0;
        }
    }

        int main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            ll t;
            cin>>t;
            while(t--){
                cin>>n>>k;
                for(ll i=0;i<=k;i++){
                    for(ll j=0;j<=n;j++){
                        pre[i][j]=0;
                    }
                }
                lr(n-k+1){
                    cin>>ar[i+1];
                }
                for(ll i=1,cnt=1;i<n-k+1;){
                    for(ll j=1;i<n-k+1 && j<=k;j++){
                        pre[j][cnt]=pre[j][cnt-1]+ar[i+1]-ar[i];
                        // cout << j << " " << i << " " << pre[j][cnt] << "\n";
                        i++;
                    }
                    cnt++;
                }
                ve<ve<ll>>seq(k+1);
                for(ll i=1;i<=n;){
                    for(ll j=1;i<=n && j<=k;j++){
                        seq[j].pb(i);
                        // cout << j << " " << i << "\n";
                        i++;
                    }
                }
                for(ll i=1;i<=k;i++){
                    whc = i;
                    if(sz(seq[i]) > 1)
                        sort(seq[i].be(),seq[i].end(),compare);
                    // for(ll j=0;j<n/k+(n%k>=i);j++){
                    //  cout << seq[i][j] << " ";
                    // }
                    // cout << "\n";
                }
                ve<ll>bol(k+1,0);
                lr(n+1){
                    vi[i]=0;
                }
                fun(seq,bol,k);
                sort(all(ans));
                cout << sz(ans) << "\n";
                for(ll i=0;i<sz(ans);i++){
                    for(ll j=0;j<n;j++){
                        cout << ans[i][j] << " ";
                    }
                    cout << "\n";
                }
                ans.clear();
            }
            return 0;
        }