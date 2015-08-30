#include <iostream>
#include <fstream>


int main(int argc, char* argv[])
{
   std::cout << "Teperature!!!\n\n";

   std::ifstream tempFile("/sys/devices/w1_bus_master1/28-00000625313b/w1_slave");

   if( !tempFile.is_open())
   {
      std::cout << "Cannot open file!!!\n";
      return 0;
   }

   std::string temp;
   std::string result;
   while(getline(tempFile, temp))
   {
      std::cout << "Temp: " << temp << std::endl;
      getline(tempFile, temp);
      std::cout << "Temp: " << temp << std::endl;
      result = temp.substr(temp.find_last_of("=") + 1);
      std::cout << "Temp: " << result << std::endl;
   }
   tempFile.close();

   return 0;
}
