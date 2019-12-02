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
     
    // ll k1=0;
     
    // void fun(ll i,ll j,ll x,ll z){
    //  k1=-1;
    //  if(i==0){
    //      if(z == x){
    //          k1=1;
    //      }
    //      return;
    //  }
    //  if(j==0){
    //      for(ll k=1;k<=10;k++){
    //          if((z + k*i)%10==x){
    //              k1=k;
    //              return;
    //          }
    //      }
    //  }
        // for(ll b=0;b<=10;b++){
        //  if(k1!=-1 && b>=k1)
        //      return;
        //  for(ll c=0;c<=10;c++){
        //      if(b+c==0)
        //          continue;
        //      ll y=(z+b*i+c*j)%10;
        //      if(y==x){
        //          if(k1==-1){
        //              k1=c+b;
        //          }
        //          else
        //              k1=min(k1,c+b);
        //      }
        //  }
        // }
        
    // }
     
        int main(){
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            ll f[10][10][10];
            for(ll i=0;i<10;i++){
                for(ll j=0;j<10;j++){
                    for(ll k=0;k<10;k++){
                        ll k1=-1;
                        for(ll b=0;b<=10;b++){
                            for(ll c=0;c<=10;c++){
                                if(b+c==0)
                                    continue;
                                ll y=(b*i+c*j)%10;
                                if(y==k){
                                    if(k1==-1){
                                        k1=c+b;
                                    }
                                    else
                                        k1=min(k1,c+b);
                                }
                            }
                        }
                        f[i][j][k]=k1;
                    }
                }
            }
            string s;
            cin>>s;
            ll n=s.length();
            ll ar[10][10];
            for(ll i=0;i<10;i++){
                for(ll j=0;j<10;j++)
                    ar[i][j]=-2;
            }
            for(ll i=0;i<10;i++){
                for(ll j=0;j<10;j++){
                    ar[i][j]=0;
                    for(ll k=1;k<n;k++){
                        ar[i][j]+=f[i][j][(10+(s[k]-'0') - (s[k-1]-'0'))%10]-1;
                        if(ar[i][j]<0){
                            ar[i][j]=-1;
                            break;
                        }
                        // if(i!=j)
                            // ar[j][i]=ar[i][j];
                    }
                }
            }
            for(ll i=0;i<10;i++){
                for(ll j=0;j<10;j++){
                    cout << ar[i][j] << " ";
                }
                cout << "\n";
            }
            return 0;
        }