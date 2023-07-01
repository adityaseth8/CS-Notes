class Solution {
public:
    int min_height(int a, int b){
        if( a <= b){
            return a;
        }
        return b;
    }
    //O(n) time complexity. Space complexity don't know wtf that is.
    int maxArea(vector<int>& height) {
        int min = 0;
        int i  = 0;
        int j = height.size() -1;
        // Create two pointers. Start and End. 
        while (i <= j){
            int h = min_height(height.at(i), height.at(j));
            int area = h*(j -i);
            if(area > min){
                min = area;
            }
            //Change the position of the pointer with the samller value.
            if(height.at(i) <= height.at(j)){
                i++;
            }else {
                j--;
            }
        }
        return min;
    }

};
