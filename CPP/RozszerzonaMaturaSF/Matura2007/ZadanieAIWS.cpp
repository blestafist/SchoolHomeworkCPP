#include <iostream>
#include <fstream>
using namespace std;

bool czypierwsza(int liczba){
	if(liczba<2)
		return false;
	for(int i=2;i*i<=liczba;i++)
		if(liczba%i==0)
			return false;
	return true;
}

int sumacyfr10(int liczba){
	int suma=0;
	while(liczba>0){
		suma+=liczba%10;
		liczba/=10;
	}
	return suma;
}

string dziesietnanabinarna(int liczba10){
	string liczba2="";
	char znak;
	while(liczba10>0){
		znak=liczba10%2+48;
		liczba2=znak+liczba2;
		liczba10/=2;
	}
	return liczba2;
}

int sumacyfr2(string liczba2){
	int suma=0;
	for(int i=0;i<liczba2.size();i++)
		if(liczba2[i]=='1')
			suma++;
	return suma;
}

void wyswietl(std::string nazwa_pliku, int zakres_p, int zakres_k){
	int licznik=0;
	fstream plik;
	plik.open(nazwa_pliku, ios::out);
	for(int i=zakres_p;i<=zakres_k;i++)
		if(czypierwsza(i) and czypierwsza(sumacyfr10(i)) and czypierwsza(sumacyfr2(dziesietnanabinarna(i)))){
			plik << i << endl;
			licznik++;
		}
	plik.close();
	cout << "W przedziale liczb <"<<zakres_p<<","<<zakres_k<<"> znajduje siê " << licznik << " \"super B pierwszych\"" << endl;
}

int main(){
	setlocale(LC_ALL,"");	
	
	wyswietl("1.txt", 2, 1000);
	wyswietl("2.txt", 100, 10000);
	wyswietl("3.txt", 1000, 100000);
	
	return 0;
}