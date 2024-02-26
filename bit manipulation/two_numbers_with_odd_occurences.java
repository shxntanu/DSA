public class two_numbers_with_odd_occurences {
    public static int[] twoOddNum(int[] arr) {
        int[] ans = new int[2];
             int x=0,n=arr.length;
            for(int i=0;i<n;i++){
                x^=arr[i];
            }
            int p=0;
            while((x&1)==0){
                p++;
                x=x>>1;
            }
            int a=0,b=0;
            for(int i=0;i<n;i++){
                if(((arr[i]>>p)&1)== 1){
         
                    a=a^arr[i];
                }
                else {
                    b=b^arr[i];
                }
            }
            if(a<b) {
                ans[0] = b;
                ans[1] = a;
                return ans;
            }
            else{
                ans[0] = a;
                ans[1] = b;
                return ans;
            }
         }
}
