#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch, name[10];
    int i;
    for(i=0;i<10;i++){
         ch = getche();
            if  (ch == 0x0d){
                name[i] = '\0';
                break;
            }
        name[i]=ch;
    }
printf("\n");

for(i = 0;i<10;i++){
        printf("%c",name[i]);
if  (name[i] == '\0')
                break;

}
    return 0;
}
