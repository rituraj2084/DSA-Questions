class Solution {
public:
    string countOfAtoms(string formula) {
        map <string, int> mp;
        int multiplier = 1;
        stack <int> st;
        int n = formula.length();

        for(int i=n-1; i>=0; i--){
            int num = 1;
            if(isdigit(formula[i])){
                string temp ="";
                while(isdigit(formula[i])){
                    temp+=formula[i];
                    i--;
                }
                reverse(temp.begin(), temp.end());
                num = stoi(temp);
            }
            
            if(formula[i] == ')'){
                st.push(num);
                multiplier *= num;
            }
            
            if((formula[i] >= 'a' && formula[i] <= 'z') || (formula[i] >= 'A' && formula[i] <= 'Z')){
                string temp = "";
                while(formula[i] >= 'a' && formula[i] <= 'z'){
                    temp += formula[i];
                    i--;
                }
                temp+=formula[i];
                reverse(temp.begin(), temp.end());
                mp[temp] += (num * multiplier);
            }

            if(formula[i] == '('){
                multiplier /= st.top();
                if(!st.empty()) st.pop();
            }
        }

        string ans="";
        for(auto it: mp){
            ans+=it.first;
            if(it.second > 1) ans+= to_string(it.second);
        }

        return ans;
    }
};