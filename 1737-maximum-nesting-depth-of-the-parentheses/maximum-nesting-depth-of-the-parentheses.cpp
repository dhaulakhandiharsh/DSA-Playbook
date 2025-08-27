class Solution {
public:
    int maxDepth(string s) {
       int cDepth = 0;
       int maxDepth = 0;
       for (int i=0; i<s.size(); i++){
        if(s[i] == '('){
            cDepth++;
            if(cDepth>maxDepth){
                maxDepth = cDepth;
            }
        }
        else{
            if(s[i] == ')'){
                cDepth--;
            }
        
        }

       }
       return maxDepth; 
    }
};