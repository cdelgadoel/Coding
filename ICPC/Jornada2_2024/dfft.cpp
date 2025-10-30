#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdint>
#define INF 1000000000000000000
#define MOD 998244353
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define sz(a) a.size()

#define V vector
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ft front()


// ===== NNT
template <typename T>
T extGcd(T a, T b, T& x, T& y) {
   if (b == 0) {
      x = 1;
      y = 0;
      return a;
   }
   else {
      int g = extGcd(b, a % b, y, x);
      y -= a / b * x;
      return g;
   }
}

template <typename T>
T modInv(T a, T m) {
   T x, y;
   extGcd(a, m, x, y);
   return (x % m + m) % m;
}

long long crt(const std::vector< std::pair<int, int> >& pp, int mod = -1);


struct FFT_mod {
   int mod, root, root_1, root_pw;
};

extern FFT_mod suggested_fft_mods[5];
void ntt_shortmod(std::vector<int>& a, bool invert, const FFT_mod& mod_data);


const int mod = 1000000007;

vector<int> mull(const vector<int>& left, const vector<int>& right, const FFT_mod& mod_data) {
   vector<int> left1 = left, right1 = right;
   ntt_shortmod(left1, false, mod_data);
   ntt_shortmod(right1, false, mod_data);

   for (int i = 0; i < left.size(); i++) {
      left1[i] = (left1[i] * 1ll * right1[i]) % mod_data.mod;
   }

   ntt_shortmod(left1, true, mod_data);
   return left1;
}


vector<int> mult(vector<int>& left, vector<int>& right) {
   int ssss = left.size() + right.size() - 1;
   int pot2;
   for (pot2 = 1; pot2 < ssss; pot2 <<= 1);

   left.resize(pot2);
   right.resize(pot2);

   vector<int> res[3];
   for (int i = 0; i < 3; i++) {
      res[i] = mull(left, right, suggested_fft_mods[i]);
   }

   vector<int> ret(pot2);
   for (int i = 0; i < pot2; i++) {
      vector< pair<int,int> > mod_results;
      for (int j = 0; j < 3; j++) {
         mod_results.emplace_back(res[j][i], suggested_fft_mods[j].mod);
      }
      ret[i] = crt(mod_results, mod);
   }
   return ret;
}

long long crt(const std::vector< std::pair<int, int> >& a, int mod) {
   long long res = 0;
   long long mult = 1;

   int SZ = a.size();
   std::vector<int> x(SZ);
   for (int i = 0; i<SZ; ++i) {
      x[i] = a[i].first;
      for (int j = 0; j<i; ++j) {
         long long cur = (x[i] - x[j]) * 1ll * modInv(a[j].second,a[i].second);
         x[i] = (int)(cur % a[i].second);
         if (x[i] < 0) x[i] += a[i].second;
      }
      res = (res + mult * 1ll * x[i]);
      mult = (mult * 1ll * a[i].second);
      if (mod != -1) {
         res %= mod;
         mult %= mod;
      }
   }

   return res;
}


FFT_mod suggested_fft_mods[] = {
   { 7340033, 5, 4404020, 1 << 20 },
   { 415236097, 73362476, 247718523, 1<<22 },
   { 463470593, 428228038, 182429, 1<<21},
   { 998244353, 15311432, 469870224, 1 << 23 },
   { 918552577, 86995699, 324602258, 1 << 22 }
};

int FFT_w[1050000];
int FFT_w_dash[1050000];


void ntt_shortmod(std::vector<int>& a, bool invert, const FFT_mod& mod_data) {
   // only use if mod < 5*10^8
   int n = (int)a.size();
   int mod = mod_data.mod;

   for (int i = 1, j = 0; i<n; ++i) {
      int bit = n >> 1;
      for (; j >= bit; bit >>= 1)
         j -= bit;
      j += bit;
      if (i < j)
         std::swap(a[i], a[j]);
   }

   for (int len = 2; len <= n; len <<= 1) {
      int wlen = invert ? mod_data.root_1 : mod_data.root;
      for (int i = len; i<mod_data.root_pw; i <<= 1)
         wlen = int(wlen * 1ll * wlen % mod_data.mod);

      long long tt = wlen;
      for (int i = 1; i < len / 2; i++) {
         FFT_w[i] = tt;
         FFT_w_dash[i] = (tt << 31) / mod;
         int q = (FFT_w_dash[1] * 1ll * tt) >> 31;
         tt = (wlen * 1ll * tt - q * 1ll * mod) & ((1LL << 31) - 1);
         if (tt >= mod) tt -= mod;
      }
      for (int i = 0; i<n; i += len) {
         int uu = a[i], vv = a[i + len / 2] % mod;
         if (uu >= 2*mod) uu -= 2*mod;
         a[i] = uu + vv;
         a[i + len / 2] = uu - vv + 2 * mod;

         for (int j = 1; j<len / 2; ++j) {
            int u = a[i + j];
            if (u >= 2*mod) u -= 2*mod;
            int q = (FFT_w_dash[j] * 1ll * a[i + j + len / 2]) >> 31;
            int v = (FFT_w[j] * 1ll * a[i + j + len / 2] - q * 1ll * mod) & ((1LL << 31) - 1);
            a[i + j] = u + v;
            a[i + j + len / 2] = u - v + 2*mod;
         }
      }
   }
   if (invert) {
      int nrev = modInv(n, mod);
      for (int i = 0; i<n; ++i)
         a[i] = int(a[i] * 1ll * nrev % mod);
   }
}

// ==============

vector<int> firstDigit(18);
vector<int> nonfirstDigit(19);
int resp[800];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    //fill first digit 
    for(int i = 1; i <= 9; ++i)
    for(int j = 1; j <= 9; ++j){
        if(i != j){
            ++firstDigit[i-j + 9];
        }
    }

    // fill nonfirst
    for(int i = 0; i <= 9; ++i)
    for(int j = 0; j <= 9; ++j){
        if(i != j){
            ++nonfirstDigit[i-j + 9];
        }
    }
    // firstDigit[0] = 1; firstDigit[1] = 1;
    // nonfirstDigit[0] = 1; nonfirstDigit[1] = 1;


    resp[1] = 0;
    vector<int> accum = firstDigit;
    loop(i, 2, 100){
        accum = mult(accum, nonfirstDigit);
        resp[i] = accum[9*i];
        accum.resize(min(18 + 19*(i-1), 7200));
        nonfirstDigit.resize(19);
        
    }

    loop(i, 1, 100){
        cout<<i<<" "<<resp[i]<<endl;
    }
    
    return 0;
}