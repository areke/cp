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
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		string s;
		cin >> s;
		vector<int> v(26, 0);
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			v[s[i] - 'a']++;
		}
		string a = "";
		string b = "";
		
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < v[i] / 2; j++) {
				a += (i + 'a');
				b += (i + 'a');
			}
			v[i] = v[i] % 2;
			if (v[i] == 1) {
				for (int j = i + 1; j < 26; j++) {
					if (v[j]) cnt++;
				}
				if (cnt == 1) {
					for (int j = i + 1; j < 26; j++) {
						if (v[j]) {
							for (int k = 0; k < v[j] / 2; k++) {
								a += (j + 'a');
								b += (j + 'a');
							}	
							v[j] = v[j] % 2;
						}
						if (v[j]) {
							a += (i + 'a');
							b += (j + 'a');
							v[i]--;
							v[j]--;
						}
					}
				}
				
				for (int j = i + 1; j < 26; j++) {
					if (v[j]) {
						a += (i + 'a');
						v[i]--;
						b += (j + 'a');
						v[j]--;
						break;
					}
				}
				break;
			}
		}
		int j = 25;
		for (int i = 0; i < 26; i++) {
			while (v[i]) {
				while (!v[j]) {
					j--;
				}
				a += ('a' + j);
				v[i]--;
				if (v[j]) {
					b += ('a' + i);
					v[j]--;
				}
			}
		}
		reverse(a.begin(), a.end());
		cout << b + a << endl;

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
