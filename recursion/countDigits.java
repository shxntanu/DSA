package recursion;

public class countDigits {
    public static int helper( int n , int count ){
        if( n == 0 ){
            return count;
        }
        return helper(n/10, count + 1);
    }
    // complete the below function
    public static int countDigits1(int n)
    {
        return helper(n , 0);
        
    }
}
