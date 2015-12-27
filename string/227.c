#include <stdio.h>
#include <string.h>


void swap(char *a,char *b){
    char tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void findblank(char matrix[][7],int *x,int *y){
    int i,j;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(matrix[i][j]==' '){
                *x = i;
                *y = j;
                break;
            }
        }
    }
    
}

int test(x,y){
    if(x<0 || x>4 || y<0 || y>4){
        return -1;
    }
    else{
        return 1;
    }
}

int move(char matrix[][7],int *x,int *y,char next){
    int srX = *x;
    int srY = *y;
    switch(next){
        case 'A':
            *x = *x - 1;
            break;
        case 'B':
            *x = *x + 1;
            break;
        case 'L':
            *y = *y - 1;
            break;
        case 'R':
            *y = *y + 1;
            break;
        default:
            return 1;
            break;
    }
    if(test(*x,*y)<0){
        return 1;
    }
    swap(&matrix[srX][srY],&matrix[*x][*y]);
    return 0;
}

int main(){
    char line[7];
    char matrix[5][7];
    char ins;
    int i,j;
    int x,y;
    int num=0;
    int isError=0;
    int ret;
    freopen("input.txt","r",stdin);
    fgets(matrix[0],10,stdin);
    while(matrix[0][0]!='Z'){
        isError = 0;
        num+=1;
       /*memcpy(matrix[0],line,5);*/
       for(i=1;i<5;i++){
           fgets(matrix[i],10,stdin);
       }
       findblank(matrix,&x,&y);
       /*printf("x=%d,y=%d\n",x,y);*/
       while((ins=getchar())!='0'){
           if(ins=='\n'){
            continue;
           }
           ret=move(matrix,&x,&y,ins);
           if(ret>0){
            isError=1;
           }
       }
       getchar();
            if(num!=1){
               printf("\n");
            }
           printf("Puzzle #%d:\n",num);
           if(isError>0){
               printf("This puzzle has no final configuration.\n");
           }
           else{
               for(i=0;i<5;i++){
                for(j=0;j<5;j++){
                    printf("%c",matrix[i][j]);
                    if(j==4){
                        printf("\n");
                    }
                    else{
                        printf(" ");
                    }
                }
               }
           }
        fgets(matrix[0],10,stdin);
    }
    return 0;
}
