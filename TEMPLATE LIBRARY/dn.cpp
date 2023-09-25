// AUTHOR->DEV KUDAWLA
//----------------------------------------------------
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // find_by_order(it return an iterator input is a value), order_of_key(input is index)
// typedef tree<long long, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
#define ll long long
#define out(a) cout << a << " "
#define ot cout <<
#define in cin >>
#define vt(T) vector<T>
#define vl vector<long long>
#define flp(a) for (auto &i : a)
#define nline cout << "\n"
#define pb push_back
#define db pop_back
#define rt return
#define n_digit(n) (int)log10(n) + 1
#define msb(n) (int)(log2(n)) + 1
// it is 1 based
#define pll pair<ll, ll>
#define all(x) x.begin(), x.end()
#define lt(x) x.size()
#define ter(a, b, c) a ? b : c
#define yesno(a) a ? ot "Yes" : ot "No"
#define ff first
#define ss second
#define str string
#define tbits(x) __builtin_popcountll(x)
#define LOCAL_COMPILER
#ifdef LOCAL_COMPILER
#define dbg(x)        \
   cerr << #x << " "; \
   cerr << x << "\n";
#endif
#ifndef LOCAL_COMPILER
#define dbg(x)
#endif
//----------------------------------------------------
template <class T>
void vin(T &v)
{
   flp(v) { cin >> i; }
}
template <class T>
void vin(set<T> &s, ll n)
{
   for (int i = 0; i < n; i++)
   {
      T d;
      cin >> d;
      s.insert(d);
   }
}
template <class T>
void vin(multiset<T> &s, ll n)
{
   for (int i = 0; i < n; i++)
   {
      T d;
      cin >> d;
      s.insert(d);
   }
}
template <class T1, class T2>
void vin(map<T1, T2> &m, ll n)
{
   for (int i = 0; i < n; i++)
   {
      T1 a;
      T2 b;
      cin >> a;
      cin >> b;
      m[a] = b;
   }
}
template <class T>
void vin(map<T, ll> &m, ll n)
{
   for (int i = 0; i < n; i++)
   {
      T a;
      cin >> a;
      m[a]++;
   }
}
template <class T>
void vout(T v)
{
   for (int i = 0; i < lt(v); i++)
   {
      ot(v[i]);
      if (i != lt(v) - 1)
         ot(" ");
   }
}
inline ll power2(ll n)
{
   ll answer = 0;
   if (n != 0)
      answer = msb(((ll)n) ^ ((ll)(n - 1))) - 1;
   return answer;
}
//----------------------------------------------------
const ll N = 1e+9 + 7;
const ll N2 = 998244353;
const long double epsilon = 1e-9;
//----------------------------------------------------
// modulo arithmetic
ll expo(ll a, ll b, ll mod = LONG_LONG_MAX)
{
   ll res = 1;
   while (b > 0)
   {
      if (b & 1)
         res = (res * a) % mod;
      a = (a * a) % mod;
      b = b >> 1;
   }
   return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m = N)
{
   a = a % m;
   b = b % m;
   return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m = N)
{
   a = a % m;
   b = b % m;
   return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m = N)
{
   a = a % m;
   b = b % m;
   return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m = N)
{
   a = a % m;
   b = b % m;
   return (mod_mul(a, mminvprime(b, m), m) + m) % m;
} // only for prime m
ll ncr(ll n, ll r, bool mod_version, ll mod = N)
{
   ll answer = 0;
   if (n >= r)
   {
      if (mod_version == true)
      {
         ll a = 1;
         for (ll i = n; i >= n - r + 1; i--)
            a = mod_mul(a, i, mod);
         ll b = 1;
         for (ll i = 1; i <= r; i++)
            b = mod_mul(b, i, mod);
         b = mminvprime(b, mod);
         a = mod_mul(a, b, mod);
         answer = a;
      }
      else
      {
         ll a = 1;
         for (ll i = n; i >= n - r + 1; i--)
            a *= i;
         ll b = 1;
         for (ll i = 1; i <= r; i++)
            b *= i;
         answer = a / b;
      }
   }
   return answer;
}
ll factorial(ll n, bool mod_version, ll mod = N)
{
   ll answer = 1;
   if (mod_version == true)
   {
      for (int i = 2; i <= n; i++)
         answer = mod_mul(answer, i, mod);
   }
   else
   {
      for (int i = 2; i <= n; i++)
         answer *= i;
   }
   return answer;
}
ll npr(ll n, ll r, ll mod = LONG_LONG_MAX)
{
   ll answer = ncr(n, r, N) * factorial(r, N);
   answer %= N;
   return answer;
}
bool is_prime(ll a)
{
   if (a == 1)
      return false;
   for (ll i = 2; i * i <= a; i++)
   {
      if (a % i == 0)
         return false;
   }
   return true;
}
//----------------------------------------------------
// KMP search
void computeLPSArray(string pat, ll M, ll lps[])
{
   ll len = 0;
   ll i = 1;
   lps[0] = 0;
   while (i < M)
   {
      if (pat[i] == pat[len])
      {
         len++;
         lps[i] = len;
         i++;
      }
      else
      {
         if (len != 0)
            len = lps[len - 1];
         else
         {
            lps[i] = len;
            i++;
         }
      }
   }
}
ll KMPSearch(string pat, string txt)
{
   ll M = pat.length();
   ll N = txt.length();
   ll lps[M];
   ll j = 0;
   computeLPSArray(pat, M, lps);
   ll i = 0;
   ll res = 0;
   ll next_i = 0;
   while (i < N)
   {
      if (pat[j] == txt[i])
         i++, j++;
      if (j == M)
      {
         j = lps[j - 1];
         res++;
      }
      else if (i < N && pat[j] != txt[i])
      {
         if (j != 0)
            j = lps[j - 1];
         else
            i = i + 1;
      }
   }
   return res;
} // O(M+N)
map<ll, ll> prime_factors(ll n)
{
   map<ll, ll> answer;
   ll a = n;
   for (ll i = 2; i * i <= a; i++)
      while (a % i == 0)
         answer[i]++, a /= i;
   if (a > 1)
      answer[a]++;
   return answer;
}
//----------------------------------------------------
// const ll n_sieve = (1e6 + 9) + 1; // O(Nlog(log(N)))
// vector<bool> prime_sieve(n_sieve, true);
void initialise_sieve(vector<bool> &prime_sieve)
{
   prime_sieve[0] = false;
   prime_sieve[1] = false;
   for (ll i = 2; i < lt(prime_sieve); i++)
      if (prime_sieve[i] == true)
         for (ll j = 2; j * i < lt(prime_sieve); j++)
            prime_sieve[j * i] = false;
}
//----------------------------------------------------
// code starts here
//----------------------------------------------------