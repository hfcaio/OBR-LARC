#include<iostream>

const int l = 10;
const int p = 10;

int inf = 100;

/*

	1 1 1 1 1 1 1 1 1 1 
	1 0 0 0 0 0 1 0 0 1
	1 1 0 1 0 0 0 0 1 1
	1 0 0 0 0 0 0 0 0 1 
	1 0 1 0 0 0 0 0 0 1
	1 0 1 1 0 0 0 0 0 1
	1 0 0 0 0 0 1 0 0 1
	1 0 0 0 0 0 1 1 0 1
	1 0 0 0 0 0 0 0 0 1
	1 1 1 1 1 1 1 1 1 1
	 
*/

struct ponto {
  int x, y;
};

int maze[l][p];
bool visitado[l][p];
int dist[l][p];

void dfs(ponto atual) {
 	 printf("DFS %d %d\n", atual.x, atual.y);

  int c = atual.x;
  int r = atual.y;

  ponto prox;
  if (visitado[c + 1][r] == 0 && dist[c][r] + 1 < dist[c + 1][r] ) {
    dist[c + 1][r] = dist[c][r] + 1;
    prox.x = c + 1;
    prox.y = r;
    dfs(prox);
  }
  if (visitado[c - 1][r] == 0 && dist[c][r] + 1 < dist[c - 1][r] ) {
    dist[c - 1][r] = dist[c][r] + 1;
    prox.x = c - 1;
    prox.y = r;
    dfs(prox);
  }
  if (visitado[c][r - 1] == 0 && dist[c][r] + 1 < dist[c][r - 1] ) {
    dist[c][r - 1] = dist[c][r] + 1;
    prox.x = c;
    prox.y = r - 1;
    dfs(prox);
  }
  if (visitado[c][r + 1] == 0 && dist[c][r] + 1 < dist[c][r + 1] ) {
    dist[c][r + 1] = dist[c][r] + 1;
    prox.x = c;
    prox.y = r + 1;
    dfs(prox);
  }

}

int main() {
	printf("digite sua matriz:\n");
	for (int i=0   ;i < l; i++){
		for(int j=0;j < p; j++){
			scanf("%d",&maze[i][j]);
			dist[i][j]=inf;
			if(maze[i][j]!=1){
				visitado[i][j]=0;
			}
			else{
				visitado[i][j]=1;
			}
		}
	}
	
	ponto inicial;
	inicial.x=1;
	inicial.y=1;
	dist[inicial.x][inicial.y]=0;
	dfs(inicial);
	
	for (int i = 0 ; i < l; i++){
		for(int j = 0; j < p; j++){
			if(maze[i][j]==1) {
				printf("- ");
			}
			else if(dist[i][j]==inf){
				printf("x ");
			}
			else {
				printf("%d ",dist[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}