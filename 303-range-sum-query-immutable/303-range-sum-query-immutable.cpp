class NumArray {
public:
    vector<int> st;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(n*4,0);
        build(nums, 0, 0, n-1);        
    }
    
    void build(vector<int> &nums, int i, int ss, int se){
        if(ss == se){
            st[i] = nums[ss];
            return;
        }
        int mid = (ss+se) / 2;
        build(nums, 2*i+1, ss, mid);
        build(nums, 2*i+2, mid+1, se);
        st[i] = st[2*i+1] + st[2*i+2];
    }
    int sumRange(int left, int right) {
        return sum(left, right, 0, 0, n-1);
    }
    int sum(int ss, int se, int i, int start, int end){
        if(ss > se) return 0;
        if(ss == start && se == end) return st[i];
        int mid = (start + end)/2;
        return sum(ss, min(mid,se), i*2+1, start, mid)
             + sum(max(mid+1,ss), se, i*2+2, mid+1, end);        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */