class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0;
        int r=heights.size()-1;
        int maxwater=0;
        while(l<r){
            int h=min(heights[l],heights[r]);
            int b=r-l;
            int area=h*b;
            maxwater=max(area,maxwater);
            if(heights[l]<heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxwater;
        
    }
};
