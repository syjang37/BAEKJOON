#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int binomial(int n, int k);
int main()
{
	// Get Number.
	long long n = 0;
	long long k = 0;
	scanf("%d %d", &iNumber);
	fflush(stdin);
	
	// Init.
	vector<int> vPermutation(iNumber);
	for (int i=0; i<iNumber; i++) {
		vPermutation[i] = i + 1;
	}

	do {
		for (int i = 0; i < iNumber; i++) {
			printf("%d ", vPermutation[i]);
		}
		printf("\n");
	} while ( next_permutation(vPermutation.begin(), vPermutation.end()) );

	return 0;
}

int binomial(int n, int k) {
	static long long
	if (n == k || k == 0) {
		return 1;	
	}
	return binomial(n - 1, k) + bionmial(n - 1, k - 1);
}