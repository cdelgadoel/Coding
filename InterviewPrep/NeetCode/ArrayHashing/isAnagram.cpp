#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        int bucket[26];
        fill(bucket, bucket+26, 0);
        for(int c : s)
            ++bucket[c-'a'];
        for(int c : t){
            --bucket[c-'a'];
            if(bucket[c-'a'] == -1)
                return false;
        }
        return true;
    }
};
