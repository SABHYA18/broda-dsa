class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size(), fleet = 0;
        double maxTime = 0.0;
        if(n==0) return 0;

        vector<pair<int, double>> cars(n);
        for(int i = 0; i<n; i++){
            double time = (double) (target-position[i])/speed[i];
            cars[i] = {position[i], time};
        }

        sort(cars.begin(), cars.end());

        for(int i = n-1; i>=0; i--){
            if(cars[i].second > maxTime){
                fleet++;
                maxTime = cars[i].second;
            }
        }
        return fleet;
    }
};
