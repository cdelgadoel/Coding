// Problema: https://leetcode.com/problems/trapping-rain-water/description/
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maximoIzq[n], maximoDer[n];
        // maximos izquierdos
        maximoIzq[0] = 0;
        for(int i = 1; i < n; ++i){
            maximoIzq[i] = max(maximoIzq[i-1], height[i-1]); 
        }

        // maximo derechos
        maximoDer[n-1] = 0;
        for(int i = (n-1) - 1; i >= 0; --i){
            maximoDer[i] = max(maximoDer[i+1], height[i+1]); 
        }

        int aguaT = 0;
        int alturaLimite;
        for(int i = 0; i < n; ++i){
            alturaLimite = min(maximoDer[i], maximoIzq[i]);
            aguaT += max(0, alturaLimite - height[i]);
        }
        return aguaT;
    }
};