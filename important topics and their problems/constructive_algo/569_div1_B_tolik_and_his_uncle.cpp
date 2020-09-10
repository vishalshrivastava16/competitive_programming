// problem link:   https://codeforces.com/problemset/problem/1179/B 

/*
    logic: Very nice problem if solved by on your own. Requires no algo just some constructive method to visit each cell of a matrix without repeating any.
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
	int x1,y1,x2,y2;
	
	x1=y1=0;
	x2=n-1;
	y2=m-1;
	int c=0;
	for(int op=0;op<=m/2;op++)
	{
		if(c==n*m)
				break;
		for(int t=0;t<n;t++)
		{
			cout<<x1+1<<" "<<y1+1<<"\n";
			c++;
			if(c==n*m)
				break;
			cout<<x2+1<<" "<<y2+1<<"\n";
			c++;
			if(c==n*m)
				break;
			x1++;
			x2--;

		}
		x1=0,x2=n-1;
		y1++;
		y2--;
	}
	cout<<"\n";
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