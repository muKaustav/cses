#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef pair<char, int> pci;
typedef pair<string, int> psi;
typedef vector<pii> vpii;
typedef vector<pci> vpci;
typedef vector<psi> vpsi;
typedef map<int, int> mii;
typedef unordered_map<char, int> mci;
typedef unordered_map<string, int> msi;
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

class TreeNode {
public:
	TreeNode *left, *right;
	int data;

	TreeNode (int val) {
		left = right = NULL;
		data = val;
	}
};

int solve(int n, vector<int> &dp) {
	if (n == 0) return 1;
	if (n < 0) return 0;

	if (dp[n] != -1) return dp[n];

	int ways = 0;

	for (int i = 1; i <= 6; i++) {
		ways += solve(n - i, dp);
		ways %= MOD;
	}

	return dp[n] = ways;
}

int main() {
    fast_io;

    int n; cin >> n;

	vector<int> dp(n + 1, -1);

	cout << solve(n, dp) << endl;

    return 0;
}