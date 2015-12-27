#include <stdio.h>
#include <string.h>

int main(){
    int i,n,j;
    int score=0;
    int cur=0;
    char s[81];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        score= 0;
        cur=0;
        j = 0;
        while(s[j]!='\0'){
            if(s[j]=='O'){
                score+=++cur;
            }
            else{
                cur = 0;
            }
            j++;
        }
        printf("%d\n",score);
    }
    return 0;
}
