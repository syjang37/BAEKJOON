#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int main()
{
	// Get Number.
	int iNumber = 0;
	scanf("%d", &iNumber);
	fflush(stdin);
	
	// Init.
	vector<int> vPermutation(iNumber);
	for (int i=0; i<iNumber; i++) {
		vPermutation[i] = i + 1;
	}

	do {
		for (int i = 0; i < iNumber; i++) {
			cout << vPermutation[i] << " ";
		}
		cout << "\n";
	} while ( next_permutation(vPermutation.begin(), vPermutation.end()) );

	return 0;
}
