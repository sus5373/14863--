//useop song 14863
//no correct
#include <stdio.h>
#include <stdlib.h>

int inp[103][7],arr[103][5],chigu[103];
int main(){
    freopen("input4.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int n,k,i,j,ai,mg,yg;

    scanf("%d %d",&n,&k);
    // printf("%d\n",k);
    for(i=0;i<n;i++)
        for(j=1;j<=4;j++) scanf("%d",&inp[i][j]);

    for(i=n-1;i>=0;i--){
        if(inp[i][1]>inp[i][3]) chigu[i+1]=inp[i][3]+chigu[i+2];
        else chigu[i+1]=inp[i][1]+chigu[i+2];
        // printf("%d : %d\n",i+1,chigu[i+1]);
    }

    for(i=1;i<=n;i++){
        ai=i+1;
        if(inp[i][2]>inp[i][4]) mg=1; else mg=3;
        if(inp[i-1][2]>inp[i-1][4]) yg=1; else yg=3;
        if(arr[ai-2][1]+inp[i-1][yg]+inp[i][mg]<k&&k-chigu[i+1]>=arr[ai-2][1]+inp[i-1][yg]){
            // printf("g ok %d\n",i);
            arr[ai-1][1]=arr[ai-2][1]+inp[i-1][yg];
            arr[ai-1][2]=arr[ai-2][2]+inp[i-1][yg+1];
        }
        else if(arr[ai-2][1]+inp[i-1][yg]+inp[i][mg]==k&&i>=n-1&&k-chigu[i+1]>=arr[ai-2][1]+inp[i-1][yg]){
            arr[ai-1][1]=arr[ai-2][1]+inp[i-1][yg];
            arr[ai-1][2]=arr[ai-2][2]+inp[i-1][yg+1];
            // printf("g == %d\n",i);
        }
        else{
            if(inp[i-1][yg+1]+inp[i][abs(mg-4)+1]>=inp[i-1][abs(yg-4)+1]+inp[i][mg+1]&&arr[ai-2][1]+inp[i-1][yg]+inp[i][abs(mg-4)]<=k&&k-chigu[i+1]>=arr[ai-2][1]+inp[i-1][yg]){
                arr[ai-1][1]=arr[ai-2][1]+inp[i-1][yg];
                arr[ai-1][2]=arr[ai-2][2]+inp[i-1][yg+1];
                // printf("use pass %d\n",i);
            }
            else{
                // printf("ng nk %d\n",i);
                mg=abs(mg-4),yg=abs(yg-4);
                arr[ai-1][1]=arr[ai-2][1]+inp[i-1][yg];
                arr[ai-1][2]=arr[ai-2][2]+inp[i-1][yg+1];
            }
        } 
    }

    // for(i=0;i<=n;i++){
        // for(j=0;j<=4;j++) printf("%d ",arr[i][j]);
        // printf("\n");
    // }


    printf("%d\n",arr[n][2]);

    return 0;
}