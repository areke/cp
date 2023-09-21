template <int len = 1>
void solve(int n) {
    if (n > len) {
        solve<std::min(len*2, MAXLEN)>(n);
        return;
    }
}