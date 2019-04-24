#include "pch.h"
#include "libAlgorithm.h"
#include "libFiles.h"
#include "libTables.h"
using namespace std;



void loadCorrectFileName(char *fileName)
{
	cin >> fileName;
	int nameLength = strlen(fileName);
	bool flag = false;

	for (int i = 1; i <= 3; i++)
	{
		if (i == 3) {
			cout << "Przekroczono limit prob wprowadzenia wlasciwej nazwy.";
			cin.ignore();
			exit(0);
		}

		for (int j = 0; j < nameLength; j++)
		{
			if (j <= nameLength - 4 && fileName[j] == '.' && fileName[j + 1] == 't' && fileName[j + 2] == 'x' && fileName[j + 3] == 't') {
				flag = true;
				break;
			}
		}

		if (flag)
			break;
		else {
			cout << "Bledna nazwa pliku! Podaj nazwe z rozszerzeniem .txt!" << endl;
			cin >> fileName;
			nameLength = strlen(fileName);
		}
	}
}



int drawNumberFromRanges(int lowRange, int highRange)
{
	int resultNumb{};

	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(lowRange, highRange);
	resultNumb = dist(rd);

	return resultNumb;
}

int* numberOfElementsEqualSetValue(int *mainTab, int mtSize, int *searchValTab, int svtSize)
{
	int *resTab = createTable(svtSize);

	for (int i = 0; i < svtSize; i++) {
		resTab[i] = 0;
	}

	int low{};
	int high = mtSize - 1;
	int mid{};
	bool isFound = false;
	int lowestIndex{};
	int highestIndex{};

	for (int i = 0; i < svtSize; i++, low = 0, mid = 0, high = mtSize - 1, isFound = false)
	{
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (searchValTab[i] == mainTab[mid]) {
				isFound = true;
				if (mid == 0) break;							// jesli jest to pierwszy element element przerwij
				if (searchValTab[i] == mainTab[mid - 1])		// jesli poprzedni element rowna sie szukanej wartosci obniz gorna granice
					high = mid - 1;
				else
					break;										// jesli poprzedni elemnt nie jest szukana wartoscia, przerwij prace, znalezlismy najmniejszy index
			}
			else if (searchValTab[i] < mainTab[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		if (isFound)
			lowestIndex = mid;

		low = 0;
		mid = 0;
		high = mtSize - 1;
		isFound = false;

		while (low <= high)
		{
			mid = (low + high) / 2;
			if (searchValTab[i] == mainTab[mid]) {
				isFound = true;
				if (mid == high) break;							// jesli jest to ostatni element, przerwij
				if (searchValTab[i] == mainTab[mid + 1])		// jesli poprzedni element rowna sie szukanej wartosci zwieksz dolna granice
					low = mid + 1;
				else
					break;										// jesli nastepny elemnt nie jest szukana wartoscia, przerwij prace, znalezlismy najmniejszy index
			}
			else if (searchValTab[i] < mainTab[mid]) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}

		if (isFound)
		{
			highestIndex = mid;
			resTab[i] = highestIndex - lowestIndex + 1;
		}
		else
			resTab[i] = 0;



	}


	return resTab;
}


int * indexOfSearchValue(int * mainTab, int mtSize, int * searchValTab, int svtSize)
{
	int *tabOfIndices = createTable(svtSize);
	int searchIndex{};
	int low{};
	int high = mtSize - 1;

	for (int i = 0; i < svtSize; i++)
	{
		tabOfIndices[i] = -1;
	}

	for (int i = 0; i < svtSize; i++, low = 0, searchIndex = 0, high = mtSize - 1)
	{
		while (mainTab[low] <= searchValTab[i] && searchValTab[i] <= mainTab[high]) {
			
			if (mainTab[high] - mainTab[low] == 0) {
				tabOfIndices[i] = low;
				break;
			}

			searchIndex = low + rint((searchValTab[i] - mainTab[low]) * (high - low) / (mainTab[high] - mainTab[low]));

			if (mainTab[searchIndex] == searchValTab[i]) {
				tabOfIndices[i] = searchIndex;
				break;
			}
			else if (mainTab[searchIndex] > searchValTab[i]) {
				high = searchIndex - 1;
			}
			else {
				low = searchIndex + 1;
			}
		}
	}

	return tabOfIndices;
}

int *tabWithoutCounterparts(int * mainTab, int mtSize,int  &nSize)
{
	int *tabWC = createTable(mtSize);
	nSize = 0;

	for (int i = 0; i < mtSize; i++)
	{
		if (i == 0)
		{
			tabWC[0] = mainTab[i];
			++nSize;
		}
		else if (tabWC[nSize - 1] != mainTab[i]) {
			tabWC[nSize] = mainTab[i];
			++nSize;
		}
	}
	return tabWC;
}
