// IMAGE LABELER
 
// TIME COMPLEXITY: O(NLOGN)
// SPACE COMPLEXITY: O(N)
 
#include "bits/stdc++.h"
using namespace std;
 
#define endl "\n"
#define F   first
#define S   second
#define ll  long long
#define vi  vector<ll>
#define pb  push_back
#define pii pair<ll,ll>
#define vii vector<pii>
#define vb  vector<bool>
#define vc  vector<char>
#define vs  vector<string> 
#define vvi vector<vi>
#define vvb vector<vb>
#define vvc vector<vc>
 
#define all(v) (v).begin(),(v).end()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define print(v) for(auto& it:v)cout<<it<<" ";
#define calc_fact(n) tgamma(n+1)
#define inf 9223372036854775807LL
#define MOD 1000000007
#define mod 998244353
 
template<typename T, typename U> static inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y) { if(x < y) x = y; }
 
/* 1. Think in Reverse Way
   2. Handle Corner Cases
   3. Check Array Bounds
   4. Don't Get Stuck on One Approach */
 
void Saraff(){
    ll n, m;
    cin >> n >> m;
 
    vi arr(n), rem;
    rep(i,0,n){
        cin >> arr[i];
    }
 
    sort(all(arr));
    reverse(all(arr));
 
    double ans = 0.0;
    rep(i,0,m-1){
        ans += arr[i];
    }
 
    rep(i,m-1,n){
        rem.pb(arr[i]);
    }
 
    sort(all(rem));
 
    ll sz = rem.size();
 
    if(sz & 1){
        ans += rem[sz / 2];
    }
    else{
        double sum = rem[sz / 2] + rem[(sz / 2) - 1];
        ans += sum/2.0;
    }
 
    cout << fixed << setprecision(10) << ans << endl;
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    ll test = 1;
    cin>>test;
    for(ll t=1;t<=test;t++){
        cout<<"Case #"<<t<<": ";
        Saraff();
    }
}