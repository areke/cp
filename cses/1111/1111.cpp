#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;


vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	string s;
	cin >> s;
	int n = s.length();
	auto res = manacher(s);
	int maxi = 0;
	int best = 0;
	for (int i = 0; i < res.size(); i++) {
		if (i % 2 == 0) {
			if ((res[i] / 2) * 2 - 1 > maxi) {
				maxi = (res[i] / 2) * 2 - 1;
				best = i / 2;
			}
		} else {
			if ((res[i] - 1) > maxi) {	
				maxi = (res[i] - 1);
				best = i / 2;	
			}
		}
	}
	if (maxi % 2) {
		for (int i = best - maxi / 2; i <= best + maxi / 2; i++) {
			cout << s[i];
		}
	} else {
		for (int i = best - maxi / 2 + 1; i <= best + maxi / 2; i++) {
			cout << s[i];
		}
	}
	cout << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
