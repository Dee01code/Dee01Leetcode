class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(begin(people),end(people));
        int st = 0;
        int end = people.size()-1;
        
        int cnt = 0;
        while(st <= end){
            if(st == end){
                cnt++;
                break;
            }
            if(people[st] + people[end] > limit){
                cnt++;
                end--;
            }
            if(people[st] + people[end] <= limit){
                cnt++;
                st++;
                end--;
            }
        }
        return cnt;
        
    }
};