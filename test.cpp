#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop1(a,b) for(ll i=a;i<=b;i++)
#define loop2(a,b) for(ll j=a;j<=b;j++)
#define vt vector<ll>
#define pb push_back

int main()
{
	int n;
	cin>>n;
	ll x=1;
	vector<ll> req;
	req.pb(1);
	map<ll,ll> mm;
	mm[1]=1;
	while(n--){
		ll a,b;
		cin>>a>>b;
		while(b--){
			vector<ll> demo2;
				for(vector<ll>::iterator i=req.begin();i!=req.end();i++){
					if(mm[a*(*i)]==0){
						demo2.pb(a*(*i));
						mm[a*(*i)]=1;
					}
				}
				for(vector<ll>::reverse_iterator i=demo2.rbegin();i!=demo2.rend();i++) req.pb(*i);
		}
	}
	for(vector<ll>::iterator i=req.begin();i!=req.end();i++) out<<(*i)<<" ";
}