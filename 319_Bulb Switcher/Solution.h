#At first I used an array to store the values of each bulb, TLE in the 33/35 case.
#I was keep thinking how to use Bit operation to solve this pro.
#While the fact is, for every bulb, the operation each time is !.
#Which is not an efficient operation if you want to do it with bit.
#After read the discussion, I still realize that you need to think this pro in math.
#Think more about characteristics of the probolem. Which is very important.
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
