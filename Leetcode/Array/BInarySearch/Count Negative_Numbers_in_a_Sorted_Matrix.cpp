class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0;
        int r = nums.size()-1;

        while (l <= r) {
            int m = l + (r - l) / 2;
            std::cout << "l,m, r: " << l << " " << m << " " << r << std::endl;
            if (nums.at(m) == target)
                return m;
 
            if(nums.at(l) <= nums.at(m)){
                if(target < nums.at(m) and target >= nums.at(l)){
                    r = r-1;
                }else{
                    l = l+1;
                }

            }else{
                if(target <= nums.at(r) and nums.at(m) <= target){
                    l = m+1;
                }else{
                    r = m-1;
                }
            }
        }
 
        return -1;
    }
};
