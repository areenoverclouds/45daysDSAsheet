/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long lb = 1, ub = n, num;
        
        while(lb <= ub){
            num = (lb+ub)/2;
            int val = guess(num);
            if(val == 0) return num;
            else if(val == 1) lb = num+1;
            else ub = num-1;
        }
        
        return num;
    }
};