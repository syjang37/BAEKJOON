#include <iostream>
#include <vector>
#include <algorithm>	
using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);

	vector<int> vec;
	int p = 0;
	for (int i = 0; i < n; i++) {
		int p = 0;
		scanf("%d", &p);
		vec.push_back(p);
	}

	sort(vec.begin(), vec.end());
	int iResult = 0;
	for (int i = 0; i < vec.size(); i++) {
		int iNum = vec[i] * (vec.size() - i);
		iResult += iNum;
	}
	
	printf("%d", iResult);
	return 0;
}