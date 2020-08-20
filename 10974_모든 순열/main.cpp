#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	fflush(stdin);
	
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