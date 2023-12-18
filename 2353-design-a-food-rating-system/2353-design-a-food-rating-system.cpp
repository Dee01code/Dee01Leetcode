class FoodRatings {
public:
    
    unordered_map<string, int> food_Rate;
    unordered_map<string,string> food_Cuisine;
    unordered_map<string, set<pair<int,string>>> cuisine_Rate;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();
        
        for(int i = 0; i < n; i++){
            string name = foods[i], type = cuisines[i];
            int rate = ratings[i];
            
            food_Rate[name] = rate;
            food_Cuisine[name] = type;
            cuisine_Rate[type].insert({-rate,name});
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRate = food_Rate[food];
        string type = food_Cuisine[food];
        food_Rate[food] = newRating;
        cuisine_Rate[type].erase({-oldRate,food});
        cuisine_Rate[type].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto it = cuisine_Rate[cuisine].begin();
        return (it->second);
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */