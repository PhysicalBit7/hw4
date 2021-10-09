// ***** main.cpp *****

#include "master.h"


int main (void)
{
   srand(time(0));
   int inputs[] = {5,7,8,10,12,17,19,22,28,31,33,35,42,51,59};
   //int inputs[] = {5, 7, 8, 10};
   SkipList list1;
   Node* node;
     
   for (int i=0; i<sizeof(inputs)/sizeof(inputs[0]); i++) {
      node = new Node(inputs[i]);  

      //cout << *node << endl;
      //delete node;

      list1.add(node);
      cout << "list1:\n"<< list1 << endl;
   }
   bool found;
   if(list1.find(33)){
      cout << "33 found\n";
   }else{
      cout << "33 not found\n";
   }
   if(list1.find(70)){
      cout << "70 found\n";
   }else{
      cout << "70 not found\n";
   }
   if(list1.find(10)){
      cout << "10 found\n";
   }else{
      cout << "10 not found\n\n\n";
   }

   if(list1.erase(59)){
      cout << "list1 after deletion of 59(eol):\n"<< list1 << endl;
   }else{
      cout << "Value not in list\n";
   }
   if(list1.erase(10)){
      cout << "List1 after deletion of 10 middle:\n" << list1 << endl;
   }else{
      cout << "Value not in list\n";
   }
   if(list1.erase(5)){
      cout << "list1 after deletion of 5(from front):\n"<< list1 << endl;
   }else{
      cout << "Value not in list\n";
   }
   if(list1.erase(22)){
      cout << "list1 after deletion of 22:\n"<< list1 << endl;
   }else{
      cout << "Value not in list\n";
   }
   if(list1.erase(70)){
      cout << "List after erasing number not in: " << list1 << endl;
   }else{
      cout << "Value not in list\n";
   }
   

   return 0;
}
