class Solution {
public:
    bool isNumber(string s) {
        int n=s.size(), i=0;

        // iterate over sign
        if(s[i]=='+' || s[i]=='-') i++;

        // checking ending condition
        if(i>=n) return false;
        
        bool beforeInt = false;

        // iterating digits
        while(isdigit(s[i]) && i<n){
            i++;
            beforeInt = true;
        }

        // checking ending condition
        if(i>=n) return true;

        // Passing dot
        bool dot = false;
        if(s[i] == '.') {i++; dot = true;}

        // check dot ending condition
        if(i>=n)
            if(dot==true && beforeInt==false) return false;
            else return true;

        // check digit after dot
        if(dot) 
        if(beforeInt) {
            if((!isdigit(s[i])) && (s[i]!='e' && s[i]!='E') ) 
                return false; 
        }
        else{  
            if(s[i]<'0' || s[i]>'9') return false; 
        }

        // iterate decimals until we reach last indext or e
        while(i<n && s[i]!='e' && s[i]!='E'){
            if(!isdigit(s[i])) return false;
            i++;
        }
        if(!dot)
        if((s[i]=='e' || s[i]=='E') && beforeInt==false) 
            return false;
        
        // checking ending condition
        if(i>=n) return true;
        
        i++; // next ot e
        
        if(s[i]=='+' || s[i]=='-') i++;

        // checking ending condition
        if(i>=n) return false;
        
        bool lastInt = false;
        // iterate over digits
        while(isdigit(s[i]) && i<n){
            i++;
            lastInt = true;
        }

        if(!lastInt) return false;

        if(i>=n) return true;
        return false;
            
    }
};