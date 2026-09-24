➡️ problemLinks --> https://leetcode.com/problems/lemonade-change/  &&  https://www.geeksforgeeks.org/problems/bus-ticket-change/1

Overview :: So we're basically selling lemonade for $5 each. and customers can give us either a $5, $10, or $20 bill. 
if its 5$ so ok, but if its 10$ or 20$ we need to give them change. and remember we will start selling with 0$. 
So if we can deal with all the given customers we return true, otherwise false.

✅ Optimized Approach --> class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      int fives = 0; // counter of 5$
      int tens = 0; // counter of 10$

      for(int i = 0; i < bills.size(); i++){
        if(bills[i] == 5) fives++; // sold successfully, and 5$ to money bag, nothing to return 
        else if(bills[i] == 10){
            // need to return 5$
            if(fives){
                fives--; // given 5$ change to customer so --
                tens++; // got 10$ so ++
            }else{
                return false; // unable to return money
            }   
        }else{ // means its 20$, no need to keep track of 20 as max money we can get is 20 not 30 40 
            if(tens && fives){ // will give a 10$ and a 5$ 
                tens--;
                fives--;
            }else if(fives >= 3){ // else will give 3 5$
                fives -= 3;
            }else{
                return false;
            }
        }
      }
      return true;  
    }
};

Time Complexity : O(n) 
Space Complexity : O(1) 

✅ Company Tags -->  