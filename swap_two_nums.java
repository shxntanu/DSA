public class swap_two_nums {
    public static void swap_numbers(int a, int b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}
