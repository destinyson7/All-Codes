#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int ans[50];
int ans2[50];

int solve(int i, vector <int> a)
{
    if(ans[i]>=0)
    {
        return ans[i];
    }
    
	if(i==0)
    {
        ans[0] = a[0];
        return ans[0];
    }
    
    if(i==1)
    {
        ans[1] = max(a[0], a[1]);
        return ans[1];
    }
    
    ans[i] = max(solve(i-1, a), a[i] + solve(i-2, a));
    return ans[i];
}

int solve2(int i, vector <int> a)
{
	if(i==0)
	{
		ans[0]=0;
		return ans[0];
	}

    if(ans2[i]>=0)
    {
        return ans2[i];
    }
    
	if(i==1)
    {
        ans2[1] = a[1];
        return ans2[1];
    }
    
    if(i==2)
    {
        ans2[2] = max(a[1], a[2]);
        return ans2[2];
    }
    
    ans2[i] = max(solve2(i-1, a), a[i] + solve2(i-2, a));   
    return ans2[i];
}

class BadNeighbors {
public:
    int maxDonations(vector <int> a){
  		int len = a.size();
        
        for(int j=0; j<50; j++)
        {
            ans[j]=-1;
            ans2[j]=-1;
        }
        
        int res=0;
        res = solve(len-2, a);
        res = max(solve2(len-1, a), res);
        
        return res;         
    }    
};