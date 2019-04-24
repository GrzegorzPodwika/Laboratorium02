#ifndef LIBALGORITHM_H
#define LIBALGORITHM_H

/*
Funkcja wczytujaca w poprawnej formie nazwe pliku
@param	fileName nazwa pliku we wlasciwej formie
*/
void loadCorrectFileName(char *fileName);

/*
Funkcja pomocnicza losujaca liczbe z przedzialu, ktorego 
wysylamy do funkcji za pomoca argumentow
@param	lowRange dolny zakres losowanej liczby
@param	highRange gorny zakres losowanej liczby
@return liczbe calkowita z podanego przedzialu
*/
int drawNumberFromRanges(int lowRange, int highRange);

/*
Funkcja obliczaj¹ca ile razy powtarza sie szukany element metoda wyszukiwania binarnego
@param	mainTab glowna tablica w ktorej zliczamy szukany element
@param	mtSize rozmiar glownej tablicy
@param	searchValTab tablica z wartosciami, ktorym poszukujemy
@param	svtSize rozmiar tablicy searchValTab
@return adres zerowego elementu wynikowej tablicy ze zliczonymi wartosciami
*/
int* numberOfElementsEqualSetValue(int *mainTab, int mtSize, int *searchValTab, int svtSize);

/*
Funkcja obliczajaca na ktorym indeksie jest szukany element metoda interpolacyjna
@param	mainTab glowna tablica w ktorej szukamy indeksu danego elementu z drugiej tablicy
@param	mtSize rozmiar glownej tablicy
@param	searchValTab tablica z liczbami, dla ktorych szukamy indeksow w glownej tablicy
@param	svtSize rozmiar tablicy searchValTab
@return adres zerowego elementu wynikowej tablicy z policzonymi indeksami
*/
int* indexOfSearchValue(int *mainTab, int mtSize, int *searchValTab, int svtSize);

/*
Funkcja usuwajaca duplikaty z glownej tablicy
@param mainTab glowna tablica z ktorej kopiujemy niepowtarzajace sie elementy
@param mtSize rozmiar glownej tablicy
@param nSize referencja do lwartosci, do ktorej zostanie wpisany rozmiar wynikowej tablicy
@return adres zerowego elementu wynikowej tablicy bez duplikatow
*/
int* tabWithoutCounterparts(int *mainTab, int mtSize, int &nSize);



#endif
