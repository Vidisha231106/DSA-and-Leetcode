//3100

/*So the rule is basically:

- Choose to drink (convert all full → empty).
- Or choose to exchange (but only once for the current numExchange value).
- After an exchange, numExchange increases by 1.

You cannot drink the newly gained bottle before completing all possible exchanges for the new numExchange cost, because every time you exchange, 
the requirement (numExchange) immediately increases, even before you drink again.

*/

int maxBottlesDrunk(int numBottles, int numExchange) {
    int total_bottles_drunk=numBottles;
    int empty=numBottles;

    while (empty>=numExchange){
        empty -=numExchange;
        empty++;
        total_bottles_drunk++;
        numExchange++;
    }
    return total_bottles_drunk;
}
