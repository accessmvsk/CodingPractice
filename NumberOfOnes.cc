#include <iostream>

// Program to count the number of 1's in a given number. 1001 -> 2
// Program to calculate the max binary gap in a given number. 1001 has a gap of 2. 10001 has a gap 3. 
// The gap between two 1's.
// http://www.programcreek.com/2013/02/twitter-codility-problem-max-binary-gap/
// http://www.programcreek.com/2014/03/leetcode-number-of-1-bits-java/
int main()
{
    int number=0, curBinaryGap=0, maxBinaryGap=0, numberOfOnes=0, rightMostDigit=0;
    std::cout<<"please enter the input number "<<std::endl;
    std::cin>>number;
    // Handle negative number
    if (number < 0) {
        number *= -1;
    }
    
    while (number > 0)
    {
        // get right most digit
        rightMostDigit = (number & 1);
        // move the number to right
        number = number >> 1;

        // if rightMostDigit is 1, then:
        // increase number of ones
        // we also have reached end of current binary gap 
        // update max binary gap if needed and
        // make current binary gap 0 as we reached the end of current gap
        if (rightMostDigit == 1) {
            numberOfOnes++;
            maxBinaryGap = (curBinaryGap > maxBinaryGap) ? curBinaryGap : maxBinaryGap;
            curBinaryGap = 0;
        } else {
            curBinaryGap++;
        }
    }
    std::cout<<"max binary gap: "<<maxBinaryGap<<std::endl;
    std::cout<<"total number of 1's: "<<numberOfOnes<<std::endl;
}
