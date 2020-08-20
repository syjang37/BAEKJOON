#include <iostream>
#include <string.h>
using namespace std;

int ** arr;
int binomial(int n, int k);
int main()
{
	int n = 0;
	int k = 0;
	scanf("%d %d", &n, &k);
	fflush(stdin);

	arr = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = new int[k];
		memset(arr[i], -1, sizeof(int)*k);
	}

	printf("%d\n", binomial(n, k));
	return 0;
}
int binomial(int n, int k)
{
	if (n == k || k == 0) {
		arr[n][k] = 1;
	}
	else 
	{
		arr[n][k] = binomial(n - 1, k) + binomial(n - 1, k - 1);
	}
	return arr[n][k];
}