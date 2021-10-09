// ***** SkipList.h *****

class SkipList
{
public:       
   SkipList (void);

   ~SkipList (void);

   void erase(void);

   //return false if nullptr is given to add
   bool add (Node* newNode);

   //return fasle if not found
   bool find(int el) const;
   
   bool erase(int el);    

   /*
   bool  erase (int el);
   */
   void write (ostream& outfile) const;

private:
   int MaxNumberOfLists;
   Node* head[100];  // going to use 100 to get started and then possibly implement dynamic array
   int   nLevelsUsed;  //the current number of levels used

   Node* addNext(Node* newNode, Node* prev, int i);  //helper for add method, not necessary for the project
};

ostream& operator << (ostream& outfile, const SkipList& list);