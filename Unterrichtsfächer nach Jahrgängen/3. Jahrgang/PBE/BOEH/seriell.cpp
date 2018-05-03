#include <stdlib.h>
int main()
{
    system("mode com1:9600,n,8,1");
    while(42)
        system("echo Alexander Hofstaetter > COM1");
}
