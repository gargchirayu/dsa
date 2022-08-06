class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //
        //for T test cases (=total/timeToDie) there are T+1 cases for pig
        //dies on 1st, 2nd, ... Tth, or doesnt die
        //now we need to figure out which pig gets which bucket and in what order
        //so we can know poisonous bucket, we assign bucket based on its index
        //after conversion to new numeric system, then 
        //for N=1000, die=15, total=60, say 1(0) 3(0) 4(1) pigs die and 0,2(3) survive
        //then, poisonous bucket is: 729 (10404)
        //means: case 0: pig 1 and 3 (died), 1: 4 (died), 2: no pigs, 3: 0 and 2 (lived)
        //              | pig num
        // test num      | 4 3 2 1 0
        // --------------------------
        //       0       | - X - X -       
        //       1       | X - - - - 
        //       2       | - - - - -
        //       3       | - - X - X
        //base of this custom system is ans, calc using formula:
        //
        
        return ceil(log(buckets)/log(minutesToTest/minutesToDie + 1));
    }
};