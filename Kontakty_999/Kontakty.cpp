#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
vector<string> v_nrtel;
vector<string> v_imie;
vector<string> v_nazw;
vector<string> v_mail;
vector<int> v_nrwpisu;
string nrtel;
string imie;
string nazw;
string mail;
int nrwpisu = -1;
char menu;
int nrdousun;

void print_table(vector<string> v_nrtel, vector<string> v_imie, vector<string> v_nazw, vector<string> v_mail)
{
	for (int i = 0; i < v_imie.size(); i++)
	{
		cout << v_nrwpisu[i] << ". " << v_imie[i] << "  " << v_nazw[i] << "  " << v_nrtel[i] << "  " << v_mail[i] << "\n";
	}
}


void display_menu()
{

	cout << "Wcisnij: n - nowy kontakt, e - edytuj istniejacy kontakt, u - usun kontakt, w - wyswietl liste, z - zapisz dane, o - odczytaj dane z pliku, s - szukaj, q - zamknij program \n";
	cin >> menu;
	if (menu == 'n')
	{
		cout << "Podaj imie: ";
		cin >> imie;
		v_imie.push_back(imie);
		cout << "Podaj nazwisko: ";
		cin >> nazw;
		v_nazw.push_back(nazw);
		cout << "Podaj numer telefonu: ";
		cin >> nrtel;
		v_nrtel.push_back(nrtel);
		cout << "Podaj adres e-mail: ";
		cin >> mail;
		v_mail.push_back(mail);

		nrwpisu += 1;
		v_nrwpisu.push_back(nrwpisu);
		print_table(v_nrtel, v_imie, v_nazw, v_mail);

	}
	if (menu == 'w')
	{
		print_table(v_nrtel, v_imie, v_nazw, v_mail);

	}
	if (menu == 's')
	{
		char stype;
		string szukana;
		size_t znaleziona;
		print_table(v_nrtel, v_imie, v_nazw, v_mail);
		cout << "Szukaj w: imionach - i, nazwiskach - n, numerach - t, mail - m \n";
		cin >> stype;
		cout << "Podaj szukana fraze: \n";
		cin >> szukana;

		if (stype == 'i')
		{
			for (int i = 0; i < sizeof(v_imie); i++)
			{
				znaleziona = v_imie[i].find(szukana);
				if (znaleziona != string::npos)
					cout << "Znalezionio w wierszu " << i << endl;
			}

		}

	}
	if (menu == 'e')
	{
		int nrdoedycji;
		char wyborpola;
		cout << "Podaj numer wpisu do edycji: \n";
		cin >> nrdoedycji;
		cout << "Co chcesz zmienic? i - imie, n - nazwisko, t - telefon, m - mail \n";
		cin >> wyborpola;
		if (wyborpola == 'i')
		{
			cout << "Wproadz nowe dane: \n";
			cin >> imie;
			v_imie.at(nrdoedycji) = imie;
			cout << "Zmieniono na" << imie << "\n";
		}
		if (wyborpola == 'n')
		{
			cout << "Wproadz nowe dane: \n";
			cin >> nazw;
			v_nazw.at(nrdoedycji) = nazw;
			cout << "Zmieniono na" << nazw << "\n";
		}
		if (wyborpola == 't')
		{
			cout << "Wproadz nowe dane: \n";
			cin >> nrtel;
			v_nrtel.at(nrdoedycji) = nrtel;
			cout << "Zmieniono na" << nrtel << "\n";
		}
		if (wyborpola == 'm')
		{
			cout << "Wproadz nowe dane: \n";
			cin >> mail;
			v_mail.at(nrdoedycji) = mail;
			cout << "Zmieniono na" << mail << "\n";
		}

	}

	if (menu == 'u')
	{
		cout << "Podaj numer wpisu: ";
		cin >> nrdousun;
		v_nrtel.erase(v_nrtel.begin() + nrdousun), v_imie.erase(v_imie.begin() + nrdousun), v_nazw.erase(v_nazw.begin() + nrdousun), v_mail.erase(v_mail.begin() + nrdousun);
		cout << "Wpis o numerze " << nrdousun << " zostal usuniety. \n";
	}
	if (menu == 'z')
	{
		ofstream sdata("data.txt");
		for (int i = 0; i < v_imie.size(); i++)
		{
			if (i > 0)
			{
				sdata << '\n';
			}
			sdata << v_imie[i] << "\t" << v_nazw[i] << "\t" << v_nrtel[i] << "\t" << v_mail[i];
		}
		cout << "Dane zostaly zapisane.\n";
	}
	if (menu == 'o')
	{
		ifstream sdata("data.txt");

		if (sdata.fail())
		{
			cerr << "error opening file";
			exit(1);
		}
		else
		{
			v_nrwpisu.clear();
			while (!sdata.eof())
			{
				getline(sdata, imie, '\t');
				v_imie.push_back(imie);
				getline(sdata, nazw, '\t');
				v_nazw.push_back(nazw);
				getline(sdata, nrtel, '\t');
				v_nrtel.push_back(nrtel);
				getline(sdata, mail, '\n');
				v_mail.push_back(mail);
				nrwpisu += 1;
				v_nrwpisu.push_back(nrwpisu);
			}
		}
		cout << "Dane odczytane poprawnie\n";
		sdata.close();
	}
	if (menu == 'q')
	{
		exit(0);
	}

	display_menu();
}

int main()
{

	display_menu();
}