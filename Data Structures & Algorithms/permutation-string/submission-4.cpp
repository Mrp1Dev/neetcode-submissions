class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1Freqs(26, 0);
        if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            s1Freqs[s1[i] - 'a']++;
        }
        vector<int> s2Freqs(26, 0);
        int l = 0;
        int longest = 0;
        for (int r = 0; r < s2.size(); r++) {

            while(s1Freqs[s2[r] - 'a'] <= 0 && l<r) {
                if (s2Freqs[s2[l] - 'a'] > 0)
                    s1Freqs[s2[l] - 'a']++;
                    s2Freqs[s2[l]-'a']--;
                    //cout << format("Shifted {} from S2 to S1\n", s2[l]);
                l++;
            } 
            
            if (s1Freqs[s2[r] - 'a'] > 0){
                s2Freqs[s2[r] - 'a']++;
                s1Freqs[s2[r] - 'a']--;
                //cout << format("Shifted {} from S1 to S2\n", s2[r]);
            }

            if(all_of(s1Freqs.begin(), s1Freqs.end(), [](int x){return x==0;})) return true;
        }
        return false;
    }
};
