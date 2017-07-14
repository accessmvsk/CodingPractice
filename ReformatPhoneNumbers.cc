// format phone number
// input values: ########## or ###-###-#### but we have area code and prefix reversed. 410-422-8081 is given as 422-410-8081
// expectation: swap the prefix and area code and put dashes if unavailable. 
#include <iostream>
#include <string>
using namespace std;
void ReformatPhoneNumbersWithDashes(string &phoneNumber)
{
    //swap values at index 0, 4
    swap(phoneNumber[0], phoneNumber[4]);
    //swap values at index 1, 5
    swap(phoneNumber[1], phoneNumber[5]);
    //swap values at index 2, 6
    swap(phoneNumber[2], phoneNumber[6]);
}

void ReformatPhoneNumbersWithoutDashes(string &phoneNumber)
{
    //Insert '-' at index 3
    //Example: 0123456789 becomes 012-3456789
    phoneNumber.insert(3, "-");
    //Insert '-' at index 7 (its 7 instead of as we added - just now)
    //Example: 012-345676789 becomes 012-345-6789
    phoneNumber.insert(7, "-");
    //call the function to format number with dashes
    ReformatPhoneNumbersWithDashes(phoneNumber);
}

void ReformatPhoneNumbers(string &phoneNumber)
{
    ReformatPhoneNumbersWithoutDashes(phoneNumber);
}

void ValidatePhoneNumber(string &phoneNumber)
{
    int length = 0;
    bool withDashes = false;
    for (; phoneNumber[length] != '\0'; length ++)
    {
        // its OK to have a '-' in 3rd position
        if (length == 3 && phoneNumber[length] == '-') {
            withDashes = true;
            continue;
        }
        // if we have a '-' in 3rd position, we must have a '-' 6th position
        if (length == 6 && withDashes && phoneNumber[length] != '-') {
            throw new string("ERROR: invalid phone number format. A - missing after prefix");
        }
        if (phoneNumber[length] > '9' || phoneNumber[length] < '0') {
            throw new string("ERROR: invalid digits in phone number");
        }
    }
    if (length != 10 || length != 12) {
        throw new string("ERROR: invalid phone number length");
    }
}

int main()
{
  std::string phoneNumber;
  std::cout << "What is the phone number? ";
  getline (std::cin, phoneNumber);
  //validate the number
  try {
    ValidatePhoneNumber(phoneNumber);
  }
  catch (string *errorString){
      cout<<*errorString<<endl;
      return 1;
  }
  //call ReformatPhoneNumbersWithoutDashes
  ReformatPhoneNumbers(phoneNumber);
  std::cout << "your phone number in formatted form:" << phoneNumber << "\n";
  return 0;
}
