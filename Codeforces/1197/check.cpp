        if(m>1){
            for(ll i=1;i<=n;i++){
                dp[i][1]=max(dp[i-1][0]+ar[i-1]-k,ar[i-1]-k);
                ans=max(dp[i][1],ans);
                for(ll j=2;j<=min(m,i) && j!=1;j++){
                    if(j==m)
                        j=0;
                    dp[i][j]=dp[i-1][(m+j-1)%m]+ar[i-1];
                    ans=max(dp[i][j],ans);
                }
            }
        }