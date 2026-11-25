class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int t=0;t<n-2;t++){
            if(t>0 &&nums[t]==nums[t-1]){
                continue;
            }
            int i=t+1;
            int j=nums.size()-1;
            while(i<j){
                int sum=nums[i]+nums[j]+nums[t];
                if(sum==0){
                    ans.push_back({nums[t],nums[i],nums[j]});
                    i++;
                    j--;
                    while(i<j &&nums[i]==nums[i-1]){
                        i++;
                    }
                     while(i<j &&nums[j]==nums[j+1]){
                        j--;
                    }
                }
                else if(sum<0){
                    i++;
                }else{
                    j--;
                }
            }
        }
        return ans;
        
    }
};
