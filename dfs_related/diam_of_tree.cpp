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

        vector <ll> dis (n, -1);

        function <void (ll, ll)> dfs = [&] (ll node, ll d) -> void {
            dis[node] = d;
            for (auto child : adj[node]) {
                if (dis[child] == -1) {
                    dfs (child, d + 1);
                }
            }
        };

        dfs (0, 0);

        ll idx = max_element (dis.begin(), dis.end()) - dis.begin();
        dis.clear(); dis.resize(n, -1);

        dfs (idx, 0);
        ll diam = *max_element (dis.begin(), dis.end());

        cout << diam << endl;
    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
