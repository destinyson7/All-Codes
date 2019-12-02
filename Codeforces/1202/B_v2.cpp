    #include<bits/stdc++.h>
    using namespace std;
    #include <ext/pb_ds/assoc_container.hpp> 
    #include <ext/pb_ds/tree_policy.hpp> 
    using namespace __gnu_pbds;   
    #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
    #define ld double
    #define ff first
    #define ss second
    #define pb push_back
    #define mp make_pair
    #define all(a) a.begin(),a.end()
    #define sz(a) (ll)(a.size())
    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair <ll, ll> pll;
    typedef vector<pll> vplll;
    ll mod = 1e9+7;
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int c,x,n,t,st[10][10][10][10]; 
        for(int i=0; i<10;i++)
        {
            for(int j=0; j <10 ;j++)
            {
                for(int k=0;k<10;k++)
                {
                    for(int p=0;p<10;p++)
                    {
                        st[i][j][k][p] = 100;
                    }
                }
            }
        }
        for(int i=0; i < 10; i++ )
        {
            for(int j=0;j<10;j++)
            {
                // if(i!=j)
                // {
                    for(int k = 0; k < 10; k++)
                    {
                        for(int u=0; u < 10; u++)
                        {
                            ll an =  ( u - k +10)%10;
                            for(int c = 0; c <= 10; c++)
                            {
                                ll tmp =0;
                                tmp = c*10 + an;
                                // if(i==0&&j==0&&k==0&&u==8)
                                // cout<<i<<j<<k<<u<<tmp<<" ";
                                for(int b= 0; b<10; b++)
                                {
                                    for(int a = 0; a < 10; a++ )
                                    {
                                        if(a*i + b*j == tmp)
                                        {
                                            // if(i!=j)
                                            // x = a+b-2;
                                            // else 
                                            x = a+b-1;
                                            // if(i==0)
                                            // x = b-1;
                                            // else if(j==0)
                                            // x = a-1;
                                            if(x>=0)
                                            st[i][j][k][u] = min(st[i][j][k][u],x);

                                        // cout << st[i][j][k][u] << endl;
                                            // if(i==0&&j==0&&k==0&&u==8)
                                            // cout<<st[i][j][k][u];
                                        }
                                    }
     
                                }
                                if(i==0||j==0)
                                if(an==0)
                                st[i][j][k][u] = 0;
                            }
                        }
                    }
     
            }
        }
        string s;
        cin>>s;
        ll ans =0;
        ll m[10][10];
        // cout<<st[1][1][0][0];
        for(int a=0;a<10;a++)
        {for(int b=0;b<10;b++)
        {ans = 0;
        ll f =0;
        m[a][b]=0;
        for(int i=1;s[i]!='\0';i++)
        {
            ll io= st[a][b][s[i-1]-'0'][s[i]-'0'];
            ans+= io;
            // cout<<a<<' '<<b<<' '<<io<<' ';
            if(st[a][b][s[i-1]-'0'][s[i]-'0']==100)
            {
                m[a][b] = -1;
                f=1;
                break;
            }
        }
        if(f==0)
        m[a][b] = ans;
        cout<<m[a][b]<<' ';
        }
        cout<<"\n";
        }
        // for(int i=0;i<10;i)
        return 0;
    }