class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<string> answer;
        
        int nodes = friends.size();
        vector<bool> visited(nodes, false);
        
        queue<int> todo;
        todo.push(id);
        visited[id] = true;
        
        int currLevel = 0;
        vector<int> levelNodes;
        while(!todo.empty()){
            if(currLevel>level) break;
            
            int size = todo.size();
            levelNodes.clear();
            for(int i=0; i<size; i++){
                int uNode = todo.front();
                todo.pop();
                
                levelNodes.push_back(uNode);
                
                for(auto& vNode : friends[uNode]){
                    if(visited[vNode] == false){
                        visited[vNode] = true;
                        todo.push(vNode);
                    }
                }
            }
            currLevel++;
        }
        
        unordered_map<string, int> cache;
        
        for(auto& fnd : levelNodes){
            
            for(auto& video : watchedVideos[fnd]){
                cache[video]++;
            }
        }
        vector<pair<int, string>> seen;
        for(auto& m : cache){
            seen.push_back({m.second, m.first});
        }
        sort(seen.begin(), seen.end());
        
        for(auto& s : seen){
            answer.push_back(s.second);
        }
        return answer;
    }
};