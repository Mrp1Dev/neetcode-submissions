class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 0) return 0;
        if(s.size() == 1 ) return 1;

        vector<int> freqs(26);
        int longest = 0;
        int l = 0;
        int r = 0;
        freqs[s[0]-'A']++;
        while(r < s.size()){
            int windowSize = r - l + 1;
            int maxFreq = getMaxFreq(freqs);
            //cout << "l: " << l << " r: " << r << " windowSize: " << windowSize <<  " f_max: " << maxFreq << endl;
            if(windowSize - maxFreq <= k){
                if(r == s.size()-1){
                    break;
                }
                longest = max(r-l+1, longest);
                r++;
                freqs[s[r] - 'A']++;
            } else {
                freqs[s[l] - 'A']--;
                l++;
            }
            
           
        }
        longest = max(r-l+1, longest);
        return longest;
    }
    int getMaxFreq(const vector<int>& freqs){
        int m = 0;
        for(int i = 0; i < freqs.size(); i++){
            m = max(m, freqs[i]);
        }
        return m;
    }
};
