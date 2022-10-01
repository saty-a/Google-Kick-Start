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

bool pali(vector<int> v){
    vector<int> v1 = v;
    reverse(v1.begin(), v1.end());
    return v1 == v;
}

int main(){
    setIO();
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n < 5){
            cout << "Case #" << tt << ": " << "POSSIBLE" << endl;
            continue;
        }
        bool dp[n + 1][1 << 5];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        vector<int> tmp;
        for(int i = 1; i <= n; i++){
            vector<int> v;
            if(s[i - 1] == '?') v.pb(0), v.pb(1);
            else v.pb(s[i - 1] - '0');
            for(int j : v){
                for(int k = 0; k < (1 << 5); k++){
                    if(!dp[i - 1][k]) continue;
                    int nw = (k << 1) + j;
                    bool val = true;
                    vector<int> v1;
                    for(int x = 0; x < 5; x++){
                        if(nw & (1 << x)) v1.pb(1);
                        else v1.pb(0);
                    }
                    val &= i <= 4 || !pali(v1);
                    v1.clear();
                    for(int x = 0; x < 6; x++){
                        if(nw & (1 << x)) v1.pb(1);
                        else v1.pb(0);
                    }
                    val &= i <= 5 || !pali(v1);
                    if(val){
                        dp[i][nw%(1 << 5)] |= dp[i - 1][k];
                    }
                }
            }
        }
        bool ans = false;
        for(int i = 0; i < (1 << 5); i++){
            ans |= dp[n][i];
        }
        cout << "Case #" << tt << ": " << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    }
}