#include <iostream>
using namespace std;

typedef struct House {
	int iR, iG, iB;
	struct House *next;
	
	House() {
		this->iR = 0;
		this->iG = 0;
		this->iB = 0;

		next = NULL;
	}

	int getCost(int p_iData) {
		int iResult = 0;
		if (next == NULL) {
			switch(p_iData) {
			case 1: iResult = this->iR; break;
			case 2: iResult = this->iG; break;
			case 3: iResult = this->iB; break;
			}
		}
		else {
			switch (p_iData) {
			case 1: iResult = next->iG < next->iB ? iR + next->iG : iR + next->iB; break;
			case 2: iResult = next->iR < next->iB ? iG + next->iR : iG + next->iB; break;
			case 3: iResult = next->iR < next->iG ? iB + next->iR : iB + next->iG; break;
			}
		}
		return iResult;
	}
} House;

int getLowestCost(House* pr_house, int p_iData);
int main()
{
	// Get Number of House
	int iNum = 0;
	scanf("%d", &iNum);

	// Init
	House* house = NULL;
	auto nextHouse = house;
	for (int i = 0; i < iNum; i++)  {
		if (house == NULL) {
			house = new House();
			nextHouse = house;
		}
		else {
			nextHouse->next = new House();
			nextHouse = nextHouse->next;
		}

		scanf("%d %d %d", &nextHouse->iR, &nextHouse->iG, &nextHouse->iB);
	}
	
	printf("%d\n", getLowestCost(house, 0));
	return 0;
}

int getLowestCost(House* pr_house, int p_iData)
{
	int iLow = 0;
	int iData = 0;
	if (pr_house != NULL) {
		// First.
		if (iData == 0) {
			if (pr_house->getCost(1) < pr_house->getCost(2)) {
				iData = pr_house->getCost(1) < pr_house->getCost(3) ? 1 : 3;
			}
			else {
				iData = pr_house->getCost(2) < pr_house->getCost(3) ? 2 : 3;
			}
		}
		else {
			switch (p_iData) {
			case 1:
				iData = pr_house->getCost(2) < pr_house->getCost(3) ? 2 : 3;
				break;

			case 2:
				iData = pr_house->getCost(1) < pr_house->getCost(3) ? 1 : 3;
				break;

			case 3:
				iData = pr_house->getCost(1) < pr_house->getCost(2) ? 1 : 2;
				break;

			}
		}

		switch (iData) {
		case 1: iLow += pr_house->iR; break;
		case 2: iLow += pr_house->iG; break;
		case 3: iLow += pr_house->iB; break;
		}

		pr_house = pr_house->next; 
		iLow += getLowestCost(pr_house, iData);
	}
	return iLow;
}