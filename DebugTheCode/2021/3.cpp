#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define maxn 100000
#define minn 2
#define maxv 100000000
#define minv 1
#define maxs 25
#define mins 1

int vacations[maxn];
int n, s;

bool verify(int a) {
    int projects = 0, nextStartDate = 0;
    for (int i = 0; i < n; i++) {
        if (vacations[i] >= nextStartDate) {
            projects++;
            nextStartDate = vacations[i] + a;
        }
    }
    return (projects <= s);
}

int HACK() {
    int low = 1,
        high = 3e8,
        ans = -1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (verify(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int AC() {
    int low = 1,
        high = 3e8,
        ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (verify(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main(void) {

    spoj_init();

    ll inp;
    int ret = fscanf(spoj_t_out, "%lld", &inp);
    spoj_assert(ret == 1 && inp <= maxn && inp >= minn);
    n = inp;

    ret = fscanf(spoj_t_out, "%lld", & inp);
    spoj_assert(ret == 1 && inp <= maxs && inp >= mins && inp < n);
    s = inp;
    for (int i = 0; i < n; i++) {
        ret = fscanf(spoj_t_out, "%lld", & inp);
        spoj_assert(ret == 1 && inp >= minv && inp <= maxv);
        vacations[i] = inp;
    }
    sort(vacations, vacations + n);

    for (int i = 1; i < n; i++) {
        spoj_assert(vacations[i - 1] != vacations[i]);
    }

    int a = HACK();
    int b = AC();

    spoj_assert(a != b);

    return 0;
}
