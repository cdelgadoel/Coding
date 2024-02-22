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
#define INF 1000000000000000000
#define MOD 1000000007
#define loop(i,a,b) for(int i = a; i < b; ++i)
using namespace std;
typedef int64_t ll;
typedef pair<int,int> pii;
const int maxN = 500005;

int gcd(int a, int b){
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);

    int c, d; cin>>c>>d;
    int gcdFizz = 0, gcdBuzz = 0;
    string s;
    loop(i, c, d+1){
        cin>>s;
        if(s == "Fizz")
            gcdFizz = gcd(gcdFizz, i);
        else if(s == "Buzz")
            gcdBuzz = gcd(gcdBuzz, i);
        else if(s == "FizzBuzz"){
            gcdFizz = gcd(gcdFizz, i);
            gcdBuzz = gcd(gcdBuzz, i);
        }
    }
    if(gcdFizz == 0)
        gcdFizz = d + 1;
    if(gcdBuzz == 0)
        gcdBuzz = d + 1;

    cout<<gcdFizz<<" "<<gcdBuzz<<"\n";
    return 0;
}