#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    double e2,m2;
    int e_final,m_final;
    int i,j;
    double a;
    int b;
    int flag;
    char line[300];
    double E[11][33];
    double M[11][33];
    double sum,e,m;
    for(i=1;i<=10;i++){
        m=1-pow(2,-i);
        for(j=1;j<=30;j++){
            e=pow(2,j)-1;
            M[i][j]=log10(m)+e*log10(2);
        }
    }
    freopen("input.txt","r",stdin);
    while(fgets(line,300,stdin)){
        if(!strcmp(line,"0e0\n")){
            break;
        }
        line[17]=' ';
        sscanf(line,"%lf %d\n",&a,&b);
        sum = log10(a)+b;
        flag = 0;
        for(i=1;i<=10;i++){
            for(j=1;j<=30;j++){
                if(fabs(sum-M[i][j])<1e-4){
                    flag=1;
                    break;
                }
            }
            if(flag){
               break; 
            }
        }
        e_final = j;
        m_final = i-1;
        
        printf("%d %d\n",m_final,e_final);
    }
    return 0;
}
