class Solution {
public:
    int min_height(int a, int b){
        if( a <= b){
            return a;
        }
        return b;
    }
    int maxArea(vector<int>& height) {
        int min = 0;
        int i  = 0;
        int j = height.size() -1;
        while (i <= j){
            int h = min_height(height.at(i), height.at(j));
            int area = h*(j -i);
            if(area > min){
                min = area;
            }
            if(height.at(i) <= height.at(j)){
                i++;
            }else {
                j--;
            }
        }
        return min;
    }

};
