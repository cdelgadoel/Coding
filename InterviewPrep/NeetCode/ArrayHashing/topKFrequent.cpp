class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int bucket[20001];
        fill(bucket, bucket+20001, 0);
        for(int v : nums)
            ++bucket[v+10000];
        
        priority_queue<pii, vector<pii>, greater<pii> > minHeap;
        for(int i = 0; i < 20001;++i){
            if(bucket[i] == 0) continue;
            if(minHeap.size() < k){
                minHeap.push(pii(bucket[i], i-10000));
            }
            else{
                if(minHeap.top().first < bucket[i]){
                    minHeap.pop();
                    minHeap.push(pii(bucket[i], i-10000));
                }
            }
        }
        vector<int> ans(k);
        int it = -1;
        while(!minHeap.empty()){
            ans[++it] = minHeap.top().second;
            minHeap.pop();
        }
        return ans;
    }
};