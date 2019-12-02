    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef long long int ll;
     
    #define pb push_back
    #define mp make_pair
    #define endl "\n"
     
    ll Fact(ll n, ll mod) 
    { 
        if (n>=mod) 
        {
           return 0; 
        }
     
        ll result = 1; 
     
        for(ll i = 1; i <= n; i++) 
        {
            result = (result * i) % mod; 
        }
     
        return result; 
    } 
     
    ll modmul(ll a, ll b, ll c)
    {
        ll ans=0;
     
        a%=c;
     
        while(b)
        {
            if(b%2==1)
            {
                ans=((ans+a)%c);
            }
     
            b/=2;
            
            a=(a*2)%c;
        }
     
        return ans;
    }
     
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);
        
        string s;
        cin >> s;
        ll len = s.length();
     
        ll q;
        cin >> q;
     
        ll cnttot[1005];
        
     
        ll mod = 1e9+7;
     
        while(q--)
        {
     
            for(ll j=0; j<1005; j++)
            {
                cnttot[j] = 0;
            }
            ll x, y;
            cin >> x >> y;
            // cout << "x " << x << " y " << y << endl;
     
            ll cntx=0, cnty=0, cnt1=0, cnt2=0;
     
            for(ll i=0; i<len; i++)
            {
                if(s[i]==s[x-1] || s[i]==s[y-1])
                {
                    // cout << "i " << i << endl;
                    if(s[i]==s[x-1])
                    {
                        cntx++;     
                    }
     
                    else
                    {
                        cnty++;     
                    }
     
                    cnt1++;
                }
     
                else
                {
                    cnttot[s[i]]++;
                }
            }
     
            // cout << "cnt1 " << cnt1 << endl;
     
            // cout << "hey " << (ll)'a' << endl;
            if(cnt1 != len/2)
            {
                cout << 0 << endl;
                // return 0;
            }
     
            else
            {       
                ll ans = Fact(len/2, mod);
                ll ans1 = Fact(cntx, mod);
                // cout << "ans1 " << ans1 << endl;
                ll ans2 = Fact(cnty, mod);
                // cout << "ans2 " << ans2 << endl;
                // cout << ans << endl;
                ans/=ans1;
                ans/=ans2;
                ans%=mod;
                // cout << "ans " << ans << endl;
                ll ans3 = Fact(len/2, mod);
                ans = modmul(ans, ans3, mod);
                // cout << ans << endl;
                for(ll j=0; j<1005; j++)
                {
                    ll temp = Fact(cnttot[j], mod);
                    ans/=temp;
                    ans%=mod;
                }
                ans%=mod;
                // ll div = Fact(cnt2, mod);
                ans = modmul(ans, 2, mod);
                // ans/=div;
                ans%=mod;   
     
                cout << ans << endl;
            }
        }   
     
        return 0;
    }