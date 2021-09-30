//https://www.spoj.com/problems/CPCRC1C/
#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define rsrt(v) sort(v.begin(), v.end(), greater<int>())
#define rsrtl(v) sort(v.begin(), v.end(), greater<ll>())
#define fi(i, a, b) for (int i = a; i < b; i++)
#define fll(i, a, b) for (ll i = a; i < b; i++)
#define srt(v) sort(v.begin(), v.end())
#define pb push_back
#define g(v, i, j) get<i>(v[j])
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(),(x).end()
#define ll long long
ll md = 1000000007;
#define theartofwar                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define F first
#define S second
#define sz(v) v.size()
using namespace std;
#define dbg(x) cerr << #x << " = " << x << endl;
template <typename T>
T pw(T a, T b){
    T c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m);
        m = (m * m), b /= 2;
    }
    return c;
}
template <typename T>
T ceel(T a, T b){
    if (a % b == 0)
        return a / b;
    else
        return a / b + 1;
}
template <typename T>
T my_log(T n, T b){
    T i = 1, ans = 0;
    while (1){
        if (i > n){
            ans--;
            break;
        }
        if (i == n) break;
        i *= b, ans++;
    }
    return ans;
}
template <typename T>
T gcd(T a, T b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll pwmd(ll a, ll b){
    ll c = 1, m = a;
    while (b){
        if (b & 1) c = (c * m) % md;
        m = (m * m) % md;
        b /= 2;
    }
    return c;
}
ll modinv(ll n){
    return pwmd(n, md - 2);
}
ll inverse(ll i){
    if (i == 1)
        return 1;
    return (md - ((md / i) * inverse(md % i)) % md + md) % md;
}
bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b){
    return (a.second < b.second);
}
vector<ll> give_digits_vector(ll a){
    vector<ll> v;
    while (a > 0) v.pb(a % 10), a /= 10;
    reverse(v.begin(), v.end());
    return v;
}
ll sum_till_a(ll a){
    if (a < 10) return (a * (a + 1)) / 2;
    vector<ll> v = give_digits_vector(a);
    ll dp[10][91][2], n = v.size(); // index, sum, tight
    for (int i = 0; i < 10; i++) for (int j = 0; j <= 90; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = 0;
    for (int i = 0; i < v[0]; i++) dp[0][i][1] = 1;
    dp[0][v[0]][0] = 1;
    for (int i = 1; i < n; i++){
        for (int j = 0; j < 91; j++){
            if (j + v[i] < 91){
                dp[i][j + v[i]][0] += dp[i - 1][j][0];
            }
            for (int k = 0; k < 10; k++){
                if (j + k > 91) continue;
                if (k < v[i]) dp[i][j + k][1] += dp[i - 1][j][0];
                dp[i][j + k][1] += dp[i - 1][j][1];
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 90; i++) ans += i * (dp[n - 1][i][0] + dp[n - 1][i][1]);
    return ans;
}
int main()
{
    theartofwar;
    ll a, b;
    while (true){
        cin >> a >> b;
        if (a == -1 && b == -1) return 0;
        cout << sum_till_a(b) - sum_till_a(max(0ll, a - 1)) << "\n";
    }
}


