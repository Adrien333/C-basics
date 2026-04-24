#include <stdio.h>

int main() {
    char x[] = "dlrow olleH";
    int i,j;
    char temporary;
    for(i=0, j=strlen(x)-1; i<j; i++, j--){
        temporary=x[i];
        x[i]=x[j];
        x[j]=temporary;
    }
    printf("%s\n", x);
}