/// file: O4.cpp
///
/// solution for exercise comparing references and pointers
///
/// see also:
/// http://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
///
/// ---
/// Prof. Dr. J�rgen Brauer, www.juergenbrauer.org
///

#include <stdio.h>  // for printf()
#include <conio.h>  // for getch()

class A
{
   public:
      A(int value)
      {
         this->value = value;
      }

      int get_value()
      {
         return value;
      }

      void set_value(int value)
      {
         this->value = value;
      }

   private:
      int value;
};

int main()
{
   // 1. pointers and references can be used to point to
   //    variables
   int i=42;
   int* pi = &i;
   int& ri = i;
   i = 43;
   printf("value of i according to pointer   : %d\n", *pi);
   printf("value of i according to reference : %d\n", ri);
   printf("\n");

   // 2. pointers and references can be used to point to
   //    objects
   A O1(17);
   A* pobj = &O1;
   A& robj = O1;
   printf("value of O1 according to pointer   : %d\n", pobj->get_value());
   printf("value of O1 according to reference : %d\n", robj.get_value());
   printf("\n");


   // 3. pointers can be reassigned to another variable/object
   //    but references not!
   A O2(101);
   pobj = &O2; // reassign pointer <pobj> to new object <O2>
   robj = O2;  // reassign reference <robj> to new object <O2> ???
   printf("value of O2 according to pointer   : %d\n", pobj->get_value());
   printf("value of O2 according to reference : %d\n", robj.get_value());
   printf("\n");

   O2.set_value(202);
   printf("value of O2 according to pointer   : %d\n", pobj->get_value());
   // we will not see 202 outputted by the following line,
   // because above we did not reassign the reference, but copied to value
   // of O2 to obj!
   printf("value of O2 according to reference : %d\n", robj.get_value());
   printf("value of O1 according to reference : %d\n", O1.get_value());
   printf("\n");


   // 4. with pointers we can do "pointer arithmetic"
   //    but there is no "reference arithmetic"
   int* SomeArray = new int[1000];
   SomeArray[0] = 21;
   SomeArray[5] = 422;

   int* ptr = SomeArray;
   ptr = ptr + 5;
   printf("ptr points to variable with value = %d\n", *ptr);
      
   int& ref = *SomeArray;
   ref = ref + 5;
   printf("ref references variable with value = %d\n", ref);
   printf("\n");


   // conclusion:
   // references are something like constant pointers which automatic
   // indirection, i.e. the compiler does the dereferencing * for us
   
   _getch();
}