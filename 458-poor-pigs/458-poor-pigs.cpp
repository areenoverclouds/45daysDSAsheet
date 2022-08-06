class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int trials = minutesToTest/minutesToDie;
        return ceil(log(buckets)/log(trials+1));
    }
};