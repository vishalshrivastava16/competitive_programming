
// problem link:    https://codeforces.com/problemset/problem/1213/G

/*
    basic logic:    It can be solved using concepts of DSU and offline queries. First we sorted the weighted edges in non decreasing order and also sorted the 
                    sorted the queires in non decreasing order then we start taking the edges whose weight less than current query weight and add them to some set
                    using DSU and side by side we calculate ans at that momemt so as to return answer when required.
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
vector<pair<int,pii>> edge;
vector<pii> que;
int par[N];
int ans[N];
int res=0;
int save[N];
int fin(int s)
{
	if(s==par[s])
	{
		return s;
	}
	return par[s]=fin(par[s]);
}
int calc(int n)
{
	int t=(n*(n-1))/2;
	return t;
}
void merge(int x,int y)
{
	x=fin(x);
	y=fin(y);
	if(save[x]<save[y])
	{
		swap(x,y);
	}
	res=res-calc(save[x]);
	res=res-calc(save[y]);
	save[x]+=save[y];
	res+=calc(save[x]);
	par[y]=x;

}
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n-1;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		x--,y--;
		edge.pb(mp(w,mp(x,y)));

	}

	for(int i=0;i<m;i++)
	{
		int q;
		cin>>q;
		que.pb(mp(q,i));
	}
	if(edge.size()==0)
	{
		for(int i=0;i<m;i++)
		{
			cout<<"0 ";
		}
		cout<<"\n";
		return;
	}
	sort(all(edge));
	sort(all(que));
	
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		save[i]=1;
	}
	int in=0;
	for(int i=0;i<m;i++)
	{
		while(edge[in].F<=que[i].F&&in<n-1)
		{
			int fir=edge[in].S.F;
			int sec=edge[in].S.S;
			merge(fir,sec);
			in++;
			//cout<<res<<"r2\n";
		}
		//cout<<res<<"r\n";
		int index=que[i].S;
		ans[index]=res;
	}
	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<" ";

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