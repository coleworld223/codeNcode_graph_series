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

        bool cyc = 0;

        vector <ll> vis (n + 1), pr (n + 1);

        function <void (ll, ll)> dfs = [&] (ll node, ll par) -> void {
            vis[node] = 1;
            pr[node] = par;
            for (auto child : adj[node]) {
                if (vis[child] == 0) {
                    dfs (child, node);
                }
                else {
                    if (child != par) cyc = 1;
                }
            }
        };

        function <void (ll)> bfs = [&] (ll node) -> void {
            queue <vector <ll>> q;
            q.push ({node, -1});
            vis[node] = 1;
            pr[node] = -1;

            while (!q.empty()) {
                ll c_node = q.front()[0], par = q.front()[1]; q.pop();
                for (auto child : adj[c_node]) {
                    if (vis[child] == 0) {
                        q.push({child, c_node}); vis[child] = 1;
                        pr[child] = c_node;
                    }
                    else {
                        if (child != par) {
                            cyc = 1;
                        }
                    }
                }
            }
        };

        for (ll i = 0; i < n; i++) {
            if (vis[i] == 0) {
                // dfs (i, -1);
                bfs (i);
            }
        }

        cout << cyc << endl;
    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
