class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if(emails.size() <= 1) {
            return emails.size();
        }
        
        unordered_set<string>unique;
        
        for(auto& email : emails){
            
            string name ="", domain = "";
            for(int i=0; i<email.size() ; i++){
                if(email[i] == '+' || email[i] == '@') break;
                if(email[i] == '.') continue;
                name += email[i];
            }
            
            for(int i=email.size()-1; i>=0; i--){
                if(email[i] == '@') break;
                domain += email[i];
            }
            
            reverse(domain.begin(), domain.end());
            unique.insert(name+'@'+domain);
        }
        return unique.size();
    }
};