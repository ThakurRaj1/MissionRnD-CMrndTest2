/*
Summer has started here at Mission RnD world ,and each City here is flourishing with Mangoes .
In MrnD world, Each city is connected to at max 2 more cities .
There is a MangoCollector named Bob ,who visits  cities and collects some mangoes on his way at each
city . At each city ,he can also loose some mangoes as some cities are filled with thiefs .

Each city is represented using a struct node which has 3 fields , data specifying the number of mangoes
lost or gained in that city ,and left and right will be pointing to either NULL or next City (node).

Once he goes from City 1 to City 2 ,He cant go back again .He stops travelling when there are no more
cities connected to current city .

He wants to collect K number of mangoes at the end . Can you help him to find the number of ways,he can
start at Start City (start) and reach end city where he finally has K mangoes .

At any point of time ,his net mangoes count can be negetive too ,like he currently has 5 mangoes,
and he travels to a city where he looses 10 mangoes ,Now he will have -5 mangoes .
K can be negetive too ,In this case Bob wants to be at loss at the end .
Bob wont stop travelling even if his current mangoes count has reached K mangoes ,but the current city
is still connected to more cities .

For 50% of Test cases ,You need to copy the shortest final path where he reached his Final Count K .[Bob cant
travel anymore ].If two paths have same minimum length "Copy whose product off all nums in path is small",
Each value in the path will be the Gain/Loss he faced during each city in the path .

Input :
A Node start(starting city), Integer K ,and a pointer to an array where you need to copy 
shortest path and Copy its length to shortestpathlen
[Memory is already allocated for both array and integer,Dont allocate it again,Just change the values]

Output :
Return the number of ways in which he can start from Startcity and end his travel with K nodes .Also copy the 
shortest path in shortestpath array provided and its length in shortestpathlen.Return -1 for NULL inputs .

Example 1:
    5
   / \
  4   3
 / \   
-3  -1  
StartCity : 5 ,K=8 Total number of ways are 2 [5,4,-1 and 5,3] .Shortest path is [5,3]

Example 2: 
    10
   /  \
  5    -2
 / \   / \
5   1 9   9
   / \   / \
  10  1 3   -1
              \
               1
Start City : 10 ,K=17 , Total number of ways are 3 
Ways are 10->5->1 and 10-> -2 ->9 and 10-> -2 -> 9 -> -1 -> 1 
Shortest Path is [10,-2,9] (Not 10->5->1 as its product 50 is larger than -180)

Start City : -2 . K=10 . Total number of ways is 1 .Shortest Path is : [-2,9,3]
StartCity : 10 , K=100 ,Total number of ways is 0 .Shortest path is []

Note :You can use your own custom function with extra parameters, Max height of Tree will be 1000.
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

int isLeaf(struct node *root) {
	if (!root->left && !root->right) {
		return 1;
	}
	return 0;
}

int collected_k_mangoes(int k, int collected_mangoes) {
	if (k == collected_mangoes) {
		return 1;
	}
	return 0;
}

int isShortestPath(int i, int *pathlen) {
	if (i < *pathlen) {
		return 1;
	}
	return 0;
}

int get_ways_and_shortest_path(struct node *startcity, int k, int sum, int *path, int i, int *pathlen) {
	if (!startcity) {
		return 0;
	}
	sum += startcity->data;
	path[i++] = startcity->data;
	if (isLeaf(startcity)) {
		if (collected_k_mangoes(k, sum)) {
			if (isShortestPath(i, pathlen)) {
				*pathlen = i;
			}
			return 1;
		}
		return 0;
	}	
	int left = get_ways_and_shortest_path(startcity->left, k, sum, path, i, pathlen);
	int right = get_ways_and_shortest_path(startcity->right, k, sum, path, i, pathlen);
	return left + right;
}

int mangocity_count_ways(struct node *startcity, int k, int *shortestpath, int *shortestpathlen){
	//Just Copy values in shortestpath and shortestpathlen .Dont allocate memory for it .
	if (!startcity) {
		return -1;
	}
	int sum = 0;
	int *path = (int*)malloc(sizeof(int) * 1000);
	int i = 0;
	int pathlen = 1000;	
	int ways = get_ways_and_shortest_path(startcity, k, sum, path, i, &pathlen);
	for (int i = 0; i < pathlen; i++) {
		shortestpath[i] = path[i];
	}
	*shortestpathlen = pathlen;
	return ways;
}

/*
void insertInto2DArr(int **arr2, int *row, int *path, int *i) {
	if (!path || *row < 0 || *i < 0) {
		return;
	}
	for (int j = 0; j < *i; j++) {
		*(*(arr2 + *row * 1000) + j) = path[j];
	}
}

int all_k_paths(struct node *startcity, int k, int sum) {//int *path, int *i, int **arr2, int *row) {
	if (isLeaf(startcity)) {
		sum += startcity->data;
		if (sum == k) {
			return 1;
		}
		return 0;
	}
	sum += startcity->data;
	
	int left = all_k_paths(startcity->left, k, sum);
	int right =	all_k_paths(startcity->right, k, sum);
	return left + right;	
}

int mangocity_count_ways(struct node *startcity,int k, int *shortestpath,int *shortestpathlen){
	//Just Copy values in shortestpath and shortestpathlen .Dont allocate memory for it .
	if (!startcity) {
		return -1;
	}
	
	//2d array
	/*
	int **arr2 = (int**)malloc(sizeof(int*) * 1000);
	for (int i = 0; i < 1000; i++) {
		arr2[i] = (int*)malloc(sizeof(int) * 1000);
	}
	int row = 0;
	

	int	*path = (int*)malloc(sizeof(int) * 1000);
	int i = 0;
	*\/
	
	int sum = 0;
	int ways = all_k_paths(startcity, k, sum);
	/*
	for (int j = 0; j < row; j++) {
		for (int l = 0; l < 10; l++) {
			printf("%d ", arr2[j][l]);
		}
	}
	*\/
	return ways;
}
*/
