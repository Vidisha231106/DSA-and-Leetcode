//1518
/*
numWaterBottles(15, 4)
 ├─ full = 15 / 4 = 3
 ├─ empty = 15 % 4 = 3
 ├─ totalDrankAtThisStep = 3 * 4 = 12
 └─ next call: numWaterBottles(full + empty = 6, 4)
       ├─ full = 6 / 4 = 1
       ├─ empty = 6 % 4 = 2
       ├─ totalDrankAtThisStep = 1 * 4 = 4
       └─ next call: numWaterBottles(full + empty = 3, 4)
             ├─ numBottles = 3 < 4 → base case
             └─ return 3

*/

int numWaterBottles(int numBottles, int numExchange) {
    if (numBottles < numExchange) {
        return numBottles; // drink remaining bottles
    }
    int full = numBottles / numExchange;   // full bottles we get by exchanging
    int empty = numBottles % numExchange; // leftover empty bottles
    int totalDrankAtThisStep = full * numExchange; // original bottles we drank to get these empty bottles
    return totalDrankAtThisStep + numWaterBottles(full + empty, numExchange);
}
