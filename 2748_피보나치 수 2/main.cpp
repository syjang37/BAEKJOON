#include <iostream>
using namespace std;

long long getFibo(const int& p_iCount);
void fibo(int& pr_iNumber, const int& p_iCount, long long& pr_iFirstFibo, long long& pr_iSecondFibo);
int main()
{
	// Get Total Count.
	int iNumber = 0;
	scanf("%d", &iNumber);

	// Get Fibo.
	printf("%lld\n", getFibo(iNumber));
	return 0;
}

long long getFibo(const int& p_iCount)
{
	int iNumber = 0;
	long long iFirstFibo = 0;
	long long iSecondFibo = 0;

	fibo(iNumber, p_iCount, iFirstFibo, iSecondFibo);

	return iSecondFibo;
}

void fibo(int& pr_iNumber, const int& p_iCount, long long& pr_iFirstFibo, long long& pr_iSecondFibo)
{
	switch (pr_iNumber)
	{
	case 0:
		break;
	case 1:
		pr_iSecondFibo = 1;
		break;

	default:
		pr_iSecondFibo += pr_iFirstFibo;
		pr_iFirstFibo = (pr_iSecondFibo - pr_iFirstFibo);
		break;
	}

	if (pr_iNumber != p_iCount)
	{
		pr_iNumber++;
		fibo(pr_iNumber, p_iCount, pr_iFirstFibo, pr_iSecondFibo);
	}
}