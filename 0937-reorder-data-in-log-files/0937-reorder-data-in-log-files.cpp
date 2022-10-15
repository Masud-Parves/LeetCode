class Solution {
public:
    static bool cmp(string& s1, string& s2){
        
        string list1 = string(s1.begin()+s1.find(' '), s1.end());
        string list2 = string(s2.begin()+s2.find(' '), s2.end());
        
        return list1 == list2 ? s1<s2 : list1<list2;
    } 
    vector<string> reorderLogFiles(vector<string>& logs) {
        int idx = logs.size()-1;
        
        int count = 0;
        for(int i=logs.size()-1; i>=0; i--){
            int pos = logs[i].find(' ');
            if(isdigit(logs[i][pos+1])){
                swap(logs[idx--], logs[i]);
            } else count++;
        }

        sort(logs.begin(), logs.begin()+count, cmp);
        return logs;
    }
};