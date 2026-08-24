class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() -1;
        int maxWater = 0;
        while(l != r){
            int hl = heights[l];
            int width = r - l;
            int height = min(hl, heights[r]);
            int water = width*height;
            if(water > maxWater) maxWater = water;
            if(height == hl) l++;
            else r--;
        }
        return maxWater;
    }
};
