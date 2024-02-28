package recursion;

// Question : https://www.geeksforgeeks.org/batch/dsa-4/track/DSASP-Recursion/problem/tower-of-hanoi-1587115621

public class tower_of_hanoi {

    private int tm = 0;

    public long toh(int N, int from, int to, int aux) {
        if (N == 1) {
            System.out.println("move disk " + N + " from rod " + from + " to rod " + to);
            tm++;
        } else {
            toh(N - 1, from, aux, to);
            System.out.println("move disk " + N + " from rod " + from + " to rod " + to);
            tm++;
            toh(N - 1, aux, to, from);
        }
        return tm;
    }
}
// Create a function towerOfHanoi where pass the N (current number of disk), from_rod, to_rod, aux_rod.
// Make a function call for N – 1 th disk.
// Then print the current the disk along with from_rod and to_rod
// Again make a function call for N – 1 th disk.
