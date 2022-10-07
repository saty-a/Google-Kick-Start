#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a;
    cin>>t;
    a=t;
    while(t--){
        cout<<"Case #"<<(a-t)<<": ";
        int r,a,b;
        cin>>r>>a>>b;
        ll j=0,e=0;
        double ans=r,count=0;
        while(ans!=0){
            count+=(3.14159265358979323846264338327950288419716939*r*r);
            if(j%2==0){
                r*=a;
            }else{
                ans=r;
                r/=b;
                ans/=b;
            }
            j++;
        }
        cout<<fixed<<setprecision(6)<<count<<endl;
    }
	return 0;
}