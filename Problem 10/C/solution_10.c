#include<stdio.h>

void targetFun()
{
    printf("\n Inside target function...!");
}

void scheduler(int n, void (*targetFun)())
{
    sleep(n/1000);
    targetFun();
}

int main(){

    int n;

    printf("\n Enter time in milliseconds : ");
    scanf("%d", &n);

    scheduler(n, &targetFun);
}