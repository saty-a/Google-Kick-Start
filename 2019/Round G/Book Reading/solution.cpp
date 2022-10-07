#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t, n, m, q, i, j, i1, ans;
    
    cin>>t;
    
    for(j=1; j<=t; j++)
    {
        cin>>n>>m>>q;
        
        ans=0;
        
        ll torn[n+1];
        ll c[n+1];
        
        for(i=0; i<=n; i++)
        {
            torn[i]=false;
            c[i]=0;
        }
        
        for(;m--;)
        {
            cin>>i;
            torn[i]=true;
        }
        
        for(i=1; i<=n; i++)
        {
            for(i1=i; i1<=n; i1+=i)
            {
                if(torn[i1]==false)
                {
                    c[i]++;
                }
            }
        }
        
        cout<<"Case #"<<j<<": ";
        for(;q--;)
        {
            cin>>i;
            ans+=c[i];
        }
        cout<<ans<<"\n";
        
        
    }
}