class NumArray {
public:
    vector<int> st;
    vector<int> dup;
    int n;
    NumArray(vector<int>& nums) {
        dup = nums;
        n = nums.size();
        st.resize(n*4, 0);
        build(nums, 0, 0, n-1);
    }
    
    void build(vector<int> &nums, int i, int ss, int se){
        if(ss == se){
            st[i] = nums[ss];
            return;
        }
        int mid = (ss+se)/2;
        build(nums, 2*i+1, ss, mid);
        build(nums, 2*i+2, mid+1, se);
        st[i] = st[2*i+1] + st[2*i+2];
    }
    
    void modify(int low, int high, int &index, int &target, int pos){
        if(low <= index && high >= index) st[pos] = st  [pos]+target;
        if(low == high) return;
        if(low>index ||high<index) return ;
        int mid = low + (high-low)/2;
        modify(low, mid, index, target, 2*pos+1);
        modify(mid+1, high, index, target, 2*pos+2);
    }
    
    void update(int i, int val) {
        int diff = val - dup[i];
        dup[i] = val;
        modify(0, n-1, i, diff, 0);
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
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */