#include <iostream>
#include <string>

#define MAX_COUNT 15
using namespace std;

// Program to find unique value in an array with all pairs except 1 value.
// This solution assumes the array doesn't have 0. If so, we are screwed
// If array has 0, use hash map solution. Keep adding and removing elements from array 
// into hash map as u see them
// Finally only unique would be left in the hashmap.
// This version of solution is simple and has no space complexity as hashmap.
// See these :
// http://www.programcreek.com/2012/12/leetcode-solution-of-single-number-in-java/
// http://www.programcreek.com/2014/03/leetcode-single-number-ii-java/
int main()
{
    int my_array[MAX_COUNT];
    int i,max,unique;

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

    //XOR all the numbers and we are left with the unique number
    unique = 0;
    for (i = 0; i < max; i++)
    {
        unique = unique ^ my_array[i];
    }
    
    //print the unique
    if (unique) {
        cout<<"unique: "<<unique<<endl;
    } else {
        cout<<"array has no unique values"<<endl;
    }
    return 0;
}
