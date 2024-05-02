#include <stdio.h>

int main(void){
    unsigned char var, var1, var2, var3, var4;
    var = 0xD8;
    var1 = (var >> 6) & 0x03;
    printf("%x\n", var1);

    var2 = (var << 2);
    var2 = (var2 >> 6) & 0x03;
    printf("%x\n", var2);

    var3 = (var << 4);
    var3 = (var3 >> 6) & 0x03;
    printf("%x\n", var3);

    var4 = (var << 6);
    var4 = (var4 >> 6) & 0x03;
    printf("%x\n", var4);

    return 0;
}