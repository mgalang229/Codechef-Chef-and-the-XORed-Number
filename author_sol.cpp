#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int m;
		cin >> m;
		if (m == 1) {
			// tricky case: to produce m = 1, 
			// if m is even, then m xor (m + 1) is 1 (smallest even is 2)
			// even xor odd = 1
			cout << 2 << '\n';
			continue;
		}
		// m must be in form of (2 ^ k) - 1
		int ans = -1;
		for (int i = 1; i <= 30; i++) {
			// (1 << i) = 1 * (2 ^ i) (power of two)
			int p = (1 << i);
			// (2 ^ i) xor ((2 ^ i) - 1) = ((2 ^ i) - 1)
			if ((p ^ (p - 1)) == m) {	
				// if m is found, then store (p - 1) since (p - 1) xor p will produce m
				ans = p - 1;
				// break the loop
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
