
#include <exception>
#include <iostream>
#include "List.h"
#include <fstream>
#include <vector>

using namespace std;

void Task_1(MyList &list, const vector<int>& vals)
{
	int sm = 0;
	for (int i =0; i<vals.size();i++)
	{
		list.Del(vals[i]-sm);
		sm++;
	}
	
}


bool Task_2(MyList &list)
{
	
	MyList* temp = list.GetHead();
	for(MyList *l1 = temp; l1 != list.GetTail(); l1 = l1->GetNext())
	{
		for(MyList *l2 = l1->GetNext(); l2!= list.GetTail(); l2 = l2->GetNext())
		{
			if (l1->Get_x() == l2->Get_x()) return true;
			
		}
	}
	return false;


}

int main()
{
	setlocale(LC_ALL, "Russian");
	int k, val;
	vector<int> vals;
	MyList lst;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	cout << "Какое число нужно удалить из списка? : ";
	cin >> val;
	while (fin >> k)
	{
		lst.Add(k);
		if (k == val)
		{
			vals.push_back(lst.GetCount());
		}
	}

	bool tr = Task_2(lst);
	Task_1(lst, vals);
	lst.Show(fout);
	if (tr)
		fout << "Есть одинаковые элементы";
	else
	{
		fout << "Одинаковых элементов не найдено";
	}
	return 0;
}
