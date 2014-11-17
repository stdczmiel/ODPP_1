#include <string>
//#include "problem.h"

#ifndef PROBLEM_GNIAZDOWY_H
#define PROBLEM_GNIAZDOWY_H

/*!
 * \brief Klasa implementuje problem gniazdowy
 *  Umo�liwia wczytywanie danych z pliku, s�u�y do harmonogramowania zada�
 *  w przypadku problemu gniazdowego
 */
class problem_gniazdowy
{
private:
    int n;      /** liczba operacji*/
    int z;      /** liczba zada� */
    int m;      /** liczba maszyn */
    int *czasi; /** czas wykonywania i-tej operacji */
    int *pi;    /** struktura przechowujaca permutacje: pi = [0 operacje_maszyny_1 0 operacje_maszyny_2 0 ... 0] */
    int *ti;    /** nast�pniki technologiczne */
    int *T;
    int *ps;    /** pozycje i-tych operacji w tabeli permutacji */
    int *lp;    /** poprzedniki */
    int *ci;    /** czas zakonczenia i-tej operacji */
	int *ph;	/** �cie�ka krytyczna*/
public:
    /*!
     * \brief problem_gniazdowy - konstruktor bezparametryczny
     *  Wszystkie zmienne s� wyzerowane, wska�niki ustawione na NULL
     */
    problem_gniazdowy();

    /*!
     * \brief Destruktor
     * Gdy wska�niki s� r�ne od NULL, pami�� na kt�r� wskazuj� zostaje zwolniona.
     */
    ~problem_gniazdowy();
    /*!
     * \brief Metoda wczytuj�ca dane z pliku
     * Wczytywane dane s� wpisywane do tablicy pi jako dopuszczalna permutacja problemu.
     * Wype�nione zostaj� r�wnie� tablice ps, ti oraz czasi.
     * \param file - nazwa pliku do wczytania
     * \return false je�li nie uda�o si� otworzy� pliku, true w przeciwnym przypadku
     */
    bool readFile(std::string file = "ta01.txt");
    /*!
     * \brief Metoda tworz�ca obiekt
     * Na podstawie wczytanej wcze�niej liczby zada� i maszyn, zostaje zaalokowana pami�� dla
     * tabli pi, ps, ti oraz czasi.
     */
    void createPi();
    /*!
     * \brief Metoda tworzy tablic� nast�pnik�w technologicznych
     * Do dzia�ania potrzebuje permutacji pi i wype�nionej tablicy ps.
     */
    void makeTi();
	/*!
	* \brief Metoda tworzy tablice liczba poprzednikow
	* Tablica ta jest niezb�dna dla algorytmu tworz�cego
	* harmonogram, zlicza ile operacji jest gotowych w danym momencie
	* wykonywania algorytmu.
	*/
    void makeLp();
	/*!
	* \brief Metoda s�u�y do wypisywania wszystkich zmiennych klasy.
	* Zmienne te wypisywane s� na stdout.
	*/
    void logClass();
	/*!
	* \brief Metoda pomocnicza funkcji problem_gniazdowy::createSchedule().
	* Oblicza czas zako�czenia ::i -tej operacji: c_max(i) = max(T[i-1],pi[ps[i]-1])+czas_wykonywania
	* gdzie T[i-1] to poprzednik technologiczny, pi[ps[i]-1] to poprzednik maszynowy.
	* \param i  - numer operacji
	*/
	void evalCi(int i);
	/*!
	* \brief Metoda tworz�ca harmonogram dla danej permutacji.
	*/
    void createSchedule();
};

#endif // PROBLEM_GNIAZDOWY_H