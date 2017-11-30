#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct Pattern
{
	string name;
	int num;	
};

class PatternArray
{
	Pattern *arr;
	int last;
public:
	PatternArray(int size)
	{
		arr = new Pattern[size];
		last = 0;
	}
	int exist(string _name)
	{
		if (last == 0)
			return -1;
		else
		{
			for (int i = 0; i < last; i++)
			{
				if (arr[i].name == _name) return i;
			}
		}
		return -1;
	}
	void push(string _name)
	{
		int place = exist(_name);
		if (place < 0)
		{
			arr[last].name = _name;
			arr[last].num = 1;
			last++;
		}
		else
		{
			arr[place].num++;
		}
	}
	string findFreqWord()
	{
		if (last == 0) throw "Text is empty";
		else
		{
			int maxnum = 0;
			string s;
			for (int i = 0; i < last; i++)
			{
				if (arr[i].num > maxnum)
				{
					maxnum = arr[i].num;
					s = arr[i].name;
				}
				else if (arr[i].num == maxnum)
				{
					s += " ";
					s += arr[i].name;
				}

			}
			return s;
		}
		return 0;
	}
	~PatternArray()
	{
		delete[] arr;
	}
};

string FrequentWords(string Text, int k)
{
	int m = Text.length(); // размер текста
	PatternArray pa(m - k + 1);
	for (int i = 0; i < m - k + 1; i++)
		pa.push(Text.substr(i, k));
	return pa.findFreqWord();	
}

int main() {
	//считываем по строкам из файла  /////////
	string *s;
	s = new string[2];
	ifstream fin("input.txt", ios_base::in);
	for (int i = 0; i < 2; i++) {
		getline(fin, s[i]);
	}
	// вывод
	for (int i = 0; i < 2; i++) {
		cout << "s = " << s[i] << endl;
	}
	
	int k = stoi(s[1]);  
	//////////////////////////////////////////


	// 
	

	string result = FrequentWords(s[0], k);

	cout << "Result: " << result << endl;

	// записываем результат в файл   ////////////////////////////
	ofstream fout("output.txt", ios_base::out | ios_base::trunc);
	fout << result;
	fout.close();
	/////////////////////////////////////////////////////////////
	delete[] s;
}