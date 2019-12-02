using namespace std;

#include <iostream>
#include <cmath>
#include <algorithm>

typedef unsigned long long int ll;

ll xset[1005];
ll yset[1005];
ll sumset[1000025];

ll modmul(ll x, ll y)
{
	ll ans = 0;

	while(y)
	{
		if(y%2==1)
		{
			ans = (ans + x);
		}

		x = (x + x);
		y/=2;
	}

	return ans;
}

int main()
{
	ll x, y, l, r;
	cin >> x >> y >> l >> r;

	ll cntx=1, cnty=1, cnt=0, least=0, max=0;

	xset[0]=1;
	for(ll i=1; ; i++)
	{	
		ll temp = modmul(xset[i-1], x);

		if(temp > 1000000000000000000/x)
		{
			xset[i]=temp;
			cntx++;
			// cout << xset[i] << " power at " << i;
			break;
		}

		xset[i]=temp;

		// if(xset[i]<=r)
		// {
		// 	cout << xset[i] << " power at " << i;
		// }

		cntx++;
	}
	// cout << endl;

	yset[0]=1;
	for(ll i=1; ; i++)
	{	
		ll temp = modmul(yset[i-1], y);

		if(temp > 1000000000000000000/y)
		{
			yset[i]=temp;
			cnty++;
			// cout << yset[i];
			break;
		}

		yset[i]=temp;

		// if(yset[i]<=r)
		// {
		// 	cout << yset[i] << " ";
		// }

		cnty++;
	}
	// cout << endl;

	for(ll j=0; j<cntx; j++)
	{
		for(ll k=0; k<cnty; k++)
		{
			// cout << xset[j] << " " << yset[k];
			if(xset[j]+yset[k]>=l && xset[j]+yset[k]<=r)
			{
				sumset[cnt++]=xset[j] + yset[k];
			}	
			// if(sumset[cnt-1]<=r)
			// {
			// 	cout << sumset[cnt-1] << " ";
			// }
		}
	}
	// cout << endl;

	sort(sumset, sumset+cnt);

	for(ll i=0; i<cnt; i++)
	{
		least=i;

		if(sumset[i]>=l)
		{
			// least=i;
			break;
		}

		// cout << sumset[i] << " ";
	}
	// cout << endl;

	for(ll i=0; i<cnt; i++)
	{
		// cout << sumset[i] << " ";

		if(i)
			max=i-1;

		if(sumset[i]>r)
		{
			// max=i-1;
			break;
		}

		if(i==(cnt-1))
		{
			max=i;
		}

		// cout << sumset[i] << " ";
	}
	// cout << endl;

	ll maxdif=0;

	// cout << sumset[least] << endl;

	if(sumset[least]>l && sumset[least]<r)
	{	
		if(sumset[least]>l)
		{
			maxdif= sumset[least] - l;
		}

		else
		{
			maxdif=0;
		}

		// cout << "if " << maxdif << endl;
	}

	else
	{
		if(max>least)
		{
			maxdif = sumset[least+1] - sumset[least] - 1;
			// cout << "else " << maxdif << endl;
		}

		else
		{
			if(sumset[max]!=r && sumset[max]!=l)
			{
				maxdif = r - l + 1;
			}

			else
			{
				maxdif = r - l;
			}
		}
	}

	// ll maxdif = -5; 

	// cout << least << " " << max << endl;
	for(ll j=least; j<max; j++)
	{
		// cout << sumset[j+1] - sumset[j] << " ";
		if(sumset[j+1] > sumset[j] + 1 && (sumset[j+1]-sumset[j]-1) > maxdif)
		{
			maxdif=sumset[j+1]-sumset[j]-1;
			// cout << "loop at " << j << "th iteration and maxdif is " << maxdif << endl;
		}
	}
	// cout << endl;

	// cout << sumset[max] << endl;

	if(sumset[max]>l && sumset[max]<r)
	{
		if(r - sumset[max] > maxdif)
		{
			if(r > sumset[max])
			{
				maxdif = r - sumset[max];
			}

			else
			{
				maxdif=0;
			}

			// cout << maxdif << endl;
		}
	}

	cout << maxdif << endl;
		
	return 0;
}