#include <iostream>
#include <fstream>

using namespace std;

const string INPUT_FILE = "cyfry.txt";
const string OUTPUT_FILE = "zadanie4.txt";

bool IsEven(int tempInt)
{
    return tempInt % 2 == 0 ? true : false;
}

int main()
{
    ifstream inputFile (INPUT_FILE);
    ofstream outputFile (OUTPUT_FILE);

    if(!inputFile.is_open()) cout << "error open file";

    int tempInt, counter = 0, minNum;

    while(inputFile >> tempInt)
    {
        if(IsEven(tempInt)) counter++;
    }

    cout << "zadanieA" << endl << counter << endl;
    outputFile << "zadanieA" << endl << counter << endl;

    inputFile.close();
    inputFile.open(INPUT_FILE);

    inputFile >> tempInt;
    minNum = tempInt;
    
    cout << minNum << endl;
    while(inputFile >> tempInt)
    {
        if(minNum < tempInt)
            minNum = tempInt;
    }
    
    inputFile.close();
    outputFile.close();
}

/* 

Мои замечания: пишу снизу чтобы код не портить

1. Убери using namespace std;
2. Константы лучше отделять комментами с ================
3. Больше отступы между функциями (по 2 endl между логическимим блоками)
4. return tempInt % 2 == 0 ? true : false; → тернарный оператор не нужен. Можно просто return tempInt % 2 == 0;
5. Пробелы после if, for, while
6. На 19 и 25 строке фигурные скобочки
7. Дальше как я понимаю еще не сделано тк там логические ошибки

*/