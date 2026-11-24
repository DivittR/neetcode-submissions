class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix_prod=1;
        int suffix_prod=1;
        int n = nums.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        for(int i=0;i<n;i++){
            prefix[i]=prefix_prod;
            prefix_prod*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            suffix[i]=suffix_prod;
            suffix_prod*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=suffix[i]*prefix[i];
        }
        return ans;

    }
};
