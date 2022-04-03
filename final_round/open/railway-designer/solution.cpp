#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std; 

class DisjointSet {
private:
    int numSets;
    vector<int> parent, rank, setSize;

public:
    DisjointSet(int n) {
        numSets = n;
        parent.assign(n, 0);
        rank.assign(n, 0);
        setSize.assign(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int getParent(int u) {
        if(parent[u] == u) {
            return u;
        }

        // path compression
        return parent[u] = getParent(parent[u]);
    }

    bool isSameSet(int u, int v) {
        return getParent(u) == getParent(v);
    }

    int getSetSize(int u) {
        return setSize[getParent(u)];
    }

    int getNumSets() {
        return numSets;
    }

    void unionSets(int u, int v) {
        int uParent = getParent(u), vParent = getParent(v);
        if(uParent == vParent) {
            return;
        }

        // union by rank
        if(rank[uParent] > rank[vParent]) {
            swap(uParent, vParent);
        }

        parent[uParent] = vParent;

        if(rank[uParent] == rank[vParent]) {
            rank[vParent]++;
        }

        setSize[vParent] += setSize[uParent];
        numSets--;
    }
};

typedef pair<int, int>      edge;
typedef pair<double, edge> wedge;

double la[5050], lo[5050];
constexpr double multiplier = 2 * 6371;

inline double haversine(int i, int j) {
    double sin1 = sin(0.5 * (la[j] - la[i]));
    double sin2 = sin(0.5 * (lo[j] - lo[i]));
    return asin(sqrt(sin1*sin1 + cos(la[i])*cos(la[j])*sin2*sin2));
}

double mst(int n) {
    DisjointSet dsu(n);
    vector<wedge> edges;

    for(int u = 0; u < n; u++) {
        for(int v = u+1; v < n; v++) {
            edges.emplace_back(haversine(u, v), edge(u, v));
        }
    }

    sort(edges.begin(), edges.end());

    double ans = 0;
    for(const auto& [d, e] : edges) {
        const auto& [u, v] = e;

        if(dsu.isSameSet(u, v)) {
            continue;
        }

        ans += d;
        dsu.unionSets(u, v);

        if(dsu.getNumSets() == 1) {
            break;
        }
    }

    return ans * 2 * 6371;
}

int main() {
    int t;
    cin >> t;

    const double PI = 2 * acos(0);

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> la[i] >> lo[i];
            la[i] = la[i] / 180.0 * PI;
            lo[i] = lo[i] / 180.0 * PI;
        }

        int ans = mst(n);
        cout << ans << endl;
    }


    return 0;
}
