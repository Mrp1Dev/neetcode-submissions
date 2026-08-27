//#include <algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int total = 0;
        for(int p : piles) total +=p;
        unsigned long long hoursRequired = 2147483647;
        int k_min = max(total/h, 1);
        int k = 0;
        int k_max = *max_element(piles.begin(), piles.end());

        int l = k_min;
        int r = k_max;
        int lastValidK = r;
        while(l<=r){
            k = l + (r-l)/2;

            hoursRequired = 0;
            for(int p : piles){
                hoursRequired += (p % k == 0) ? p/k : p/k + 1;
            }

            if(hoursRequired > h) l = k + 1;
            else{
                lastValidK = k;
                r = k - 1;
            } 
        }
        return lastValidK;
    }
};
