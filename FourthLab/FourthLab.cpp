#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int N = 501;

void readText(char *s)
{
    short pick;
    cout << "Выберите способ ввода последовательности:\n1. Ввод с клавиатуры\n2. Ввод из файла\n";
    cin >> pick;
    if (pick == 1)
    {
        cout << "Введите последовательность из 50 слов, в каждом из которых от 1 до 10 латинских букв или цифр\n";
        cin.ignore();
        cin.getline(s, N);
    }
    else
    {
        cout << "Выполняется чтение строки из файла...\n";
        string FileName = "C:\\ЛЭТИ\\Программирование\\input.txt";
        ifstream File;
        File.open(FileName);
        if (!File.is_open())
        {
            cout << "Не удалось открыть файл";
        }
        while (!File.eof())
        {
            File.getline(s, N);
        }
        File.close();
    }

}

void deleteSymbol(char* s, int pos)
{
    s[pos] = ' ';
    for (int i = pos + 1; i < strlen(s); i++)
    {
        swap(s[i - 1], s[i]);
    }
}

void lineEditing(char* s)
{
    for (int i = 2; i < strlen(s); i++)
    {
        if (((s[i - 1] == ' ') || (s[i - 1] == 'э')) && ((s[i] == ' ') || (s[i] == 'э')))
        {
            s[i] = 'э';
        }
        if (((s[i - 1] == ',') || (s[i - 1] == ';') || (s[i - 1] == '-') || (s[i - 1] == '!') || (s[i - 1] == '?') || (s[i - 1] == 'ё')) && ((s[i] == ',') || (s[i] == ';') || (s[i] == '-') || (s[i] == '!') || (s[i] == '?') || (s[i] == 'ё')))
        {
            s[i] = 'ё';
        }
        if (((s[i - 2] == '.') && (s[i - 1] == '.') && (s[i] != '.')))
        {
            s[i - 1] = 'ё';
            s[i] = 'ё';
        }
        if ((s[i - 2] == '.') && (s[i - 1] != '.'))
        {
            s[i - 1] = 'ё';
        }
    }

    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == 'ё') || (s[i] == 'э'))
        {
            deleteSymbol(s, i);
            i--;
        }
    }

    for (int i = 1; i < strlen(s); i++)
    {
        if (s[i - 1] != ' ')
        {
            s[i] = tolower(s[i]);
        }
    }
}

void wordsWithSameLetters(char* s)
{
    int i = 0;
    char s1[11];
    while (i < strlen(s))
    {
        int k = 0;
        bool same = false;
        while ((s[i + k] != ' ') && (s[i + k] != ',') && (s[i + k] != ';') && (s[i + k] != '.') && (s[i + k] != '-') && (s[i + k] != '!') && (s[i + k] != '?'))
        {
            s1[k] = s[i + k];
            k++;
        }
        s1[k] = '\0';
        for (int j = 0; j < strlen(s1); j++)
        {
            for (int g = j + 1; g < strlen(s1); g++)
            {
                if (s1[j] == s1[g])
                {
                    same = true;
                    break;
                }
            }
        }
        if (same)
        {
            cout << s1 << ' ';
        }

        i = i + 1 + strlen(s1);
    }
}

void replaceNums(char* s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        switch (s[i])
        {
        case('1'):
            s[i] = 'a';
            break;
        case('2'):
            s[i] = 'b';
            break;
        case('3'):
            s[i] = 'c';
            break;
        case('4'):
            s[i] = 'd';
            break;
        case('5'):
            s[i] = 'e';
            break;
        case('6'):
            s[i] = 'f';
            break;
        case('7'):
            s[i] = 'g';
            break;
        case('8'):
            s[i] = 'h';
            break;
        case('9'):
            s[i] = 'i';
            break;
        case('10'):
            s[i] = 'j';
            break;
        default:
            break;
        }
    }
    cout << s;
}

void searchSubStr(char* s, char* smalls)
{
    int x = strlen(s);
    int y = strlen(smalls);
    bool isFind = false;
    for (int i = 0; i < x - y + 1; i++)
    {
        int j;
        for (j = 0; j < y; j++)
        {
            if (s[i + j] != smalls[j])
            {
                break;
            }
        }
        if (j == y)
        {
            cout << "Искомая подстрака найдена, индекс: " << i << '\n';
            isFind = true;
        }
    }
    if (!isFind)
    {
        cout << "Искомая подстрака не найдена\n";
    }
}

int main()
{
    setlocale(0, "");
    char line[N];
    readText(line);
    cout << "Ваша строка:\n";
    cout << line << '\n';
    short menu;
    while (true)
    {
        cout << "\n2. Редактирование исходного текста\n3. Вывести на экран только те слова последовательности, в которых встречаются одинаковые буквы\n4. Вывести на экран ту же последовательность, заменив во всех словах цифры на буквы латинского алфавита, номера которых в алфавите равны заменяемой цифре\n5. Найти все вхождения подстроки в строку\n0. Выход\n";
        cin >> menu;
        switch (menu)
        {
        case(2):
            cout << "\nВторое задание\n";
            lineEditing(line);
            cout << line << '\n';
            break;
        case(3):
            cout << "\nТретье задание\n";
            wordsWithSameLetters(line);
            cout << '\n';
            break;
        case(4):
            cout << "\nЧетвертое задание\n";
            replaceNums(line);
            cout << '\n';
            break;
        case(5):
            cout << "\nПятое задание\n";
            char subline[N];
            cout << "Введите текст, который хотите найти\n";
            cin.ignore();
            cin.getline(subline, N);
            searchSubStr(line, subline);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}