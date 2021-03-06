#include <iostream>
#include <string.h>
using namespace std;

#define MAX_SIZE 1000
int binomial(int n, int k);
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	fflush(stdin);

	printf("%d\n", binomial(n, k));
	return 0;
}
int binomial(int n, int k)
{
	static int array[MAX_SIZE][MAX_SIZE];
	if (n == k || k == 0) {
		array[n][k] = 1;
	}
	else
	{
		array[n][k] = binomial(n - 1, k) + binomial(n - 1, k - 1);
	}
	return array[n][k];
}