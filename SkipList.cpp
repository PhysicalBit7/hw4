// ***** SkipList.cpp *****

#include "master.h"

SkipList::SkipList (void)
{
   MaxNumberOfLists = 100;
   for (int i=0; i < MaxNumberOfLists; i++) {
      head[i] = nullptr;
   }
   nLevelsUsed = 0; 

}

SkipList::~SkipList (void)
{
   erase ();

   return;
}

void SkipList::erase (void)
{
   cout << "SkipList::erase\n";

   Node* tmp = head[0];  //use the layer-0 to remove nodes
   while (tmp)
   {
      Node* nextHead = tmp->next[0];
      delete tmp;
      tmp = nextHead;
   }

   // reset
   // clear the head[] 
   for (int i=0; i< nLevelsUsed; i++) {  
      head[i] = nullptr;
   }

   nLevelsUsed=0;

   return;
}


// To remove the node with given value from the list
// input: int el 
// output: bool to indicate el deleted or not (not exist)

bool SkipList::erase (int el){  //change to return bool
   Node* previous = nullptr;
   Node* current = nullptr;
   bool foundForDeletion;
   for(int i = nLevelsUsed - 1; i >= 0; i--){
      foundForDeletion = false;
      if(previous != nullptr){
         current = previous->next[i];
      }else if(current == nullptr || current->info != el){ //in order to not change current if we are on it
         current = head[i];
      }

      while(current != nullptr && !foundForDeletion){ 
         if(current->info == el){
            foundForDeletion = true;
            if(previous == nullptr){
               if(head[i] == current){
                  head[i] = current->next[i];
               }else{
                  previous = head[i];
                  while(previous->next[i] != current){
                     previous = previous->next[i];
                  }
                  previous->next[i] = current->next[i];
               }
            }else{
               /*while(previous->next[i] != current){
                  previous = previous->next[i];
               }*/
               previous->next[i] = current->next[i];
            }
         }else if (current->info < el){  // we need to look higher
            previous = current;
            current = current->next[i];
         }else{
            break;
         }
      }
   }
   
   for(int i = nLevelsUsed - 1; i >= 0; i--){
      if(head[i] == nullptr){
         nLevelsUsed--;
      }
   }
   delete current;
   return foundForDeletion;
}


void SkipList::write (ostream& outfile) const
{

   Node* current = head[0];
   outfile << "current # of levels is " << nLevelsUsed << endl;
   while (current != nullptr)
   {
      outfile << *current << endl;
      current = current->next[0];
   }

   return;
}   

ostream& operator << (ostream& outfile, const SkipList& list)
{
   list.write (outfile);

   return outfile;
}

