class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> seen = {{1000, "M"},{900, "CM"} , {500, "D"},{400, "CD"} , {100, "C"} , {90, "XC"}, {50, "L"}, {40, "XL"},{10, "X"}, {9, "IX"},{5, "V"} , {4, "IV"},{1, "I"} };
        string result = "";
        while(num>0){
            for(auto& p : seen){
                if(num>=p.first){
                    result += p.second;
                    num -= p.first;
                    cout << p.first << " " << p.second << " " << num << endl;
                    break;
                }
            }
        }
    
        return result;
    }
};