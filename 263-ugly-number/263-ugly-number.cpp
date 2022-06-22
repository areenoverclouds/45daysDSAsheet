class Solution {
public:
    bool isUgly(int n) {
        if(!n) return false;
        for(int i = 6; i >= 2; i--){
            while(n%i == 0){
                n /= i;
            }
        }
        return n==1;
    }
};