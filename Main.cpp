#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    pair <string, string> para;
    vector <pair<string,string> > wejscie;

    int rozm;                                           //Podanie rozmiaru tablicy wyjsciowej
    cout << "Podaj rozmiar tablicy wyjsciowej: ";
    cin >> rozm;

    list <pair<string,string> > wyjscie[rozm];

    int licznik;                                 //Wypelnienie wektora danymi wejsciowymi
    string a, b;
    cout << "\n\nIle par (klucz, dana) chcesz wczytac: ";
    cin >> licznik;
    for(int i=0; i<licznik; i++)
    {
        cout << "Podaj " << i+1 << ". klucz: ";
        cin >> a;
        cout << "Podaj " << i+1 << ". dana: ";
        cin >> b;

        para = make_pair(a, b);
        wejscie.push_back(para);
    }

    fstream plik("TH.txt", ios::out);                   //Wypisanie tablicy przed zahaszowaniem
    plik << "Tablica przez zahaszowaniem: " << endl;
    for(int i=0; i<licznik; i++)
    {
        plik << "{" << wejscie[i].first << " , " << wejscie[i].second << "}" << endl;
    }
    plik << endl << endl;


    int opcja;
    int opcja2;                                             //Wybor opcji haszowania
    cout << "\n\n(1)Haszowanie przez dzielenie." << endl;
    cout << "(2)Haszowanie przez mnozenie." << endl;
    cout << "Wybierz co chcesz robic: ";
    cin >> opcja;
    int klucz;
    int hdziel;
    int hmnoz;

    switch(opcja)
    {
    case 1:                                 //Haszowanie modularne
        {
            plik << "Tablica po zahaszowaniu:" << endl;
            for(int i=0; i<licznik; i++)        //Wypelnienie wszystkich mozliwych list z tablicy wyjsciowej
            {
                klucz = 0;
                for(int j=0; j<(wejscie[i].first).size(); j++)
                {
                        klucz = klucz+(int)(wejscie[i].first)[j];
                }

                hdziel = klucz%rozm;
                wyjscie[hdziel].push_front(wejscie[i]);
            }
            cout << endl << endl;

            for(int i=0;i<rozm;i++)                 //Wypisanie zawartosci pliku+zapisanie jej do pliku
            {
                for(list<pair<string, string> >::iterator it = wyjscie[i].begin(); it != wyjscie[i].end(); it++)
                {
                    cout << "{" << (*it).first << " , " << (*it).second << "}" << "    ";
                    plik << "{" << (*it).first << " , " << (*it).second << "}" << "    ";
                }
                cout << endl;
                plik << endl;
            }

                cout << "\n(1)Wyszukaj po kluczu" << endl;
                cout << "(2)Zakoncz dzialanie programu" << endl;
                cout << "Co chcesz zrobic?: ";
                cin >> opcja2;

                switch(opcja2)
                {


                    case 1:
                        {
                            string szukaj;
                            cout << "Wybierz klucz po ktorym chcesz wyszukac: ";
                            cin >> szukaj;

                            for(int i=0; i<licznik; i++)
                                {
                                klucz = 0;
                                    for(int j=0; j<(wejscie[i].first).size(); j++)
                                    {
                                        klucz = klucz+(int)(wejscie[i].first)[j];
                                    }
                                hdziel = klucz%rozm;
                                }

                                cout << "Wyszukiwanie po kluczu " << szukaj << endl;
                                for(int i=0; i<licznik; i++)
                                {
                                    if(szukaj == wejscie[i].first)
                                    {

                                        cout << "{ " << wejscie[i].first << " , " << wejscie[i].second << " }   ";
                                    }
                                }


                        }

                    case 2:
                        {
                            break;
                        }

                }

            break;
        }


    case 2:                                 //Haszowanie przez mnozenie
        {
            double stala;
            cout << "Prosze podac liczbe z zakresu (0;1): ";
            cin >> stala;
            plik << "Tablica po zahaszowaniu:" << endl;
            for(int i=0; i<licznik; i++)        //Wypelnienie wszystkich mozliwych list z tablicy wyjsciowej
            {
                klucz = 0;
                for(int j=0; j<(wejscie[i].first).size(); j++)
                {
                        klucz = klucz+(int)(wejscie[i].first)[j];
                }

                hmnoz = floor(rozm*((stala*klucz)-floor(stala*klucz)));
                wyjscie[hmnoz].push_front(wejscie[i]);
            }
            for(int i=0;i<rozm;i++)                 //Wypisanie zawartosci pliku+zapisanie jej do pliku
            {
                for(list<pair<string, string> >::iterator it = wyjscie[i].begin(); it != wyjscie[i].end(); it++)
                {
                    cout << "{" << (*it).first << " , " << (*it).second << "}" << "    ";
                    plik << "{" << (*it).first << " , " << (*it).second << "}" << "    ";
                }
                cout << endl;
                plik << endl;
            }

                cout << "\n(1)Wyszukaj po kluczu" << endl;
                cout << "(2)Zakoncz dzialanie programu" << endl;
                cout << "Co chcesz zrobic?: ";
                cin >> opcja2;

            switch(opcja2)
                {
                    case 1:
                        {
                            string szukaj;
                            cout << "Wybierz klucz po ktorym chcesz wyszukac: ";
                            cin >> szukaj;

                            for(int i=0; i<licznik; i++)        //Wypelnienie wszystkich mozliwych list z tablicy wyjsciowej
                                {
                                    klucz = 0;
                                    for(int j=0; j<(wejscie[i].first).size(); j++)
                                    {
                                            klucz = klucz+(int)(wejscie[i].first)[j];
                                    }
                                    hmnoz = floor(rozm*((stala*klucz)-floor(stala*klucz)));
                                }

                                cout << "Wyszukiwanie po kluczu " << szukaj << endl;
                                for(int i=0; i<licznik; i++)
                                {
                                    if(szukaj == wejscie[i].first)
                                    {

                                        cout << "{ " << wejscie[i].first << " , " << wejscie[i].second << " }   ";
                                    }
                                }
                        }

                    case 2:
                        {
                            break;
                        }

                }
        }
    }
    plik.close();

    return 0;
}
