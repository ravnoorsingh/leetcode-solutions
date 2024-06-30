class Solution {
    bool isPerfectSquare(int num){
        int squareRoot = sqrt(num);
            if((squareRoot*squareRoot)==num){
                return true;
            }
            else return false;
    }
public:
    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        while(x<=y){
            if(isPerfectSquare(x) && isPerfectSquare(y)){
                return true;
                break;
            }
            else if(!isPerfectSquare(y)){
                y = (int)(sqrt(y))*(int)(sqrt(y));
                x = c - y;
            }
            else{ // x is not a perfect square
                x = (int)(sqrt(x)+1)*(int)(sqrt(x)+1);
                y = c -x;
            }
        }
        return false;
    }
};
