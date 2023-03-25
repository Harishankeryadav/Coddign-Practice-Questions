// word reverse.
// my name is harry --> ym eman si yrrah.
#include <iostream>
#include <cstring>
using namespace std;

void word_rev(char arr[], int len)
{
   cout << "strlen "<<len<<endl;
   int x = 0;
   for (int i = 0; arr[i] != '\0'; i++)
   {
      if (arr[i] == ' ' && arr[i + 1] != ' ' )
      {
         for (int j = i; j >= x; j--)
         {
            cout << arr[i];
         }
         cout <<" ";
         x = i;
      }
      // else
      //    for (int i = len - 1; arr[i] != ' '; i--)
      //    {
      //       cout << arr[i];
      //    }
      //    cout<<" ";
   }
}

int main()
{
   char arr[50];
   int len = 0;
   cout << "Enter the string ";
   cin.getline(arr, 50);
   len = strlen(arr);
   word_rev(arr, len);
   return 0;
}