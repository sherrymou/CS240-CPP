#include "Mou_Keni_Hello_Class.h"

using namespace std;


Hello_Class::Hello_Class(int i) {
         if (i == 0) {
            output_string = "Hello C++ Data Structures!";
         } else {
            output_string = "Hello Data Structures!";
         }
      }

void Hello_Class::print_hello(){
         cout << output_string << endl;
}
