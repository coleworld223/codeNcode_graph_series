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

        vector <ll> shor_path (n);

        function <void (ll node, ll dis, ll par)> dfs = [&] (ll node, ll dis, ll par) -> void {
            shor_path[node] = dis;
            for (auto child : adj[node]) {
                if (child == par) continue;
                dfs (child, dis + 1, node);
            }
        };

        dfs (0, 0, -1);

        for (ll i = 0; i < n; i++) {
            cout << shor_path[i] << " ";
        }
        cout << endl;
    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
