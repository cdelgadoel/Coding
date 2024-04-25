#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
struct Trie{
    struct Node{
        Node *children[2];
    };
    struct Node *getNode() 
    { 
        struct Node *pNode =  new Node; 
        for (int i = 0; i < 2; i++) 
            pNode->children[i] = NULL; 
        return pNode; 
    } 
    Node* root;

    Trie(){
        root = getNode();
    }

    void insert(int num) 
    { 
        Node *it = root; 
        for (int i = 30; i >= 0; --i) 
        { 
            int index = num & (1<<i) ? 1 : 0; 
            if (!it->children[index]) 
                it->children[index] = getNode(); 
            it = it->children[index]; 
        } 
    } 

	int getMaxXOR(int x){
		int resp = 0;
		Node *it = root; 
		for (int b = 30; b >= 0; --b){
			if(x & (1<<b)){
				// queremos tomar el camino del cero
				if(!it->children[0]){
					// afuerza tomamos el del uno
					it = it -> children[1];
				}
				else{
					// tomamos el del cero
					resp += (1<<b);
					it = it -> children[0];
				}
			}
			else{
				// queremos tomar el camino del uno
				if(!it->children[1]){
					// afuerza tomamos el del cero
					it = it -> children[0];
				}
				else{
					// tomamos el del uno
					resp += (1<<b);
					it = it -> children[1];
				}
			}
		}
		return resp;
	}

};
 
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(), arr.end());
	vector<int> resps (queries.size());
	vector<int> order (queries.size());
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(),  [&queries](int a, int b) { return queries[a][1] < queries[b][1]; });

	int p = 0;
	Trie trie;
	for(int i = 0, qId;  i < order.size(); ++i){
		qId = order[i];
		while(p < arr.size() && arr[p] <= queries[qId][1]){
			trie.insert(arr[p]);
			++p;
		}

		if(p == 0)
			resps[qId] = -1;
		else
			resps[qId] = trie.getMaxXOR(queries[qId][0]);
	}

	return resps;
}