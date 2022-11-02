class Solution {
    
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> seen, visited;
        for(auto& bk : bank){
            seen[bk] = true;
        }
        
        vector<char> list;
        list.push_back('A');
        list.push_back('C');
        list.push_back('G');
        list.push_back('T');
        
        queue<pair<string, int>> todo;
        todo.push({start, 0});
        
        visited[start] = true;
        
        while(!todo.empty()){
            string uNode = todo.front().first;
            int dis = todo.front().second;
            
            todo.pop();
            
            
            if(uNode == end){
                return dis;
            }
            
            for(int i=0; i<8; i++){
                for(auto& ch : list){
                    if(uNode[i] == ch) continue;
                    
                    string vNode = uNode;
                    vNode[i] = ch;
                    if(seen[vNode] == true && visited[vNode] == false){
                        todo.push({vNode, dis+1});
                        visited[vNode] = true;
                    }
                }
            }
            
        }
        return -1;
    }
};