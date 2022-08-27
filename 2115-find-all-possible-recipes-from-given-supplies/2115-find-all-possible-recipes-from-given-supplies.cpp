class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int numOfRecipes = recipes.size();
        
        unordered_map<string, bool> allSupplies;
        for(auto& supply : supplies){
            allSupplies[supply] = true;
        }
        
        vector<string> result;
        vector<bool> visited(numOfRecipes, false);
        bool continueCooking = true;
        
        
        while(continueCooking){
            continueCooking = false;
            bool isCreated;
            for(int i=0; i<numOfRecipes; i++){
                if(visited[i] == true) continue;
                
                isCreated = true;
                for(int need = 0; need<ingredients[i].size(); need++){
                    if(allSupplies.find(ingredients[i][need]) == allSupplies.end()){
                        isCreated = false;
                        break;
                    }
                }

                if(isCreated == true){
                    visited[i] = true;
                    continueCooking = true;
                    result.push_back(recipes[i]);
                    allSupplies[recipes[i]] = true;
                }
            }
        }
        return result;
    }
};