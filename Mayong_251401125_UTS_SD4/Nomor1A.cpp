#include <iostream>
using namespace std;

int main() {
   int nilai [5][4] = 
   {
      {50, 80, 70, 85},
      {60, 90, 75, 95},
      {70, 85, 80, 90},
      {20, 50, 45, 90}

   };
   
   for (int i = 0; i < 5; i++) 
   {
       for (int j = 0; j < 4; j++) 
       {
           cout << nilai[i][j] << " ";
       }
       cout << endl;
   }

   return 0;
}