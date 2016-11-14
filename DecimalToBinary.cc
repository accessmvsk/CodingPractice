#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

// Program to convert decimal to binary and again binary to decimal
// XXX what if number is signed ?
int main()
{
    std::string inputNumber;
    std::cout<<"please enter the input number "<<std::endl;
    std::cin>>inputNumber;
    int decimal = 0;
    int length = inputNumber.size();
    for (int i = 0; i < length; i++)
    {
        if (inputNumber.c_str()[i] == '1') {
            decimal += pow(2,(length -1 -i));
        }
    }
    std::cout<<"decimal value: "<<decimal<<std::endl;
    char binary[33];
    memset(binary, '0', 33);
    binary[32] = '\0';
    for (int i = 0; decimal > 0 ; i++)
    {
        // get the right most bit
        int rightMostBit = decimal & 1;
        
        // set the corresponding bit in binary string
        if (rightMostBit == 1) {
            binary[(31-i)] = '1';
        } else {
            binary[(31-i)] = '0';
        }
        
        // knock off the right most bit.
        decimal = decimal >> 1;
        
    }
    // print in human readable form
    std::string binaryString(binary);
    std::cout<<"binary: "<<binaryString<<std::endl;
    return 0;
}
