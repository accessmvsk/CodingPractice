#include <iostream>
#include <string>
#define MAX_COUNT 15
using namespace std;

// Program to find unique value in an array with all elements THRICE except 1 value.
// This solution assumes '0' isn't a valid entry.
// http://www.programcreek.com/2014/03/leetcode-single-number-ii-java/
int main()
{
    int my_array[MAX_COUNT];
    int ones = 0, twos = 0, threes = 0, max, i;

    // read the max number of valid values in the array
    cout<<"Please enter the array size\n";
    cin>>max;
    if (max > MAX_COUNT)
    {
        cout<<"Please re-run with count less than 16 \n";
        return 1;
    }

    //read in the array
    cout<<"Please enter the array elements one by one\n"<<endl;
    for (i = 0; i < max; i++ )
    {
        cin>>my_array[i];
    }

    //Using bitwise, make sure we narrow down the element that appears once.
    for (i = 0; i < max; i++)
    {
        // Any element appread once already, and appeared again (& operation)
        twos |= ones & my_array[i];
        
        // Any elment that appeared only once (do XOR operation. This removes repeating values.
        ones ^= my_array[i];
        
        // Any element that appread once AND twice means it appeared thrice
        threes = ones & twos;
        
        // Remove the element that appeared thrice from ones and twos
        ones &= ~threes;
        twos &= ~threes;
    }
    
   cout <<"The element appearing only once is: "<<ones<<endl;
}
