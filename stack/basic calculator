class Solution {
public:
    int calculate(string s) {
        
        int num=0,sign=1,res=0;
        //vector<int> 
        stack<int> signs,result;
        for(char c:s){
            if(isdigit(c)){
                num=num*10 +( c-'0');
            }
            else{
                res=res+num*sign;
                if(c=='+')sign=1;
                if(c=='-')sign=-1;
                
                num=0;
                if(c=='('){
                    signs.push(sign);
                    result.push(res);
                    res=0;
                    sign=1;
                }
                if(c==')'){
                    res=result.top()+res*signs.top();
                    result.pop();
                    signs.pop();

                }
            }
        }

        res+=sign*num;

        return res;
    }
};
