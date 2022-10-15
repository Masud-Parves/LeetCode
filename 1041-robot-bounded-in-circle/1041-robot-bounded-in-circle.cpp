class Solution {
private:
    string leftDirection = "WSEN";
    string rightDirection = "ENWS";
public:
    bool isRobotBounded(string instructions) {
        char currFace = 'N';
        int currX = 0, currY = 0;
        
        unordered_map<char, int> cacheFace;
        cacheFace['N'] = 0;
        cacheFace['W'] = 1;
        cacheFace['S'] = 2;
        cacheFace['E'] = 3;

        for(auto& ch : instructions){
            if(ch == 'G'){
                currX += (currFace == 'E') ? 1 : 0;
                currX += (currFace == 'W') ? -1 : 0;
                currY += (currFace == 'N') ? 1 : 0;
                currY += (currFace == 'S') ? -1 : 0;
            } else {
                currFace = (ch == 'L') ? leftDirection[cacheFace[currFace]] : rightDirection[cacheFace[currFace]];
            }
        }
        return (currX == 0 && currY == 0) || (currFace != 'N');
    }
};