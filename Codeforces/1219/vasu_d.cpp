#include "bits/stdc++.h"
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
using namespace std;
int main(void)
{
    ll n, sum1 = 0, num1 = 0, sum2 = 0, num2 = 0, i;
    cin>>n;
    string s;
    cin>>s;
    for(i=0; i<n/2; i++)
    {
        if(s[i]=='?')
            num1++;
        else
            sum1 += s[i] - '0';
    }
    for(; i<n; i++)
    {
        if(s[i] == '?')
            num2++;
        else
            sum2 += s[i] - '0';
    }
    if(sum1 > sum2 && num1 >= num2)
        cout<<"Monocarp\n";
    else if(sum1 > sum2 && num1 < num2)
    {
        if(num1%2==0)
        {   
            sum1 += 9 * (num1/2);
            if(num2%2==0)
                sum2 += 9 * (num2/2);
            else
                sum2 += 9 * (num2/2) + 0;
        }       
        else
        {
            sum1 += 9 * (num1/2) + 9;
            if(num2%2==0)
                sum2 += 9 * (num2/2);
            else
                sum2 += 9 * (num2/2) + 9;
        }
        if(sum1 != sum2)
            cout<<"Monocarp\n";
        else
            cout<<"Bicarp\n";
    }
    else if(sum1 < sum2 && num1 <= num2)
        cout<<"Monocarp\n";
    else if(sum1 < sum2 && num1 > num2)
    {
        if(num1%2==0)
        {   
            sum1 += 9 * (num1/2);
            if(num2%2==0)
                sum2 += 9 * (num2/2);
            else
                sum2 += 9 * (num2/2) + 9;
        }       
        else
        {
            sum1 += 9 * (num1/2) + 0;
            if(num2%2==0)
                sum2 += 9 * (num2/2);
            else
                sum2 += 9 * (num2/2) + 0;
        }
        if(sum2 != sum1)
            cout<<"Monocarp\n";
        else
            cout<<"Bicarp\n";
    }
    else
    {
        if(num1==num2)
            cout<<"Bicarp\n";
        else
            cout<<"Monocarp\n";
    }
}   