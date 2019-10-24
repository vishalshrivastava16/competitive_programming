/*
  Vishal Shrivastava
  i_am_kirito
*/
 
#include <bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define f(i,x,n) for(int i=x;i<n;i++)
#define all(c) c.begin(),c.end()
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
const int mod = 1e9+7, N = 1e5 + 10;
 
void solve()
{
  ll n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  int flag=0;
  for(int i=1;i<n;i++)
  {
    if(a[i]-a[i-1]<=1)
      {flag=1;
        break;
      }
  }
  if(flag==1)
    cout<<"2\n";
  else
    cout<<"1\n";
  return;
}
 
int32_t main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test=1;
  cin>>test;
  while(test--)
  {
    solve();
  }
}
