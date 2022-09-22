#include <iostream>
#include <string>

std::string global_str;
int global_int;
int main()
{
 int local_int; std::string local_str;

 std::cout << (local_int) << " " << local_str <<std::endl;
}