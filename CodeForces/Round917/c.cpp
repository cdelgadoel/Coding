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
const int maxN = 2005, maxK = 100005;

int n, k, d;
int a[maxN], v[maxK], need[maxN], bucket[maxN];
vector<pii> vsort;
ll resp;

int bit[maxK];
void update(int pos, ll x){
    while(pos <= k){
        bit[pos] = bit[pos] + x;
        pos += pos&(-pos);
    }
}

ll query(int pos){
    ll suma = 0;
    while(pos > 0){
        suma = suma + bit[pos];
        pos -= pos&(-pos);
    }
    return suma;
}

void solve(){
    cin>>n>>k>>d;
    loop(i, 1, n+1) cin>>a[i];
    vsort.resize(k);
    loop(i, 1, k+1){ cin>>v[i]; vsort[i-1] = pii(v[i], i); }
    resp = (d-1)/2;

    loop(i, 1, n+1){
        need[i] = i - a[i];
    }
    
    fill(bucket+1, bucket + n + 1, 0);
    loop(i, 1, k+1){
        ++ bucket[ v[i] ];
    }

    for(int i = n-1; i>0; --i){
        bucket[i] += bucket[i+1];
    }

    vector<pii> events;
    events.clear();
    fill(bit, bit+k+1, 0);
    
    sort(vsort.begin(), vsort.end());
    int itVSORT = k-1;
    for(int i = n; i > 0; --i){
        while(itVSORT >= 0 && vsort[itVSORT].first >= i){
            update(vsort[itVSORT].second, 1);
            --itVSORT;
        }

        //cout<<"in "<<i<<" bucket: "<<bucket[i]<<" need: "<<need[i]<<endl;
        if(need[i] < 0) continue;
        else if(bucket[i] == 0 && need[i] > 0) continue;
        else if(bucket[i] == 0 && need[i] == 0){
            events.push_back(pii(0, 1));
        }

        // bucket[i] > 0 and need[i] >= 0
        // we search for the first one 
        else if(need[i] == 0){
            events.push_back(pii(0, 1));
            int ini = 1, fin = k, mid;
            while(ini != fin){
                mid = (ini + fin)/2;
                if(query(mid) > 0)
                    fin = mid;
                else
                    ini = mid+1;
            }
            events.push_back(pii(ini, -1));
        }    
        else{
            int mod = need[i] % bucket[i];
            if(mod > 0){
                int ini = 1, fin = k, mid;
                // we look for >= mod
                while(ini != fin){
                    mid = (ini + fin)/2;
                    if(query(mid) >= mod)
                        fin = mid;
                    else
                        ini = mid+1;
                }
                //cout<<"\tbinSearch result: "<<ini<<endl;
                ll dayIni = k*(need[i]/bucket[i]) + ini;
                //cout<<"\tdayini "<<dayIni<<endl;
                events.push_back(pii( dayIni, 1));

                ini = 1; fin = k;
                while(ini != fin){
                    mid = (ini + fin)/2;
                    if(query(mid) > mod)
                        fin = mid;
                    else
                        ini = mid+1;
                }
                //cout<<"\tbinSearch result: "<<ini<<endl;
                ll dayFin = k*(need[i]/bucket[i]) + ini;
                //cout<<"\tdayfin "<<dayFin<<endl;
                events.push_back(pii(dayFin, -1));
            }
            // mod == 0
            else{
                int ini = 1, fin = k, mid;
                // we look for >= mod
                while(ini != fin){
                    mid = (ini + fin)/2;
                    if(query(mid) >= bucket[i])
                        fin = mid;
                    else
                        ini = mid+1;
                }
                //cout<<"\tbinSearch result: "<<ini<<endl;
                ll dayIni = k*(need[i]/bucket[i] - 1) + ini;
                //cout<<"\tdayini "<<dayIni<<endl;
                events.push_back(pii( dayIni, 1));

                ini = 1; fin = k;
                while(ini != fin){
                    mid = (ini + fin)/2;
                    if(query(mid) > 0)
                        fin = mid;
                    else
                        ini = mid+1;
                }
                //cout<<"\tbinSearch result: "<<ini<<endl;
                ll dayFin = k*(need[i]/bucket[i]) + ini;
                //cout<<"\tdayfin "<<dayFin<<endl;
                events.push_back(pii(dayFin, -1));
            }
        }
    }

    sort(events.begin(), events.end());

    ll active = 0;
    //cout<<"EEEE"<<endl;
    for(pii e : events){
        //cout<<e.first<<" "<<e.second<<endl;
        if(e.first >= d) 
            break;

        if(e.second == -1){
            --active;
        }
        else{
            ++active;
            resp = max(resp, active + (d-e.first-1)/2);
        }
    }
    cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}