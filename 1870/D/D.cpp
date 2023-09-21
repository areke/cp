#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int n;
    cin >> n;

    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    long long k;
    cin >> k;
    vector<pair<long long, int> > v(n);
    for (int i = 0; i < n; i++) {
      v[i] = {c[i], i};
    }
    sort(v.begin(), v.end());
    int l = 0, r = 0;
    vector<long long> cnt(n, 0);
    long long used = 0;
    int best = -1;
    int last = -1;
    for (int i = 0; i < n; i++) {
      if (v[i].second < best) continue;
      if (last >= 0) {
        long long low = 0;
        long long high = cnt[v[last].second];
        long long best = 0;
        while (low <= high) {
          long long mid = (low + high) / 2;
          long long tot = mid * v[last].first + k;
          assert(tot / v[i].first <= mid);
          if (tot / v[i].first >= mid) {
            best = mid;
            low = mid + 1;
          } else {
            high = mid - 1;
          }
        }
        cnt[v[last].second] -= best;
        long long ac = k + best * v[last].first;
        cnt[v[i].second] += ac / v[i].first;
        k = ac % v[i].first;
      } else {
        cnt[v[i].second] += k / v[i].first;
        k = k % v[i].first;
      }
      used += cnt[v[i].second];
      best = v[i].second;
      last = i;
    }
    vector<long long> res(n, 0);
    res[n - 1] = cnt[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      res[i] = res[i + 1] + cnt[i];
    }
    for (int i = 0; i < n; i++) {
      cout << res[i] << " \n"[i == n - 1];
    }
  }

  // IF STUCK:
    // DIV CONQUER?
    // CONSIDER SMALL CASES
    // INDUCTION
  return 0;
}
