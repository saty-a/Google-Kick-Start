#include<bits/stdc++.h>
using namespace std;

class UnionFind {
  public:
  vector<int> par;
  vector<int> rank;
  vector<int> Size;

  UnionFind(int n) {
    for(int i = 0; i < n; ++i) {
      par.push_back(i);
      rank.push_back(0);
      Size.push_back(1);
    }
  }

  int root(int x) {
    if(par[x] == x) return x;
    else return par[x] = root(par[x]);
  }

  bool same(int x, int y) {
    return root(x) == root(y);
  }

  void unite(int x, int y) {
    x = root(x), y = root(y);
    if(x == y) return;
    if(rank[x] < rank[y]) {
      par[x] = y;
      rank[y]++;
      Size[y] += Size[x];
    }
    else {
      par[y] = x;
      if(rank[x] != rank[y]) rank[x]++;
      Size[x] += Size[y];
    }
  }

  long long size(int x) {
    return Size[root(x)];
  }
};

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 1; tt <= t; ++tt){
        long long ans = 0;
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int> (n,0));
        vector<vector<int>> b(n, vector<int> (n,0));
        vector<int> r(n);
        vector<int> c(n);

        vector<tuple<int, int, int>> g;

        UnionFind uf(2*n);

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> a[i][j];
            }
        }
        ll s = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> b[i][j];
                s += b[i][j];
                g.emplace_back(b[i][j], i, n+j);
            }
        }

        for(int i = 0; i < n; ++i) cin >> r[i];
        for(int i = 0; i < n; ++i) cin >> c[i];

        sort(g.rbegin(), g.rend());

        ll remove = 0;
        
        for(auto [w, u, v] : g){
          if(uf.same(u,v)) continue;
          remove += w;
          uf.unite(u,v);
        }
        ans = s-remove;
        cout << "Case #" << tt << ": " << ans << endl;
        
    }
    return 0;
}