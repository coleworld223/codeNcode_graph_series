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

        bool bi = 1;

        vector <ll> col (n, -1);

        function <void (ll, ll)> dfs = [&] (ll node, ll c) -> void {
            col[node] = c;
            for (auto child : adj[node]) {
                if (col[child] == -1) {
                    dfs (child, 1 - c);
                }
                else if (col[child] == c) {
                    bi = 0;
                }
            }
        };

        for (ll i = 0; i < n; i++) {
            if (col[i] == -1) {
                dfs (i, 0);
            }
        }

        if (bi) {
            for (ll i = 0; i < n; i++) {
                cout << col[i] << " ";
            }
        }
        else {
            cout << "Not bipartite" << endl;
        }

    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
