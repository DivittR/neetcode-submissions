class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //create an frequency map
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
         //create a min heap, so that when we pop elements when size of heap get greater than k, only the smallest element gets popped, not the greater frequncy element 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mp){
            //we push in order {frequency, element} because we need to compare frequency to pop lowest frequency.
            pq.push({it.second,it.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
    return ans;
    }
};
