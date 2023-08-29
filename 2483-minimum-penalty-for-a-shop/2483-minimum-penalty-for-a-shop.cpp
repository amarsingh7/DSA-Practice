class Solution {
public:
    int bestClosingTime(string customers) {
        int minpen= 0, curpen=0;
        int earlhr=0;
        
        for(int i=0; i<customers.size(); i++)
        {
            char c= customers[i];
            
            if(c=='Y')
                curpen--;
            else
                curpen++;
            
            if(curpen<minpen)
            {
                minpen= curpen;
                earlhr= i+1;
            }
        }
        return earlhr;
    }
};