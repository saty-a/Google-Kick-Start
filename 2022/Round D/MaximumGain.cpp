// MAXIMUM GAIN
 
// TIME COMPLEXITY: O(N*N + M*M + K)
// SPACE COMPLEXITY: O(N + M)
 
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
 
vi Operate(vi& arr, ll n){
    vi dp(n + 1), pref(n + 2), suff(n + 2);
 
    rep(i,0,n){
        pref[i + 1] = pref[i] + arr[i];
    }
 
    for(ll i=n-1; i>=0; i--){
        suff[i + 1] = suff[i + 2] + arr[i];
    }
 
    rep(i,1,n+1){
        // take i elements in total
        rep(j,0,i+1){
            // take j elements from front
            dp[i] = max(dp[i], pref[j] + suff[n - (i - j) + 1]);
        }
    }
 
    return dp;
}
 
void Saraff(){
    ll n;
    cin >> n;
 
    vi A(n);
    rep(i,0,n){
        cin >> A[i];
    }
 
    ll m;
    cin >> m;
 
    vi B(m);
    rep(i,0,m){
        cin >> B[i];
    }
 
    ll K;
    cin >> K;
 
    vi dp1 = Operate(A, n);
    vi dp2 = Operate(B, m);
 
    ll ans = 0;
    rep(i,0,K+1){
        // i questions answered from task A
        // K - i questions answered from task B
 
        if(i<=n && K-i<=m){
            ans = max(ans, dp1[i] + dp2[K - i]);
        }
    }
 
    cout << ans << endl;
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