class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int, float>> carTimes(position.size());
        
        for(int i = 0; i < position.size(); i++)
            carTimes[i] = {position[i], (float)(target-position[i])/(float)speed[i]};
        sort(carTimes.begin(), carTimes.end());

        stack<int> toBeFleet;
        unordered_set<int> fleetHeads;
    
        for(int i = 0; i < carTimes.size(); i++){
            while(!toBeFleet.empty() && carTimes[toBeFleet.top()].second <= carTimes[i].second){
                fleetHeads.insert(i);
                
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
