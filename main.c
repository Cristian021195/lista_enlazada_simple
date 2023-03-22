#include <stdio.h>
void aumentarRef(int * val);

int main(){
    int val = 0;
    aumentarRef(&val);
    printf("Holi, el valor es: %d\n", val);

    return 0;
}

void aumentarRef(int * val){
    *val = *val + 1;
}