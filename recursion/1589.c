#include <stdio.h>
#include <string.h>

typedef struct{
    char type;
    char hasPiece;
    char check;
    int x;
    int y;
}Location;

char x_h[8]={2,2,1,1,-1,-1,-2,-2};
char y_h[8]={-1,1,-2,2,-2,2,-1,1};
char x_hhl[8]={1,1,0,0,0,0,-1,-1};
char y_hhl[8]={0,0,-1,1,-1,1,0,0};

char x_bg[4]={1,-1,0,0};
char y_bg[4]={0,0,1,-1};

int inBoard(int x,int y){
    if(x<1 || x>10 || y<1 || y>9){
        return 0;
    }
    else{
        return 1;
    }
}
int inCamp(int x,int y){
    if(x<1 || x>3 || y<4 || y>6){
        return 0;
    }
    else{
        return 1;
    }
}

void check(Location chessboard[][10],Location black_G,Location location){
    int i,j;
    int flag_g;
    int n_canon;
    switch(location.type){
        case 'G':
            flag_g = 0;
            for(i=black_G.x+1;i<location.x;i++){
                if(chessboard[i][location.y].hasPiece){
                    flag_g=1;
                    break;
                }
            }
            if(!flag_g){
                for(i=black_G.x;i<=3;i++){
                    chessboard[i][location.y].check=1;
                }

            }
            break;
        case 'R':
            for(i=location.x+1;i<=10;i++){
                chessboard[i][location.y].check=1;
                if(chessboard[i][location.y].hasPiece){
                    if(!(black_G.x==i && black_G.y==location.y)){
                        break;
                    }
                } 
            }
            for(i=location.x-1;i>=1;i--){
                    chessboard[i][location.y].check=1;
                if(chessboard[i][location.y].hasPiece){
                    if(!(black_G.x==i && black_G.y==location.y)){
                        break;
                    }
                } 
            }
            for(i=location.y+1;i<=9;i++){
                    chessboard[location.x][i].check=1;
                if(chessboard[location.x][i].hasPiece){
                    if(!(black_G.x==location.x && black_G.y==i)){
                        break;
                    }
                }
            }
            for(i=location.y-1;i>=1;i--){
                    chessboard[location.x][i].check=1;
                if(chessboard[location.x][i].hasPiece){
                    if(!(black_G.x==location.x && black_G.y==i)){
                        break;
                    }
                }
            }
            break;
        case 'H':
            for(i=0;i<8;i++){
                if(inBoard(location.x+x_hhl[i],location.y+y_hhl[i])){
                    if(chessboard[location.x+x_hhl[i]][location.y+y_hhl[i]].hasPiece){
                        continue;
                }
                else{
                    if(inBoard(location.x+x_h[i],location.y+y_h[i])){
                        chessboard[location.x+x_h[i]][location.y+y_h[i]].check=1;
                    }
                }
                
                }
            }
            break;
        case 'C':
            n_canon=0;
            for(i=location.x+1;i<=10;i++){
                    if(n_canon==1){
                        chessboard[i][location.y].check=1;
                    }
                if(chessboard[i][location.y].hasPiece){
                    if(!(black_G.x==i && black_G.y==location.y)){
                    n_canon+=1;
                    }
                    if(n_canon>1){
                    if(!(black_G.x==i && black_G.y==location.y)){
                        break;
                    }
                    }
                } 
            }
            n_canon=0;
            for(i=location.x-1;i>=1;i--){
                    if(n_canon==1){
                        chessboard[i][location.y].check=1;
                    }
                if(chessboard[i][location.y].hasPiece){
                    if(!(black_G.x==i && black_G.y==location.y)){
                    n_canon+=1;
                    }
                    if(n_canon>1){
                    if(!(black_G.x==i && black_G.y==location.y)){
                        break;
                    }
                    }
                } 
            }
            n_canon=0;
            for(i=location.y+1;i<=9;i++){
                    if(n_canon==1){
                        chessboard[location.x][i].check=1;
                    }
                if(chessboard[location.x][i].hasPiece){
                    if(!(black_G.x==location.x && black_G.y==i)){
                    n_canon+=1;
                    }
                    if(n_canon>1){
                    if(!(black_G.x==location.x && black_G.y==i)){
                        break;
                    }
                    }
                }
            }
            n_canon=0;
            for(i=location.y-1;i>=1;i--){
                    if(n_canon==1){
                    chessboard[location.x][i].check=1;
                    }
                if(chessboard[location.x][i].hasPiece){
                    if(!(black_G.x==location.x && black_G.y==i)){
                    n_canon+=1;
                    }
                    if(n_canon>1){
                    if(!(black_G.x==location.x && black_G.y==i)){
                        break;
                    }
                    }
                }
            }
            break;
        default:
            break;
    }
}

int canMove(Location chessboard[][10],Location black_G){
    int i;
    int flag=0;
    for(i=0;i<4;i++){
        if(inBoard(black_G.x+x_bg[i],black_G.y+y_bg[i]) && 
            inCamp(black_G.x+x_bg[i],black_G.y+y_bg[i])
                ){
            if(!chessboard[black_G.x+x_bg[i]][black_G.y+y_bg[i]].check){
                flag=1;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int n_red;
    int i;
    Location chessboard[11][10];
    Location black_G={'G',1};
    Location red[7];
    char blank[2];
    freopen("input.txt","r",stdin);
    while(scanf("%d %d %d\n",&n_red,&black_G.x,&black_G.y)){
        memset(chessboard,0,sizeof(chessboard));
        memset(red,0,sizeof(red));
        if(n_red==0){
            break;
        }
        chessboard[black_G.x][black_G.y]=black_G;
        for(i=0;i<n_red;i++){
            scanf("%c %d %d\n",&red[i].type,&red[i].x,&red[i].y);
            red[i].hasPiece=1;
            chessboard[red[i].x][red[i].y]=red[i];
        }
        for(i=0;i<n_red;i++){
            check(chessboard,black_G,red[i]);
        }
        if(canMove(chessboard,black_G)){
            printf("NO\n");
        }
        else{
            printf("YES\n");
        }
    }
    return 0;
}
