
//problem link: https://codeforces.com/contest/1242/problem/B

/*
    basic logic:    This question can be solved by DSU. In this we mainly have to find the minimum spanning tree which is mainly having least 1 and max 0.
                    For that we maintain sets of zeroes and for each new node encountered we check all the nodes having less index and has a zero edge between them 
                    if it is true then we merge it and reduce the answer by one as one more zero edge is added.At last when all nodes are considered then the 
                    remaining number is the answer as that are the number of 1 edge required.
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
set<int> adj[N];
int par[N];
set<int> compo;
vector<int> save[N];
int get_root(int u)
{
    if(u!=par[u])
    {
        par[u]=get_root(par[u]);
    }
    return par[u];

}
void merge(int x,int y)
{
    int x1=get_root(x);
    int y1=get_root(y);
    if (save[x1].size() < save[y1].size()) {
        swap(x1, y1);
    }
    for (auto &w : save[y1]) {
        save[x1].pb(w);
    }
    save[y1].clear();
    par[y1] = x1;
    compo.erase(y1);

}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;

        adj[x].insert(y);
        adj[y].insert(x);

    }
    for(int i=0;i<n;i++)
    {
        par[i]=i;
        save[i].pb(i);
        compo.insert(i);
    }
    int ans=n-1;
    for(int i=0;i<n;i++)
    {
        vector<int> to_merge;
        for(auto &j: compo)
        {
            if(j>=i)
                break;
            for(auto &x:save[j])
            {
                if(adj[i].count(x)==0)
                {
                    to_merge.pb(x);
                    break;
                }
            }
        }
        for(auto &k: to_merge)
        {
            merge(i,k);
            ans--;
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