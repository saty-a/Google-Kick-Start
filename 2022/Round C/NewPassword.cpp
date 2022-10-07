#include<bits/stdc++.h>
#include<chrono>
 
using namespace std;
using namespace std::chrono;
 
#define fastio std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#define MOD 1000000007
#define pll pair<long long ,long long>
#define ll long long
#define pb push_back
#define vii vector<vector<long long>>
#define vi vector<long long>
#define max_pq priority_queue<long long>
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define all(x) (x).begin(), (x).end()
#define f(i,l,r) for(ll i=l; i<=r; i++)
#define rf(i,r,l) for(ll i=r; i>=l; i--)
#define nline "\n"
#define setBits(n) __builtin_popcountll(n)
#define preci(a) cout << setprecision(a) << fixed;  
#define setMax(a,b) a = max(a,b)
#define google(n) cout << "Case #" << n << ": ";
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_p_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 

ll gcd(ll A, ll B) {
    ll tmp;
    while(B){
        tmp = A % B;
        A = B;
        B = tmp;
    }
    return A;
}
 
ll lcm(ll A, ll B){
    ll _gcd = gcd(A,B);
    return (A/_gcd)*(B/_gcd);
}
 
vector<ll> take_input(ll n){
    vector<ll> in(n);
    for(int i=0; i<n; i++)
        cin >> in[i];
    return in;
}
 
vector<pll> take_input_vpp(ll n){
    vector<pll> in(n);
    for(int i=0; i<n; i++)
        cin >> in[i].first >> in[i].second;
    return in;
}
// <------------------------------------------------------------------------------------------------------------------>

void solve(int tc){
    google(tc+1);
    int n; cin >> n;
    string s; cin >> s;
    int low = 0, high = 0, dig = 0, special = 0;
    for(auto &c:s){
        low = low || (c >= 'a' && c <= 'z');
        high = high || (c >= 'A' && c <= 'Z');
        dig = dig || (c >= '0' && c <= '9');
        special = special || (c == '#' || c == '@' || c == '*' || c == '&');
    }
    if(!low) s.push_back('a');
    if(!high) s.push_back('A');
    if(!dig) s.push_back('0');
    if(!special) s.push_back('#');
    while(s.size() < 7)
        s.push_back('a');
    cout << s;
}
        
int main(){
    fastio
 

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++){
        solve(i);
        cout << nline;
    }
    return 0;
}
