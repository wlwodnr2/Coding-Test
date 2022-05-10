#define MAX 100000
#define MIN(a,b) a < b ? a : b
#define INF 987654321

int V, E;
int adj[MAX][MAX];

void initAdj(){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			adj[i][j] = MAX;
			if(i == j) adj[i][j] = 0;
		}
	}
}

void floyd() {
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				adj[i][j] = MIN(adj[i][j] , adj[i][k] + adj[k][j]);
			}
		}
	}
}
