#include "pch.h"
#include "libFiles.h"
#include "libTables.h"
#include "libAlgorithm.h"
#include <iomanip>
using namespace std;



bool isFileExist(fstream &file)
{
	if (!file) {
		cout << "Nie ma takiego pliku, ale go wygenerujemy." << endl;
		file.close();
		return false;
	}else
		return true;
}

fstream createReadFile(char * fileName)
{
	fstream rFile(fileName, ios::in);

	if (!rFile) {
		cout << "Nie ma takiego pliku, ale go wygenerujemy." << endl;
		rFile = createRecordFile(fileName);
		fillFileWithRandomData(rFile);
		return rFile;
	}
	else
	{
		return rFile;
	}

}

fstream createRecordFile(char* fileName)
{
	fstream file(fileName, ios::out | ios::in | ios::trunc);
	if (!file) {
		cout << "Pliku nie mozna utworzyc!";
		getchar();
		exit(0);
	}

	return file;
}



void fillFileWithRandomData(std::fstream &file)
{
	constexpr int AMOUNT_OF_ELEMENTS = 1000;
	constexpr int SIZE_OF_SVTAB = 100;

	int numberOfDataSets = drawNumberFromRanges(2, 4);
	file << numberOfDataSets << endl;

	for (int i = 0; i < numberOfDataSets; i++)
	{
		int *mainTab = createTable(AMOUNT_OF_ELEMENTS);
		fillTableRandomNumbers(mainTab, AMOUNT_OF_ELEMENTS);
		sortTable(mainTab, AMOUNT_OF_ELEMENTS);

		file << AMOUNT_OF_ELEMENTS << endl;
		for (int j = 0; j < AMOUNT_OF_ELEMENTS; j++)
		{
			file << mainTab[j] << " ";
		}
		file << endl << SIZE_OF_SVTAB << endl;


		int *searchValTab = createTable(SIZE_OF_SVTAB);
		fillTableRandomNumbers(searchValTab, SIZE_OF_SVTAB);

		for (int j = 0; j < SIZE_OF_SVTAB; j++)
		{
			file << searchValTab[j] << " ";
		}

		file << endl;

		delete[] mainTab;
		delete[] searchValTab;
	}

}

void saveDataToFile(fstream &resFile, int * tabOfElements, int toeSize, int * tabOfIndices, int toiSize, int * tabWithoutCopies, int twcSize)
{
	for (int i = 0; i < toeSize; i++)
	{
		resFile << "(" << tabOfElements[i] << " " << tabOfIndices[i] << ")" << " ";
	}

	resFile << endl;

	for (int i = 0; i < twcSize; i++)
	{
		if (i < 200) {
			resFile << setw(5) << tabWithoutCopies[i] << " ";
			if ((i + 1) % 50 == 0) {
				resFile << endl;
			}
		}
	}

	resFile << endl;

}


void loadComputeAndSaveDataToFile(fstream &loadedFile, fstream &fileToSave)
{
	loadedFile.seekg(0, ios_base::beg);

	int numberOfDataSets{};
	loadedFile >> numberOfDataSets;

	int pozycja = loadedFile.tellg();

	for (int j = 0; j < numberOfDataSets; j++) {

		loadedFile.seekg(pozycja);

		int mtSize{};
		loadedFile >> mtSize;
		int *mainTab = createTable(mtSize);

		for (int i = 0; i < mtSize; i++)
		{
			loadedFile >> mainTab[i];
		}

		int stSize{};
		loadedFile >> stSize;
		int *searchValTab = createTable(stSize);

		for (int i = 0; i < stSize; i++)
		{
			loadedFile >> searchValTab[i];
		}

		pozycja = loadedFile.tellg();

		int nSize{};
		int *tabOfElements = numberOfElementsEqualSetValue(mainTab, mtSize, searchValTab, stSize);
		int *tabOfIndices = indexOfSearchValue(mainTab, mtSize, searchValTab, stSize);
		int *tabWithoutCopies = tabWithoutCounterparts(mainTab, mtSize, nSize);

		saveDataToFile(fileToSave, tabOfElements, stSize, tabOfIndices, stSize, tabWithoutCopies, nSize);

		delete[] tabOfElements;
		delete[] tabOfIndices;
		delete[] tabWithoutCopies;
	}
}