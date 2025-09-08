string toBinary(int num){
    if(num == 0) return "0";

    string res = "";
    
    while(num > 0){
        if(num % 2 == 1){
            res += "1";
        }else{
            res += "0";
        }
        num = num / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}


class Solution {
public:
    string convertDateToBinary(string date) {
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);

        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        return toBinary(y) + '-' + toBinary(m) + '-' + toBinary(d);
    }
};