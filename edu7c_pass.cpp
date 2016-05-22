#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 200200;

int n, m;
int a[N];
int l[N], r[N], x[N];

inline bool read() {
	if (!(cin >> n >> m)) return false;
	forn(i, n) assert(scanf("%d", &a[i]) == 1);
	forn(i, m) {
		assert(scanf("%d%d%d", &l[i], &r[i], &x[i]) == 3);
		l[i]--, r[i]--;
	}
	return true;
}

int z[N];

inline void solve() {
    //找出上一个不一样元素的下标
	z[0] = -1;
	fore(i, 1, n) {
		if (a[i - 1] != a[i]) z[i] = i - 1;
		else z[i] = z[i - 1];
	}

	forn(i, m) {
		if (a[r[i]] != x[i]) printf("%d\n", r[i] + 1);
		else if (z[r[i]] >= l[i]) printf("%d\n", z[r[i]] + 1);
		else puts("-1");
	}
}

int main() {
#ifdef SU1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif

    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

    while (read()) {
		solve();
		//break;
	}

    return 0;
}
