#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main () {
    // int tests; cin >> tests;
    int tests = 1;

    auto solve = [&] () {
        ll n, m; cin >> n >> m;

        vector <vector <ll>> adj (n);

        // sssp algo for trees using dfs 

        for (ll i = 0; i < m; i++) {
            ll u, v; cin >> u >> v; u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector <ll> vis (n);

        bool cyc = 0;

        ll cc = 0;

        function <void (ll, ll)> dfs = [&] (ll node, ll par) -> void {
            vis[node] = 1;
            for (auto child : adj[node]) {
                if (vis[child] == 0) {
                    dfs (child, node);
                }
                else if (child != par) {
                    cyc = 1;
                }
            }
        };

        for (ll i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs (i, -1);
                cc++;
            }
        }

        if (cc == 1 && !cyc) {
            cout << "Yes a tree" << endl;
        }
        else cout << "No" << endl;

    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
