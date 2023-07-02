class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero =0; 
       int one = 0;
       int two = 0;
       int size = 0;
       vector<int> temp;
       for(int k =0; k < nums.size(); k++){
           
            if(nums.at(k) == 0){
               temp.insert(temp.begin(), 0);
               zero++;
            }else if(nums.at(k) == 1){
                temp.insert(temp.begin() + zero, 1);
            }else{
                temp.push_back(2);
            }
       }
       nums = temp;
    }
};
