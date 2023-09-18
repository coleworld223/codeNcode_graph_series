#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    // int tests; cin >> tests;
    int tests = 1;

    auto solve = [&] () {
        ll n, m; cin >> n >> m;

        vector <vector <ll>> adj (n);

        for (ll i = 0; i < m; i++) {
            ll u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector <ll> sbtree_sz (n);

        function <void (ll, ll)> dfs = [&] (ll node, ll par) -> void {
            for (auto child : adj[node]) {
                if (child == par) continue;
                dfs (child, node);
                sbtree_sz[node] += sbtree_sz[child];
            }
            sbtree_sz[node] += 1;
        };

        dfs (0, -1);

        for (ll i = 0; i < n; i++) {
            cout << i << " :" << sbtree_sz[i] << endl;
        }
    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
