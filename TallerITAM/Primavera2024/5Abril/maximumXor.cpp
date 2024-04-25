#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(), arr.end());

	vector<int> resps (queries.size());
	for(int i = 0, x, a, ini, fin, resp, ini2, fin2, m, m2; i < queries.size(); ++i){
		x = queries[i][0]; 
        a = queries[i][1];
		
    	if (arr[0] > a) {
            resps[i] = -1; 
		} 
		else{
			resp = 0;
			ini = 0;
			ini2 = 0; fin2 = arr.size()-1;
			while(ini2 != fin2){
				m2 = (ini2+fin2+1)/2;
				if( arr[m2] > a)
					fin2= m2-1;
				else
					ini2 = m2;
			}
			fin = ini2;
			for (int b = 30; b >= 0; --b) {
				// intento prender bit b
				// si todos lo tienen
				if(arr[ini]&(1<<b)){
                    if( ((1<<b)&x) == 0)
                        resp += 1<<b;
				}
                // si nadie lo tiene
				else if( (arr[fin]&(1<<b)) == 0){
                    if( x& (1<<b))
					    resp += (1<<b);
				}
                // si hay numeros que tanto lo tienen, como no lo tienen
				else{
					resp += (1<<b);
					if(x&(1<<b)){
						//quito a los que lo tienen
						ini2 = ini; fin2 = fin;
						while(ini2 != fin2){
							m2 = (ini2+fin2+1)/2;
							if(arr[m2] & (1<<b))
								fin2 = m2-1;
							else
								ini2 = m2;
						}
						fin = ini2;
					}
					else{
						//quito a los que no lo tienen 
						ini2 = ini; fin2 = fin;
						while(ini2 != fin2){
							m2 = (ini2+fin2)/2;
							if(!(arr[m2] & (1<<b)))
								ini2 = m2+1;
							else
								fin2 = m2;
						}
						ini = ini2;
					}
				}
			}
			resps[i] = resp;
		}
    }
	return resps;
}