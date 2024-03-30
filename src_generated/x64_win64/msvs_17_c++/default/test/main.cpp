#include <iostream>

#include "LibNum.h"

int main()
{
   std::cout << "Execution begins.\n";
   std::cout << "LnZbmBcardOZbaILbd(0) is : " << LnZbmBcardOZbaILbd(0) << "\n";
   std::cout << "LnZbmBcardOZbaILbd(0xFFFFFFFE) is : " << LnZbmBcardOZbaILbd(0xFFFFFFFE) << "\n";
   std::cout << "LnZbmBcardOZbaILbd(0x80000000) is : " << LnZbmBcardOZbaILbd(0x80000000) << "\n";
   std::cout << "LnGenCheckOBb8() is : " << (int)LnGenCheckOBb8() << "\n";

   return 0;
}