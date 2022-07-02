class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        int i;
        
        // pushing 0 and n
        hc.push_back(0);
        vc.push_back(0);
        hc.push_back(h);
        vc.push_back(w);
        
        // sort both
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        
        // calculate heights
        vector<int> height;
        for(i = 0; i < hc.size()-1; i++){
            height.push_back(hc[i+1] - hc[i]);
        }
        
        vector<int> width;
        for(i = 0; i < vc.size()-1; i++){
            width.push_back(vc[i+1] - vc[i]);
        }
        
        long long int a = *max_element(height.begin(), height.end());
        long long int b = *max_element(width.begin(), width.end());
        
        // Multiply and return
        return (int)(a%1000000007*b%1000000007);
    }
};