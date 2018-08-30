#include <stdio.h>
#include <conio.h>
#include <string.h>

char numbers[11][11] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
char teen[11][11] = {"","eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen","eighteen", "nineteen"};
char tens[11][11] = {"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int func(int n){
    if (n<11) {
        printf("%s", numbers[n]);
        return 1;
    }
    else if(n<20) {
        printf("%s",teen[n%10]);
        return 1;
    }
    else if(n%10 == 0 && n<100) {
        printf("%s",tens[n/10]);
        return 1;
    }
    else if(n<100) {
        printf("%s %s",tens[n/10], numbers[n%10]);
        return 1;
    }
    else if(n%100==0 && n<1000) {
        printf("%s hundred ",numbers[n/100]);//%10
        return 1;
    }
    return 0;
}

int func2(int n) {
        if(n>100 && n<1000){
            if((n-((n/100)*100))%100 == 0)
                printf("%s hundred ", numbers[n/100]);
            else
                printf("%s hundred and ", numbers[n/100]);
            printf(func(n-(n/100)*100));
            return 1;
            }
        else
            func(n);
        return 0;
}

int main() {
    int n;
    scanf("%d", &n);
     if(!func(n)) {
        if(!func2(n)) {
                if (n%1000 == 0) {
                    func(n/1000);
                    printf(" thousand");
                }
                else if(n<70000) {
                    func(n/1000);
                    if((n-(n/1000)*1000)>=100)
                        printf(" thousand ");
                    else
                        printf(" thousand and ");
                    func2(n-(n/1000)*1000);
                }
        }
    }

}
