#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class ZigZag {
public:
    int longestZigZag(vector <int> arr){
        int len = arr.size();
        
        int zigzag[55][2];
        
        for(int i=0; i<len; i++)
        {
            zigzag[i][0]=1;
            zigzag[i][1]=1;
        }
        
        int ans = 0;
        
        for(int j=0; j<len; j++)
        {
            for(int k=0; k<j; k++)
            {
                if(arr[k]>arr[j])
                {
                    zigzag[j][1]=max(zigzag[k][0]+1, zigzag[j][1]);
                }
                
                if(arr[k]<arr[j])
                {
                    zigzag[j][0]=max(zigzag[k][1]+1, zigzag[j][0]);
                }
            }
            
            int temp = max(zigzag[j][0], zigzag[j][1]);
            ans = max(temp, ans);
        }
        
        return ans;        
    }
};

