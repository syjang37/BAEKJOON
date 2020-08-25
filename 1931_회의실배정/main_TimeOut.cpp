#include <iostream>
#include <map>
using namespace std;

typedef map<int, map<int, int>> Confer;
typedef Confer::iterator Iter;

int getMaxConfer(Confer& p_mapConfer, Iter p_iter);
int main()
{
	// Get Size Info
	int iSize = 0;
	scanf("%d", &iSize);

	// Init Conference
	Confer mapConfer;
	for (int i = 0; i < iSize; i++) {
		int iStart = 0;
		int iEnd = 0;
		scanf("%d %d", &iStart, &iEnd);
		
		auto iter = mapConfer.find(iStart);
		if (iter != mapConfer.end()) {
			iter->second.insert(make_pair(iEnd, 0));
		}
		else {
			map<int, int> temp;
			temp.insert(make_pair(iEnd, 0));
			mapConfer.insert(make_pair(iStart, temp));
		}
	}

	printf("%d\n", getMaxConfer(mapConfer, mapConfer.begin()));
	return 0;
}

int getMaxConfer(Confer& p_mapConfer, Iter p_iter)
{
	int iMaxSize = 1;
	int iStart = p_iter->first;
	for (; p_iter != p_mapConfer.end(); p_iter++){
		int iInitConfer = 1;
		auto it_s = p_iter->second.begin();
		auto it_e = p_iter->second.end();
		for (; it_s != it_e; it_s++) {
			int iConferSize = iInitConfer;
			int iEnd = it_s->first;
			if (iEnd == iStart) {
				iInitConfer += 1;
				continue;
			}

			if (it_s->second == 0) {
				auto const_iter = p_mapConfer.find(iEnd);
				auto iter = p_mapConfer.begin();
				advance(iter, distance(p_mapConfer.begin(), const_iter));
				if (iter == p_mapConfer.end()) {
					auto temp_s = p_iter;
					temp_s++;

					bool bFind = false;
					for (; temp_s != p_mapConfer.end(); temp_s++) {
						if (temp_s->first >= iEnd) {
							iter = temp_s;
							bFind = true;
							break;
						}
					}

					if (!bFind) {
						it_s->second = 1;
						continue;
					}
				}
				iConferSize += getMaxConfer(p_mapConfer, iter);
				it_s->second = iConferSize;
			}

			iConferSize = it_s->second;
			if (iMaxSize < iConferSize) {
				iMaxSize = iConferSize;
			}
		}
	}
	return iMaxSize;
}