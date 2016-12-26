/**
** Problem: https://www.hackerrank.com/contests/w27/challenges/hackonacci-matrix-rotations
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

#define XX true
#define YY false

void compute_hackonacci(vector<short> &hacko){
    hacko[1]=1;
    hacko[2]=2;
    hacko[3]=3;
    for(LL i=4;i<=19600;i++){
        hacko[i]=(1*hacko[i-1]+2*hacko[i-2]+3*hacko[i-3])%10;
    }
}

void compute_matrix(LL n,vector<short> &hacko, vector<vector<bool> > &matrix){
    for(LL i=1;i<=n;i++){
        for(LL j=i;j<=n;j++){
            int index=(i*j)%140;
            if(index==0) index=140;
            if(hacko[index*index]%2==0)
                matrix[i][j]=matrix[j][i]=XX; 
            else matrix[i][j]=matrix[j][i]=YY;
        }
    }
}

int main(){
    LL n,q;
    cin>>n>>q;
    vector<vector<bool> > matrix(n+1, vector<bool>(n+1));
    vector<short> hacko(19601);
    compute_hackonacci(hacko);
    compute_matrix(n,hacko,matrix);
    int answer[4]={0,0,0,0};
    int x,y;
    //90 degree
    x=n,y=1;
    LOOP(i,1,n){
        LOOP(j,1,n){
            if(matrix[i][j]!=matrix[x][y]) answer[1]++;
            x--;
        }
        x=n,y++;
    }
    //180 degree
    x=n,y=n;
    LOOP(i,1,n){
        LOOP(j,1,n){
            if(matrix[i][j]!=matrix[x][y]) answer[2]++;
            y--;
        }
        x--,y=n;
    }
    //270 degree
    x=1,y=n;
    LOOP(i,1,n){
        LOOP(j,1,n){
            if(matrix[i][j]!=matrix[x][y]) answer[3]++;
            x++;
        }
        x=1,y--;
    }
    int query;
    while(q--){
        cin>>query;
        switch((query/90)%4){
            case 0: cout<<answer[0]<<endl; break;
            case 1: cout<<answer[1]<<endl; break;
            case 2: cout<<answer[2]<<endl; break;
            case 3: cout<<answer[3]<<endl; break;
        }
    }
    return 0;
}
