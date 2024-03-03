int buyChoco(int* prices, int pricesSize, int money){
    int min1= 101, min2 = 101; int minIndex;
    for(int i=0;i<pricesSize;i++) {
        if(prices[i] < min1) {min1 = prices[i]; minIndex = i;}
    }
    for(int i=0; i<pricesSize; i++) {
        if(prices[i] < min2 && i != minIndex) min2 = prices[i];
    }
    if((min1 + min2) > money) return money;
    return money - min1 - min2;
}
