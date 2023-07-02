class Solution {
public:
    string convert(string s, int numRows) {
        string sol;
        vector<string> rows(numRows, "");
        if(numRows == 1){
            return s;
        }
        int k  =0;
        bool inc = true; 
        for(int i =0; i < s.size(); i++){
            rows.at(k) += s.at(i);
            if(inc){
                k++;
            }else{
                k--;
            }
            if(k == numRows-1){
                inc = false;
            }else if(k ==0){
                inc = true;
            }

            
        }
        for(int j = 0; j < rows.size(); j++){
            std::cout << rows.at(j) << std::endl;
            sol += rows.at(j);
        }
        return sol;
    }
};
