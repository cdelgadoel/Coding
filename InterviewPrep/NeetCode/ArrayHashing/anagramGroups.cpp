#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< vector<string> > ans;
        unordered_map<string, int> indx;
        int nextIndx = 0;
        
        for(string s : strs){
            string s_copy = s;
            sort(s_copy.begin(), s_copy.end());
            
            auto it = indx.find(s_copy);
            if(it == indx.end()){
                indx[s_copy] = nextIndx;
                ans.push_back(vector<string>());
                ans[nextIndx].push_back(s);
                ++nextIndx;
            }
            else{
                ans[(*it).second].push_back(s);
            }
        }
        return ans;
    }
};
