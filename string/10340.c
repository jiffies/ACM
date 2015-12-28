#include <stdio.h>
#include <string.h>

int main(){
    char sub[100005];
    char all[100005];
    int i,j;
    int len_sub,len_all;
    freopen("input.txt","r",stdin);
    while(scanf("%s %s",sub,all)!=EOF){
       len_sub = strlen(sub);
       len_all = strlen(all);
       i=0;
       j=0;
       while(sub[i]!='\0' && all[j]!='\0'){
           if(sub[i]==all[j]){
               i++;
               j++;
           }
           else{
               j++;
           }
       }
       if(i==len_sub){
            printf("Yes\n");
       }
       else{
            printf("No\n");
       }

    }
    return 0;
}
