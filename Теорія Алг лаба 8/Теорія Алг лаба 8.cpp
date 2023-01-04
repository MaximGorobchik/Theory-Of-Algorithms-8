#include "Tree.h"
#include <Windows.h>
#include <ctime>
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	Tree* Root = 0;
	int n, k, element, del;
	cout << "Введіть кількість елементів у дереві: "; cin >> n; cout << endl;
	for (int i = 0; i < n; i++)
	{
		Root->AddToTree(rand() % 100, Root);
	}
	Root->PrintTree(Root, 5);
	cout << endl << "Обхід дерева: ";
	Root->ByPassTree(Root); cout << endl;
	cout << "Мінімальний елемент: "; cout << Root->Search_Min(Root); cout << endl;
	cout << "Максимальний елемент: "; cout << Root->search_max(Root) << endl;
	cout << "Сума елементів: "; cout << Root->Sum(Root);
	cout << endl << "Елемент для входження: "; cin >> k; cout << endl << "Кількість входжень : "; cout << Root->Entering(Root, k);
    cout << endl << "Елемент для видалення: "; cin >> del; Root->Delete(Root,del);
	Root->PrintTree(Root, 0);
	Root->FreeTree(Root);
}
