    #include<bits/stdc++.h>
    using namespace std;
     
    typedef long long int ll;
    typedef long double ld;
     
    //****************************************************                
    #define lp(var,start,end) for (ll var = start; var <end ; ++var)
    #define rlp(var,start,end) for(ll var = start; var>=end ; var--)
    #define pb push_back
    #define mp make_pair
    #define pf push_front
    #define ff first
    #define ss second
    #define vll vector<ll>
    #define pll pair<ll,ll> 
    #define vpll vector<pll>
    #define all(X) X.begin(),X.end()
    #define endl "\n" //comment it for interactive questions
   
    #define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

    void solve()
    {
        ll n;
        cin >> n;
        vll a(n);
        ll maxid = 0;
        for(ll i=0;i<n;i++) {
            cin >> a[i];
        }
        for(ll i=0;i<n;i++) {
            if(a[i] > a[maxid]) {
                maxid = i;
                // cout << maxid << " ";
            }
        }
        // cout << maxid << "\n";
        vll ans(n);
        ll j = 0;
        for(ll i=maxid;j < n;i++,j++) {
            if(a[(i+1)%n] <= (a[maxid]-1)/2) {
                ans[maxid] = j+1;

                cout << maxid << " " << j+1 << endl;
                // cout << j + 1 << "\n";
                break;
            }
        }
        if(j == n) {
            for(ll i=0;i<n;i++) {
                cout << "-1 ";
            }
            cout << "\n";
            return;
        }
        ll cn = 1;
        for(ll j=maxid-1;cn < n;j--) {
            if(j==-1) {
                j = n-1;
            }
            if(a[j] <= 2*a[(j+1)%n]){
                ans[j] = ans[(j+1)%n] + 1;
            }
            else {
                ans[j] = 1;
            }
            cn++;
            if(j==0) {
                j = n;
            }
        }
        for(ll i=0;i<n;i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
     
    int main()
    {
        FAST_IO;

        ll t = 1;
        // cin >> t;
        while(t--){
            solve();
        }
    }