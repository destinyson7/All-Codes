using namespace std;

#include <iostream>
#include <cmath>

typedef long long int ll;

int main()
{
	ll r, x, y, a, b;
	cin >> r >> x >> y >> a >> b;

	ll c = a-x;
	ll d = b-y;

	ll dist2 = c*c + d*d;

	double dist = sqrt(dist2);
	ll dist3 = (ll)dist;
	// cout << "dist" << dist << " distint" << dist3 << endl;

	ll flag=0;
	// dist-=r;
	// dist3-=r;
	// cout << "dist" << dist << " distint" << dist3 << endl;

	if(dist == (double)dist3)
	{
		flag=1;
	}

	r*=2;

	ll ans=0;

	// if(dist < 0)
	// 	ans=0;

	if(flag)
	{
		ans += dist3/r;
		// cout << ans << "ans ";

		if(dist3%r!=0 && dist)
		{
			ans++;
			// cout << ans << "ans ";
		}

		cout << ans << endl;
	}

	else
	{
		ans += dist3/r;
		ans++;

		cout << ans << endl;
	}

	return 0;
}