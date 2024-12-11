class Solution {
public:
    int findComplement(int num) {
        int i;
        for (i=0;i<32;i++){
            if(num&(1<<(31-i))){
                break;
            }
        }
        for (i;i<32;i++){
            num=num^(1<<(31-i));
        }
        return num;
    }
};
