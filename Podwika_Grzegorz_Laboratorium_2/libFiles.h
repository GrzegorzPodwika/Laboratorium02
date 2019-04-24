#ifndef LIBFILES_H
#define LIBFILES_H

#include <fstream>
#include <random>

/*
Funkcja sprawdzajaca czy otwierany plik istnieje
@param	file przesy³any plik do sprawdzenia
@return true jesli istnieje lub false jesli nie istnieje
*/
bool isFileExist(std::fstream &file);

/*
Funkcja wczytujaca plik do odczytu, w przypadku niepowodzenia tworzaca plik i wypelaniajaca go zawartoscia
@param	fileName nazwa pliku do odczytu lub stworzenia
@return wczytany plik lub wygenerowany sztucznie
*/
std::fstream createReadFile(char *fileName);

/*
Funkcja generujaca plik tekstowy do zapisu jak i odczytu, wraz z kontrola bledu
@param	fileName nazwa pliku do utworzenia
@return plik typu fstream do zapisu i odczytu
*/
std::fstream createRecordFile(char* fileName);

/*
Funkcja	wypelniajaca plik losowymi wartosciami
@param	file przesylany plik do wypelnienia
*/
void fillFileWithRandomData(std::fstream &file);

/*
Funkcja pomocnicza, zapisujaca tablice powtorzen elementow, tablice indeksow, tablice bez duplikatow do pliku wynikowego
@param	resFile wynikowy plik do ktorego program zapisuje dane
@param	tabOfElements tablica powtorzen elementow
@param	toeSize rozmiar tablicy powtorzen elementow
@param	tabOfIndices tablica z indeksami danych elementow
@param	toiSize rozmiar tablicy indeksow
@param	tabWithoutCopies glowna tablica elementow bez duplikatow
@param	twcSize rozmiar tablicy bez duplikatow
*/
void saveDataToFile(std::fstream &resFile, int *tabOfElements, int toeSize, int *tabOfIndices, int toiSize, int *tabWithoutCopies, int twcSize);

/*
Funkcja glowna, odpowiadajaca za wczytanie danych z pierwszego pliku, obliczanie rezultatow i wpisywanie ich do pliku wyjsciowego
@param	loadedFile przesylany plik do wczytywania zestawow danych
@param	fileToSave plik do zapisu danych wynikowych
*/
void loadComputeAndSaveDataToFile(std::fstream &loadedFile, std::fstream &fileToSave);

#endif
