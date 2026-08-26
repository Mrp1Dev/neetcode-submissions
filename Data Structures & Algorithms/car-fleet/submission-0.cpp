class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // .   .   .   |

        unordered_map<int, int> speeds;
        for(int i = 0; i < position.size(); i++)
            speeds[position[i]] = speed[i];
        sort(position.begin(), position.end());

        stack<int> toBeFleet;
        unordered_set<int> fleetHeads;
        auto time = [&](int i){
            return (float)(target-position[i])/(float)speeds[position[i]];
        };
        for(int i = 0; i < position.size(); i++){
            while(!toBeFleet.empty() && time(toBeFleet.top()) <= time(i)){
                fleetHeads.insert(i);
                //isFleet[i] = true;
                if(fleetHeads.contains(toBeFleet.top()))
                    fleetHeads.erase(toBeFleet.top());
                    
                toBeFleet.pop();
            }
            toBeFleet.push(i);
        }        
        while(!toBeFleet.empty()){
            fleetHeads.insert(toBeFleet.top());
            toBeFleet.pop();
        }
        return fleetHeads.size();
    }
    
};
