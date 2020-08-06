/*
    For this question we will have to use concept from a similar problem called the strip problem and then it is just the implementation of it.
*/

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
	int n,m;
	cin>>n>>m;
	int max1=max(n,m);
	int fib[max1+1];
	fib[0]=1;
	fib[1]=1;
	for(int i=2;i<=max1;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
		fib[i]=fib[i]%mod;
	}
	int ans=2*(fib[m]+fib[n]-1);
	ans=ans%mod;
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