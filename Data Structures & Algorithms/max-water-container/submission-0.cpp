class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() -1;
        int maxWater = 0;
        while(l != r){
            int width = r - l;
            int height = min(heights[l], heights[r]);
            int water = width*height;
            if(water > maxWater) maxWater = water;
            if(height == heights[l]) l++;
            else r--;
        }
        return maxWater;
    }
};
