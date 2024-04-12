class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        // finding previous greatest element
        vector<int> arr(n);
        int max1 = -1;
        for(int i=0;i<n;i++){
            arr[i]=max1;
            if(max1<height[i]) max1=height[i];
        }

        // finding next greatest element
        vector<int> brr(n);
        int max2 = -1;
        for (int j=n-1;j>=0;j--){
            brr[j]=max2;
            if(max2<height[j]) max2=height[j];
        }

        // water+=min(arr[i],brr[i])-height[i]. if positive
        int num=0;
        for(int i=1;i<n-1;i++){
            num=min(arr[i],brr[i]) - height[i];
            if(num>0){
                water+=num;
            }
        }

        return water;

    }
};
