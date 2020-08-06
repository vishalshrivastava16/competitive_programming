/*
  Vishal Shrivastava
  i_am_kirito

  look up to the sky,keep up(don't let go)
  I'll look towards the sky, without any doubt...
  
  never let you go,never let you go.
  till the light shines stronger, I go.
*/
#include <bits/stdc++.h>
using namespace std;
#define minpq priority_queue <int, vector<int>, greater<int> >
#define maxpq  priority_queue <int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define ll long long
#define int ll
#define pll pair<ll,ll>
#define pii pair<int,int>
const int mod = 1e9+7, N = 4e5 + 10;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int posa=-1,posb=-1;
	int save[n][2];
	for(int i=n-1;i>=0;i--)
	{
		save[i][0]=posa;
		save[i][1]=posb;
		if(s[i]=='A')
			posa=i;
		else
			posb=i;

	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='A')
		{
			int in1=save[i][0];
			if(in1==-1)
				continue;
			int in2=save[i][1];
			if(in2<in1)
			{
				ans+=(n-1-in1+1);
			}
			else
			{
				ans+=(n-1-in1);
			}
		}
		else
		{
			int in1=save[i][1];
			if(in1==-1)
				continue;
			int in2=save[i][0];
			if(in2<in1)
			{
				ans+=(n-1-in1+1);
			}
			else
			{
				ans+=(n-1-in1);
			}

		}
	}
	cout<<ans<<"\n";
    return;
}
 
int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test=1;
  //cin>>test;
  while(test--)
  {
    solve();
  }
}