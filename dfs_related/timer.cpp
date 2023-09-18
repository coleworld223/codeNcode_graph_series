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

        vector <ll> in_time (n, -1), out_time (n, -1);

        ll tim = 0;

        function <void (ll)> dfs = [&] (ll node) -> void {
            in_time [node] = tim++;
            for (auto child : adj[node]) {
                if (in_time[child] == -1) {
                    dfs (child);
                }
            }
            out_time[node] = tim++;
        };

        dfs (0);

        for (ll i = 0; i < n; i++) {
            cout << i << " :" << in_time[i] << " " << out_time[i] << endl;
        }
    };

    for (int i = 0; i < tests; i += 1) {
        solve ();
    }
}
