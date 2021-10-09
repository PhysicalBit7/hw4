// ***** SkipListAdd.cpp *****

#include "master.h"

// add node to the list with info in ascending order  
bool SkipList::add(Node* newNode)
{
   if (newNode == nullptr) 
      return false;  

   if(nLevelsUsed < newNode->numOfNextPtrs){  // in order to keep track of how many levels are in head
      nLevelsUsed = newNode->numOfNextPtrs;
   }

   Node* previous = nullptr;
   for(int i = nLevelsUsed - 1; i >= 0; i-- ){  // i == nLevelsUsed
      
      previous = addNext(newNode, previous, i);

   }
   return true;
}

// a helper function to add to a particular level, currLevel.
// not required
Node* SkipList::addNext(Node* newNode, Node* prev, int currLevel)  // currLevel == i
{
 
   if(head[currLevel] == nullptr){  // if the list is empty add new node
      head[currLevel] = newNode;
   }else{  // there are many items in the list
      Node* current = head[currLevel];
      if(prev != nullptr){  // used to not start at head, start from last place we visit
         current = prev->next[currLevel];
      }
      while(current != nullptr && current->info < newNode->info){
         prev = current;
         current = current->next[currLevel];
      }
      if(prev == nullptr){ // if we need to add at the front of list with multiple nodes
         newNode->next[currLevel] = current;
         head[currLevel] = newNode;
      }else{  // most common case
         if(newNode->numOfNextPtrs > currLevel){  // in order to not point previous to newNode is newNode does not have a pointer at that level
            prev->next[currLevel] = newNode;
            newNode->next[currLevel] = current;
         }
      }
   }
   return prev;
}

bool SkipList::find(int el) const {  // not using binary search, fix using two pointers
   bool found = false;
   Node* previous = nullptr;
   Node* current;
   for(int i = nLevelsUsed - 1; i >= 0; i--){
      if(previous != nullptr){
         current = previous->next[i];
      }else{
         current = head[i];
      }
      while(current != nullptr && !found){
         if(current->info == el){
            found = true;
         }else if (current->info < el){  // we need to look higher
            previous = current;
            current = current->next[i];
         }else{
            current = current->next[i];
         }
      }
   }
   return found;
}

