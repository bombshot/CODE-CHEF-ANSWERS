#include<bits/stdc++.h>
typedef long long ll;
ll ar[1000009];
using namespace std;
ll k=0;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
	ll t,n;
	cin>>t;
	while(t--)
	{
        vector<ll>err(100007,0);
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>ar[i];
			ar[i]+=1;
			//cout<<ar[i]<<" ";
		}
		ll sum=0;
		for (int i = 0;i<n;i++)
		{
			if(!err[i])
			{
            vector<ll>I(100007,0);
			ll s=ar[i];
			ll c=i;
			s%=n;
			if(s+c>=n)
			{
                s=s+c-n;
                c=0;
			}
			ll count=1;
			err[i]=1;
			I[i]=1;
			while(1)
			{
				if (I[s+c])
				{
					sum+=count-I[s+c]+1;
					break;
				}
				else if(err[s+c])
				{
					break;
				}
				else
				{
					I[s+c]=count+1;
					err[s+c]=1;
					ll t=c;
					c=s+c;
					s=ar[s+t];
					s%=n;
     				if(s+c>=n)
					{
                        s=s+c-n;
                        c=0;
					}
				}
				count++;
			}
			}
 
		}
		cout<<sum<<endl;
	}
	return 0;
}