#include <fstream>
#include <vector>

using namespace std;

const int HashTableSize = 100001; // Размер хеш-таблицы
vector<pair<string, string>> HashTable[HashTableSize]; // Создаем хеш-таблицу через пару элементов

int Search(vector<pair<string, string>> a, const string& key) // Функция поиска в хеш-таблице по ключу
{
    for (int i = 0; i < a.size(); i++) // цикл по всем элементам таблицы
        if (a[i].first == key) // если встретели нужный ключ
            return i; // возвращаем его индекс
    return 0; // возвращаем ноль
}

int GetHash(string key) // Функция для хеширования элементов 
{
    int CodeHash = 0; // хеш
    const int k = 15; // константа
    for (char i : key) // это цикл forarche. Он совершает одну итерацию на каждый символ в нашем слове
    {
        CodeHash = k * CodeHash + (int)i; // хешируем
    }
    return abs(CodeHash % HashTableSize); // возвращием хеш
}

int main() 
{
    ifstream fin("map.in");
    ofstream fout("map.out");
    string Command;
    while (fin >> Command)
    {
        if (Command == "put") // ввести элемент в хеш-таблицу
        {
            string key, value; 
            fin >> key >> value; // вводим ключ и его значение
            long i = GetHash(key); // хешируем
            int b = Search(HashTable[i], key); // ищем индекс элемент в векторе
            if (!HashTable[i].empty() && HashTable[i][b].first == key) // если вектор не пустой и наш элмент совпадает с ключом
                HashTable[i][b].second = value; // записываем знеачение
            if (HashTable[i].empty() || HashTable[i][b].first != key) // если наш вектор пуст или нашего ключа в нём нет
                HashTable[i].emplace_back(key, value); // записываем ключ-значение в конец вектора(emplace_back - запись в конец вектора)
        }
        else if (Command == "delete")
        {
            string key;
            fin >> key; // вводим ключ
            long i = GetHash(key); // хешируем
            int b = Search(HashTable[i], key); // ищем индекс элемент в векторе
            if (!HashTable[i].empty() && HashTable[i][b].first == key) // если вектор не пустой и наш элмент совпадает с ключом
            {
                swap(HashTable[i][b], HashTable[i][HashTable[i].size() - 1]); // меняем местами наш элемент с последним, потому что pop_back удаляет последний эл. в векторе
                HashTable[i].pop_back(); // удаляем его
            }
        }
        else if (Command == "get")
        {
            string key;
            fin >> key; // вводим ключ
            long i = GetHash(key); // хешируем
            int b = Search(HashTable[i], key); // ищем индекс элемент в векторе
            if (!HashTable[i].empty() && HashTable[i][b].first == key) // если вектор не пустой и наш элмент совпадает с ключом
            {
                fout << HashTable[i][b].second << '\n'; // выводим значение, прнодлежащие этому ключу
            }
            else 
            {
                fout << "none\n";
            }
        }
    }
    return 0;
}