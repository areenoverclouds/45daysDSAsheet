class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        int i = 0, boats = 0, j = people.size()-1;
        while(i <= j){
            int weight = people[i];
            boats++;
            i++;
            
            if((weight + people[j]) <= limit){
                j--;
            }
        }
        return boats;
    }
};