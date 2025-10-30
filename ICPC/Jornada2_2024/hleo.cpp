#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <cstdint>

using namespace std;
typedef int64_t ll;
ll mx = INT64_MAX;
ll mn = INT64_MIN;

void solved()
{
    list<ll> v;
    ll n, r, c, movs;
    vector<ll> res;
    cin >> n >> r >> c;
    r--;
    c--;
    for (ll i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    auto s1 = v.begin();
    auto s2 = v.end();
    s2--;
    while (v.size() > 2)
    {
        movs = r % v.size();
        // se mueve s1 r
        while (movs--)
        {
            s1++;
            if (s1 == v.end())
            {
                s1 = v.begin();
            }
        }

        // se mueve s2 c
        movs = c % v.size();
        while (movs--)
        {
            if (s2 == v.begin())
            {
                s2 = v.end();
            }
            s2--;
        }

        if (*s1 == *s2)
        { // si es el mismo, contrata
            res.push_back(*s1);
            s1 = v.erase(s1);
            s2 = s1;
        }
        else
        { // si son distintos, no contrates
            s1 = v.erase(s1);
            if(s1 == s2){
                s1 = ++s2;
                --s2;
            }
            s2 = v.erase(s2);
        }
        if (s1 == v.end())
        {
            s1 = v.begin();
        }
        if (s2 == v.begin())
        {
            s2 = v.end();
        }
        s2--;
    }
    for (ll x : v)
    {
        res.push_back(x);
    }
    sort(res.begin(), res.end());
    for (ll x : res)
    {
        cout << x << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    solved();
}
