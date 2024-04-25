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

using namespace std;

typedef int64_t ll;
typedef pair<int,int> pii;

#define INF 1000000000000
#define MOD 1000000007

#define loop(i,a,b) for(int i = a; i < b; ++i)

const int maxN = 1e6+5;
int n;

int toInt(string numero){
    int resp = 0;
    for(char c : numero){
        resp = 10*resp + (c-'0');
    }
    return resp;
}   

vector<pii> cads[maxN];
map<int, int> eventos;

void agrega(int i){
	int size = cads[i].size();
	if(size == 0 || (size&1))
		return;
	int suma = 0;
	for(int j = 0; j < size; ++j)
		suma += cads[i][j].first;
	if(suma != 0) return;
	
	suma = 0;
	int mini=1e6, posMini;
	for(int j = 0; j < size;++j){
		suma += cads[i][j].first;
		if(suma < mini){
			mini = suma; posMini = j;
		}
	}
	int ini = posMini;
	suma = 0;
	for(int it = 0; it < size; ++it){
		suma += cads[i][it].first;
		if(suma == mini){
			if(it == size-1){
				eventos[cads[i][it].second+1] += 1;
				
				eventos[1] += 1;
				eventos[cads[i][0].second+1] += -1;
				
			}
			else{
				eventos[cads[i][it].second+1] += 1;
				eventos[cads[i][it+1].second+1] += -1;
			}
		}
	}
}

void solve(){
	cin>>n;
	string x; int y, repre;
	loop(i, 1, n+1){
		cin>>x;
		y = toInt(x.substr(1));
		repre = x[0] =='s'? 1:-1;
		cads[y].push_back(pii(repre, i));
	}
	
	loop(i, 1, 1e6+1){
		agrega(i);
	}
	
	
	int suma = 0, sumaResp = 0, resp = 1; 
	for(auto e : eventos){
		suma += e.second;
		if(suma > sumaResp){
			resp = e.first; 
			sumaResp = suma;
		}
	}
	
	cout<<resp<<" "<<sumaResp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //if(fopen("case.txt", "r")) freopen("case.txt", "r", stdin);
    int t = 1;
    //int t; cin>>t;
    loop(i, 0, t){
        solve();
    }
    return 0; 
}
