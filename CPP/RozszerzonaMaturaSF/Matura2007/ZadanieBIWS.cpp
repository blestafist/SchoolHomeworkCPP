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

void pytanie1(){
	int licznik=0;
	for(int i=100;i<=10000;i++)
		if(czypierwsza(sumacyfr10(i)))
			licznik++;
	cout << "Liczb w przedziale <100,10000>, " <<
	"których suma jest liczb¹ pierwsz¹ jest: " << licznik << endl;
}

void pytanie2(){
	int sumaliczb=0;
	for(int i=100;i<=10000;i++)
		if(czypierwsza(i) and czypierwsza(sumacyfr10(i)) and czypierwsza(sumacyfr2(dziesietnanabinarna(i))))
			sumaliczb+=i;
	if(czypierwsza(sumaliczb))
		cout << "TAK, suma wszystkich liczb \"super B pierwszych\" " <<
		"w przedziale <100,10000> jest liczb¹ pierwsz¹" << endl;
	else
		cout << "NIE, suma wszystkich liczb \"super B pierwszych\" " << 
		"w przedziale <100,10000> jest liczb¹ z³o¿on¹." << endl;
}

int main(){
	setlocale(LC_ALL,"");	
	
	pytanie1();
	pytanie2();
	
	return 0;
}