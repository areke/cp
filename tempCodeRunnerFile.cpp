#include <bits/stdc++.h>
#define pb emplace_back
#define N 100005
#define A 70
#define mod 1000000007
 
std::vector<int> primes;
int mask[A + 1];
 
void sieve(int n) {
  std::vector<bool> q_prime(n, true);
  for (int p = 2; p * p <= n; ++p)
    if (q_prime[p])
      for (int q = p * p; q <= n; q += p)
	q_prime[q] = false;
 
  for (int p = 2; p <= n; ++p)
    if (q_prime[p])
      primes.pb(p);
 
  std::reverse(primes.begin(), primes.end());
}
 
inline int get_mask(int n) {
  int ret = 0;
 
  for (int p : primes) {
    ret <<= 1;
    while (n % p == 0) {
      ret ^= 1;
      n /= p;
    }
  }
 
  return ret;
}
 
inline int pow2(int n) {
  int ret = 1; 
  for (int i = 0; i < n; ++i)
    ret = 2 * ret % mod;
  return ret;
}
 
void solve() {
  int n, a;
  std::cin >> n;
 
  sieve(A);
 
  for (int i = 1; i <= A; ++i)
    mask[i] = get_mask(i);
 
  int MASK = 1 << primes.size();
  std::vector<std::vector<int>> dp(A + 1, std::vector<int>(MASK, 0ll));
 
  // cnt[i] counts the number of ways to select even/odd
  // number of elements from a[1..n] with value equal to i
  std::vector<int> cnt(A + 1);
 
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    ++cnt[a];
  }
 
  for (int i = 1; i <= A; ++i)
    if (cnt[i])
      cnt[i] = pow2(cnt[i] - 1);
 
  dp[0][0] = 1;
 
  for (int i = 1; i <= A; ++i)
    for (int m = 0; m < MASK; ++m) {
      int even = cnt[i] ? cnt[i] : 1, odd = cnt[i];
      dp[i][m] = (dp[i - 1][m] * even % mod + dp[i - 1][m ^ mask[i]] * odd % mod) % mod;
    }
 
  std::cout << dp[A][0] - dp[0][0] << std::endl;
}
 
int main() { 
  solve();
}