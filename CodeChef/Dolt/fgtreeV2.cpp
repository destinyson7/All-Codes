#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mm map <ll,ll>
#define mv vector <ll>
#define mp pair <ll,ll>
#define ms set <ll>
#define mq queue <ll>
#define mdq deque <ll>
#define mst stack <ll>
#define mpq priority_queue <ll>
#define mmh priority_queue <ll, vector<ll>, greater<ll> >
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define flush cout.flush();
int main(void)
{
    ll i,N,f,T,ans[105],arr[105],left[105],right[105],fixed[105],size,cnt;
    mm mapp1;
    map <pair <ll,ll>,ll> mapp2;
    string s;
    cin>>T;
    while(T--)
    {
        cin>>N;
        mapp1.clear();
        mapp2.clear();
        if(N==2)
        {
            cout<<"Q "<<1<<" "<<1<<" "<<1<<"\n";
            flush
            cin>>s;
            if(s[0]=='Y')
            {
                cout<<"A 2 -1\n";
                flush
            }
            else
            {
                cout<<"A -1 1\n";
                flush
            }
            continue;
        }
        size=cnt=0;
        for(i=1;i<=N;i++)
        {
            ans[i]=-1;
            fixed[i]=1;
        }
        for(i=1;i<=N;i++)
        {
            cout<<"Q "<<i<<" "<<i<<" "<<i<<"\n";
            flush
            cin>>s;
            if(s[0]=='Y')
            {
                size++;
                arr[size-1]=left[size-1]=right[size-1]=i;
                i++;
            }
        }
        cnt=N;
        while(cnt>1)
        {
            for(i=0;i<size;i++)
            {
                if(mapp1.find(arr[i])!=mapp1.end())
                {
                    continue;
                }
                while(1)
                {
                    mapp1[arr[i]]=1;
                    f=1;
                    if(left[i]>1)
                    {
                        cout<<"Q "<<left[i]-1<<" "<<left[i]-1<<" "<<right[i]<<"\n";
                        flush
                        cin>>s;
                        if(s[0]=='Y')
                        {
                            fixed[arr[i]]=0;
                            ans[arr[i]]=left[i]-1;
                            cnt--;
                            left[i]--;
                            arr[i]=left[i];
                            f=0;
                        }
                    }
                    if(right[i]<N && f)
                    {
                        cout<<"Q "<<right[i]+1<<" "<<left[i]<<" "<<right[i]+1<<"\n";
                        flush
                        cin>>s;
                        if(s[0]=='Y')
                        {
                            fixed[arr[i]]=0;
                            ans[arr[i]]=right[i]+1;
                            cnt--;
                            right[i]++;
                            arr[i]=right[i];
                            f=2;
                        }       
                    }
                    if(f==1)
                    {
                        break;
                    }
                }
            }
            for(i=1;i<size;i++)
            {
                if(mapp2.find({arr[i-1],arr[i]})==mapp2.end() && right[i-1]+1==left[i]-1 && fixed[arr[i-1]] && fixed[arr[i]])
                {
                    mapp2[{arr[i-1],arr[i]}]=1;
                    cout<<"Q "<<right[i-1]+1<<" "<<left[i-1]<<" "<<right[i]<<"\n";
                    flush
                    cin>>s;
                    if(s[0]=='Y')
                    {
                        fixed[arr[i-1]]=fixed[arr[i]]=0;
                        ans[arr[i-1]]=ans[arr[i]]=right[i-1]+1;
                        arr[i]=right[i-1]+1;
                        left[i]=left[i-1];
                        arr[i-1]=-1;
                        cnt-=2;
                        i++;
                    }
                }
            }
            f=0;
            for(i=0;i<size;i++)
            {
                if(arr[i]!=-1)
                {
                    arr[f]=arr[i];
                    left[f]=left[i];
                    right[f]=right[i];
                    f++;
                }
            }
            size=f;
        }
        cout<<"A ";
        for(i=1;i<=N;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        flush
    }
    return 0;
}