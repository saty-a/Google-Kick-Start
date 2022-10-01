#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef pair<ld, ld> pld;

const int inf = 1e9;
const ll llinf = 1e18;
const int mod = 1e9 + 7;
const double PI = acos(-1);

struct chash {
    const uint64_t C = ll(2e18*PI)+71;
    const int RANDOM = rand();
    ll operator()(ll x) const {
        return __builtin_bswap64((x^RANDOM)*C);
    }
};

template<class K> using sset =  tree<K, null_type, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
template<class K, class V> using gphash = gp_hash_table<K, V, chash, equal_to<K>, direct_mask_range_hashing<>, linear_probe_fn<>, hash_standard_resize_policy< hash_exponential_size_policy<>, hash_load_check_resize_trigger<>, true> >;

inline ll ceil0(ll a, ll b) {
    return a / b + ((a ^ b) > 0 && a % b);
}

inline ll floor0(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
}

void setIO() {
    ios_base::sync_with_stdio(0); cin.tie(0);
}

//index, sum, prod%sum, limit, first
ll dp[13][110][110][2][2];
vector<int> digit;

void find(ll x){
    digit.clear();
	while(x){
		digit.pb(x%10);
		x /= 10;
	}
}

int tar;
 
ll dfs(int x, int sum, int rem, bool lim, bool first){
	if(x == -1) return sum == 0 && rem == 0;
	if(dp[x][sum][rem][lim][first] != -1) return dp[x][sum][rem][lim][first];
	ll ret = 0;
	int mx = 9;
	if(lim) mx = digit[x];
	for(int i = 0; i <= mx; i++){
		if(i == 0 && first) ret += dfs(x - 1, sum, rem, (digit[x] == i) ? lim : false, true);
        if(sum < i) continue;
	    if(i != 0 || !first) ret += dfs(x - 1, sum - i, rem*i%tar, (digit[x] == i) ? lim : false, false);
	}
	return dp[x][sum][rem][lim][first] = ret;
}

int main(){
    setIO();
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        find(b);
        for(int i = 1; i <= 108; i++){
            tar = i;
            memset(dp, -1, sizeof(dp));
            ans += dfs(digit.size() - 1, i, 1, true, true);
        }
        find(a - 1);
        for(int i = 1; i <= 108; i++){
            tar = i;
            memset(dp, -1, sizeof(dp));
            ans -= dfs(digit.size() - 1, i, 1, true, true);
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
}