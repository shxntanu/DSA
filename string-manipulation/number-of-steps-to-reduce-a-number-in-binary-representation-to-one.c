int numSteps(char* s) {
     int step = 0;
    int carry = 0;
    int n = strlen(s);

    for (int i = n - 1; i > 0; i--) {
        if (s[i] == '1' && carry == 0 || s[i] == '0' && carry == 1) {
        step++;
        carry = 1;
        } else if (s[i] == '1' && carry == 1) {
        carry = 1;
        }
        step++;
    }
    if (s[0] == '1' && carry == 1) {
        step++;
    }
    return step;
}
