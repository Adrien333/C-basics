#include <stdio.h>
#include <stdlib.h>

int x=5;

struct Demonstration{
   int (*value)(int a); 
   void (*reference)(int *a);
};

int by_value(int a){ a+= 5; a++; return a;}

void by_reference(int *a){*a+= 5; (*a)++;}

struct Demonstration *demonstration_new(){
   struct Demonstration *p = malloc(sizeof(*p));
   if(p==NULL) return NULL;
   p->value = &by_value ;
   p->reference = &by_reference;
   return p; 
}

int main() {
   struct Demonstration *pt = demonstration_new();
   if(pt == NULL) {
      printf("allocation failed\n");
      return 1;
   }
   int b = pt->value(x);
   printf("The copied variable on the stack is %d ...\n", b);
   printf("but x remains %d in the memory :(\n", x);
   pt->reference(&x);
   printf("Now x is %d\n", x);
   free(pt);
}