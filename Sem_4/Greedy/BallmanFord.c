#include <complex.h>
#include <limits.h>
#include <stdio.h>
int path[7]={1,1,1,1,1,1,1};
int cost[7][7] = {{0, 6, 5, 5, INT_MAX, INT_MAX, INT_MAX},
                  {INT_MAX, 0, 3, INT_MAX, -1, 2, 3},
                  {INT_MAX, -2, 0, INT_MAX, 1, INT_MAX, INT_MAX},
                  {-2,3,-2,0,INT_MAX,-1,INT_MAX},
                  {1,2,INT_MAX,INT_MAX,0,5,3},
                  {4,1,INT_MAX,INT_MAX,INT_MAX,0,3},
                  {-2,-1,3,INT_MAX,INT_MAX,-2,0}
                };
                void display(int Array[7][7]) {
                    for (int i = 0; i < 7; i++) {
                        for (int j = 0; j < 7; j++) {
                            if (Array[i][j] != INT_MAX)
                                printf(" %3d  ", Array[i][j]);
                            else
                                printf("   ∞  ");
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
                void displayLine(int dist[7]){
                    for (int i=0; i<7; i++  ) {
                        if(dist[i]!=INT_MAX)
                            printf("%2d ",dist[i]);
                        else
                        printf(" ∞ ");
                    }
                    printf("\n");
                }
void bell_man(int dist[7], int cost[7][7], int v, int n) {
    for (int i = 0; i < n; i++) {
        dist[i] = cost[0][i];
    }
    dist[v] = 0;
    displayLine(dist);
    int temp[7];
    for (int k = 1; k < n; k++) {
        for (int u = 0; u < n; u++) {
            temp[u] = dist[u];
        }
        for (int u = 0; u < n; u++) {
            for (int i = 0; i < n; i++) {
                if (temp[i] != INT_MAX && cost[i][u] != INT_MAX && temp[i] + cost[i][u] < dist[u]) {
                    dist[u] = temp[i] + cost[i][u];
                    path[u]=i+1;
                }
            }
        }
        displayLine(dist);
    }
}
void displayPath(int cost[7][7],int dist[7],int v){
    printf("Source      Destination     Length      Path\n");
    for(int i=1;i<7;i++){
        printf("%d            %d             %2d",v,i+1,dist[i]);
        int j = i;
        printf("           %d", v + 1);
        while (path[j] != v + 1) {
            printf(" -> %d", path[j]);
            j = path[j] - 1;
        }
        printf(" -> %d\n", i + 1);
    }
    
}
int main(){
    display(cost);
    int dist[7]={0,0,0,0,0,0,0};
    bell_man(dist, cost, 0, 7);
    displayPath(cost,dist,0);
    return 0;
}