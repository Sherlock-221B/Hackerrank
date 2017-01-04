/**
** Problem: https://www.hackerrank.com/contests/hourrank-16/challenges/pile-of-candies
**/
#include <bits/stdc++.h>
using namespace std;
#define LOOP(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPR(i,u,l) for(int (i)=(int)(u);(i)>=(int)(l);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }
template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}

class cmp{
    public:
    bool operator() (const int &a,const int &b){
        return a>b;
    }
};


int main(){

    int n;
    cin>>n;
    priority_queue<int,VI,cmp> pq;
    VI v;
    LOOP(i,0,n-1){
        int x;
        cin>>x;
        v.PB(x);
        pq.push(x);
    }
    int x=pq.top();
    pq.pop();
    pq.push(2*x);
    x=pq.top();
    int count=0;
    LOOP(i,0,n-1){
        v[i]*=2;
        LL mn=v[0];
        LOOP(j,1,n-1){
            MIN(mn,v[j]);
        }
        v[i]/=2;
        if(mn==x) count++;
    }
    cout<<x<<" "<<count;
    return 0;
}
