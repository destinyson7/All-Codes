#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<vector<long long>> mll;
typedef vector<pair<long long, long long>> vpl;
typedef long double ld;
typedef vector<long double> vld;
typedef vector<vector<long double>> mld;
typedef vector<bool> vbl;
typedef vector<vector<bool>> mbl;
#define minimize(a, b) (a = min(a, b))
#define maximize(a, b) (a = max(a, b))
const long long MOD = 1e9 + 7;

template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
    ll n = vec.size();
    for (int i = 0; i < n; i++)
        in >> vec[i];
    return in;
}
template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
    for (auto val : vec)
        out << val << " ";
    out << endl;
    return out;
}

class PermutationAnnealer {
   public:
    ll score = 0;
    ld temperature = 1.0;
    vll state;

    ll size = 0, tables = 0, chairs = 0;
    mll cost_matrix;

    PermutationAnnealer(ll n, ll t, mll &cost_matrix) {
        this->size = n;
        this->tables = t;
        this->chairs = n / t;
        this->cost_matrix = cost_matrix;
        state = vll(size);
        iota(state.begin(), state.end(), 0ll);
        random_state_fn();
        score = cost_fn(state);
    }

    ll anneal(ll maxsteps = 1000) {
        ll cost = cost_fn(state);
        for (int step = 0; step < maxsteps; step++) {
            temperature = temperature_fn(temperature);
            pll positions = neighbour_fn();
            ll new_cost =
                cost + cost_fn(state, positions.first, positions.second);
            if (acceptance_fn(cost, new_cost, temperature) > rand()) {
                cost = new_cost;
                swap(state[positions.first], state[positions.second]);
            }
        }
        return cost;
    }

    void random_state_fn() {
        random_shuffle(state.begin(), state.end());
    }

    ll cost_fn(vll &state) {
        ll answer = 0;
        for (int i = 0; i < tables; i++) {
            for (int j = 0; j < chairs; j++) {
                for (int k = j + 1; k < chairs; k++) {
                    answer += cost_matrix[state[i * chairs + j]]
                                         [state[i * chairs + k]];
                }
            }
        }
        return answer;
    }

    ll cost_fn(vll &state, ll pos1, ll pos2) {
        if (pos1 / chairs == pos2 / chairs)
            return 0;
        ll answer = 0;
        ll pos1_group = pos1 / chairs, pos1_id = pos1 % chairs,
           pos2_group = pos2 / chairs, pos2_id = pos2 % chairs;
        for (int j = 0; j < chairs; j++) {
            answer -= cost_matrix[state[pos1]][state[pos1_group * chairs + j]];
        }
        for (int j = 0; j < chairs; j++) {
            answer -= cost_matrix[state[pos2]][state[pos2_group * chairs + j]];
        }
        for (int j = 0; j < chairs; j++) {
            if (j != pos2_id)
                answer +=
                    cost_matrix[state[pos1]][state[pos2_group * chairs + j]];
        }
        for (int j = 0; j < chairs; j++) {
            if (j != pos1_id)
                answer +=
                    cost_matrix[state[pos2]][state[pos1_group * chairs + j]];
        }
        return answer;
    }

    ld acceptance_fn(ll old_cost, ll new_cost, ld temp) {
        return exp((new_cost - old_cost) / temp);
    }

    ld temperature_fn(ld temp) {
        return temp * 0.99;
    }

    pll neighbour_fn() {
        pll res = {rand() % size, rand() % size};
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, t;
    cin >> n >> t;
    mll costs(n, vll(n, 0));
    cin >> costs;
    PermutationAnnealer x(n, t, costs);
    ll cost = x.anneal(1000000);
    for (auto el : x.state)
        cout << el << " ";
    cout << endl;
    cout << cost << " " << endl;
}