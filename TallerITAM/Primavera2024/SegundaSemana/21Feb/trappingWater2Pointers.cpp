#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int itLeft = 0, itRight = height.size()-1;
        int resp = 0;
        int maxiLeft = height[0], maxiRight = height[height.size() - 1];
        while(itLeft != itRight){
            if(maxiLeft <= maxiRight){
                // muevo izq
                resp += maxiLeft - height[itLeft];
                ++itLeft;
                maxiLeft = max(maxiLeft, height[itLeft]);
            }
            else{
                resp += maxiRight - height[itRight];
                --itRight;
                maxiRight = max(maxiRight, height[itRight]);
            }
        }
        return resp;
    }
};