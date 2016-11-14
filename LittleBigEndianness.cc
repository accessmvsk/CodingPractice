#include <iostream>
// Program to print endianness of the platform 
using namespace std;
int is_big_endian()
{
    union {
        uint32_t i;
        char c[sizeof(int)];
    } u = {0x010000000};
    return u.c[0];
}

int main()
{
    unsigned int i = 1;
    char *p;
    p = (char *)&i;
    if (*p == 1) {
        std::cout<<"little endian"<< std::endl;
    } else {
        std::cout<<"big endian"<< std::endl;
    }
    if (is_big_endian()) {
        std::cout<<"big endian"<< std::endl;
    } else {
        std::cout<<"little endian"<< std::endl;
    }
    
    return 0;
}
