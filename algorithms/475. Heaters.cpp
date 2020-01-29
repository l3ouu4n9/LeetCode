/*
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:

Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
 

Example 1:

Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
 

Example 2:

Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int max_diff = 0, lastHeatIndex = 0;
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        vector<int>::iterator it;
        it = unique(houses.begin(), houses.end());
        houses.resize(distance(houses.begin(), it));
        it = unique(heaters.begin(), heaters.end());
        heaters.resize(distance(heaters.begin(), it));
        
        for(int i = 0; i < houses.size(); ++i){
            int min_diff = INT_MAX;
            for(int j = lastHeatIndex; j < heaters.size(); ++j){
                if(abs(houses[i] - heaters[j]) < min_diff){
                    min_diff = abs(houses[i] - heaters[j]);                    
                } else {
                    lastHeatIndex = j - 1;
                    break;
                }
            }
            
            if(max_diff < min_diff){
                cout << min_diff << endl;
                max_diff = min_diff;
            }
        }
        return max_diff;
    }
};
