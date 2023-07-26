class Solution {
public:
    
    bool reachInTime(vector<int>& dist, double hour, double mid){
        double timeToReach = 0;
        for(int i = 0; i < dist.size(); i++){
            double rideTime = dist[i]/mid;
            if(i != dist.size()-1){
                rideTime = ceil(rideTime);
            }
            timeToReach += rideTime;
            if(timeToReach > hour) return 0;
        }
        return 1;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size()-1) return -1;
        int st = 1;
        int end = 1e7+1;
        while(st < end){
            int mid = st - (st - end)/2;
            cout << mid << endl;
            if(reachInTime(dist,hour,mid)) { cout << "Reaching in " << mid << endl; end = mid;}
            else st = mid+1;
        }
        return end;
    }
};