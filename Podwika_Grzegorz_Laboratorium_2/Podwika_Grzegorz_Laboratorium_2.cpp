// Podwika_Grzegorz_Laboratorium_2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include "libFiles.h"
#include "libTables.h"
#include "libAlgorithm.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


int main()
{
	char fileName[50];
	loadCorrectFileName(fileName);
	fstream readFile = createReadFile(fileName);

	loadCorrectFileName(fileName);
	fstream recordFile = createRecordFile(fileName);

	loadComputeAndSaveDataToFile(readFile, recordFile);

	recordFile.close();
	readFile.close();
	cin.ignore();
	return 0;
}
