#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,e;
    cin>>t;
    e=t;
    while(t--){
        cout<<"Case #"<<(e-t)<<": ";
        int n,x,y;
        cin>>n>>x>>y;
        ll a=0,b=0,c=0,d=0;
        a = ((n)*(n+1))/2;
        if((a%(x+y))!=0){
            cout<<"IMPOSSIBLE"<<endl;
        }else{
            cout<<"POSSIBLE"<<endl;
            b = (a/(x+y));
            x*=b;
            y*=b;
            c = n;
            int e=x;
            while(x>0){
                x-=c;
                c--;
                d++;
            }
            cout<<d<<endl;
            c = n;
            while(e>0){
                if((e-c)>0){
                    e-=c;
                    cout<<c<<" ";
                    c--;
                }else{
                    cout<<e<<endl;
                    break;
                }
            }
        }
    }
	return 0;
}
