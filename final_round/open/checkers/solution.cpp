#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<long long, long long, long long> state;

// O(1) 
state upMonotone(state x, long long steps) {
    const auto& [a, b, c] = x;
    long long d1 = b-a, d2 = c-b;

    if(d1 < d2) {
        return { a + steps * d1, b + steps * d1, c };
    }
    else {
        return { a, b - steps * d2, c - steps * d2 };
    }
}

// O(1)
pair<state, long long> upMonotone(state x) {
    const auto& [a, b, c] = x;
    long long d1 = b-a, d2 = c-b;

    if(d1 == d2) {
        return { x, 0 };
    }

    long long steps = (max(d1, d2) - 1) / min(d1, d2);

    return { upMonotone(x, steps), steps };
}

inline bool isRootState(const state& x) {
    const auto& [a, b, c] = x;
    return b-a == c-b;
}

// O(log d)
state up(state x, long long steps) {
    while(steps > 0 && !isRootState(x)) {
        auto [mono, s] = upMonotone(x);
        if(s <= steps) {
            steps -= s;
            x = mono;
        }
        else {
            x = upMonotone(x, steps);
            steps = 0;
        }
    }
    return x;
}

// O(log d)
pair<state, long long> getRootState(state x) {
    long long steps = 0;
    while(!isRootState(x)) {
        auto [p, s] = upMonotone(x);
        steps += s;
        x = p;
    }

    return { x, steps };
}

state makeState(long long a, long long b, long long c) {
    long long x = min(min(a, b), c);
    long long z = max(max(a, b), c);
    return state(x, a+b+c-x-z, z);
}

state getLCA(state x, long long distX, state y, long long distY) {
    if(distX > distY) {
        return getLCA(y, distY, x, distX);
    }

    // distY >= distX
    y = up(y, distY-distX);

    if(x == y) {
        return x;
    }

    long long d = distX, bit = 1;
    while(bit <= d) {
        bit *= 2;
    }

    for(bit /= 2; bit > 0; bit /= 2) {
        if(up(x, bit) != up(y, bit)) {
            x = up(x, bit);
            y = up(y, bit);
        }
    }

    return up(x, 1);
}

int main() {
    long long a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    state s1 = makeState(a, b, c), s2 = makeState(x, y, z);
    auto [r1, k1] = getRootState(s1);
    auto [r2, k2] = getRootState(s2);

    if(r1 != r2) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    auto lca = getLCA(s1, k1, s2, k2);
    auto [_, k3] = getRootState(lca);

    cout << k1 + k2 - 2 * k3 << endl;
    return 0;
}
