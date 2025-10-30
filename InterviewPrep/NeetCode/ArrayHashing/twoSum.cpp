#include <vector>
#include <unordered_map>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> indx;
        unordered_map<int, int> :: iterator look;
        bool found = false;
        int it = 0, v;
        while(!found){
            v = nums[it];

            look = indx.find(target - v);
            if(look == indx.end()){
                if(indx.find(v) == indx.end())
                    indx[v] = it;
            }
            else{
                ans.push_back( (*look).second);
                ans.push_back(it);
                found = true;
            }
            ++it;
        }
        return ans;
    }
};
