#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main (void){
    setlocale(LC_ALL,"");
    
    while(1){
        int num;
        scanf("%d",&num);
        printf("%lc\n",(wint_t) num);
    }
}
