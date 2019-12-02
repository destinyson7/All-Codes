    #include <bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    int main()
    {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        
        ll n;
        
        while(scanf("%lld", &n) != EOF)
        {
            string a[n];
            for (int i = 0; i < n; ++i)
            {
                cin >> a[i];
            }
            ll f=0;
            for (int i = 0; i < n; ++i)
            {
                set<ll> s1;
                set<ll> s2;
                for (int j = 0; j < n; ++j)
                {
                    s1.insert(a[i][j]);
                    s2.insert(a[j][i]);
                    
                }
                if (s1.size()!=n||s2.size()!=n)
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                cout << "No\n";
            }
            else
            {
                ll f=0;
                for (int i = 1; i < n; ++i)
                {
                    if (a[0][i]<a[0][i-1])
                    {
                        f=1;
                        break;
                    }
         
                    if (a[i][0]<a[i-1][0])
                    {
                        f=1;
                        break;
                    }
                }
                if (f==1)
                {
                    cout << "Not Reduced\n";
                }
                else
                {
                    cout << "Reduced\n";
                }
            }
        }
        return 0;
    }