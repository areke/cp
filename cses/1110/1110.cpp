#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<int> pos;
	char mini = 'z';
	for (int i = 0; i < s.length(); i++) {
		if (s[i] < mini) mini = s[i];
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == mini) pos.push_back((i + 1) % s.length());
	}
	int res = -1;
	for (int i = 1; i <= s.length(); i++) {
		if (pos.size() == 1) {
			res = (pos[0] - i + s.length()) % s.length();
			break;
		} else if (i * pos.size() >= s.length()) {
			vector<int> bad;
			vector<int> npos;
			for (int j = 0; j < pos.size(); j++) {
				//cout << pos[j] << endl;
				if ( ((pos[(j + 1) % pos.size()] + s.length() - pos[j]) % s.length()) <= i) {
					if (((pos[j] + s.length() - pos[(j + pos.size() - 1) % pos.size()]) % s.length()) > i) {
						npos.push_back((pos[j] - i + s.length()) % s.length());
						//cout << i << " " << (pos[j] - i + s.length()) % s.length() << endl;
					}
				}
			}
			if (!npos.size()) {
				res = (pos[0] - i + s.length()) % s.length();
				break;
			}
			pos = npos;
			i = 0;
		}
		mini = 'z';
		for (int x : pos) {
			if (s[x] < mini) mini = s[x];
		}
		vector<int> npos;
		for (int x  : pos) {
			if (s[x] == mini) npos.push_back((x + 1) % s.length());
		}
		pos = npos;
	}
	for (int i = 0; i < s.length(); i++) {
		cout << s[(i + res) % s.length()];
	}
	cout << endl;

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
