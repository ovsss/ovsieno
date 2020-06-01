#include <cstdlib>
//#include "windows.h"
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
//#pragma hdrstop

// Структура:
struct tree
{
    string eng;     //англійське слово
     string rus;     //російський переклад
      int count;      //кількість звернень
       tree *left;
        tree *right;
};
string temp_eng;
 string temp_ukr;
  int temp_count;
   int level = 0;
 
// створення першого елемента
 tree *first(string eng, string rus, int count);
 // функція пошуку елементів
  tree *search_insert(tree *root, string eng, string rus, int count);
   //вивід дерева
 void print_tree(tree *p, int level);
 
  int main()
{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
 
    int choice;
     tree *root = NULL;
      do {
        cout << "Оберіть: " << endl;
         cout << "1) Додати слово до словника" << endl;
          cout << "2) Вихід" << endl;
           cout << "3) Вивести дерево на консоль" << endl;
            cout << "4) Шукати переклад англійського слова" << endl;
             cout << "5) Видалити слово зі словника" << endl;
        cin >> choice;
         switch (choice)
         {
          case 1: {cout << "Введіть англійське слово: " << endl;
            cin >> temp_eng;
             cout << "Введіть українське слово: " << endl;
              cin >> temp_ukr;
               cout << "Введіть значення лічильника: " << endl;
                cin >> temp_count;
            //перший елемент дерева
              if (!root) root = first(temp_eng, temp_ukr, temp_count);
            else root = search_insert(root, temp_eng, temp_ukr, temp_count);
 
        };
                break;
        case 2:
                 return 0;
               break;
        case 3:
                 print_tree(root, 0);
              break;
        default:
                 cout << "Натисніть клавішу від 1 до 5" << endl;
            break;
        }
    }
 
    while (choice != 3);
    system("pause");
    return 0;
}
 
//функція формування першого елемента дерева
tree *first(string temp_eng, string temp_ukr, int count)
{
    tree *pv = new tree;
     pv->eng = temp_eng;
      pv->rus = temp_ukr;
       pv->count = temp_count;
        pv->left = 0;
         pv->right = 0;
      return pv;
}
// функція пошуку і додавання елемента в дерево:
 tree *search_insert(tree *root, string temp_eng, string temp_ukr, int temp_count)
{
    
    tree *pv = root, *prev;
     bool found = false;
      //пошук по дереву
        prev = pv;
    while (pv && !found) {
    
        if (temp_eng == pv->eng) found = true;
         else if (temp_count < pv->count) pv = pv->left;
          else pv = pv->right;
    }
    if (found) return pv;
     tree *pnew = new tree;
      pnew->eng = temp_eng;
       pnew->rus = temp_ukr;
        pnew->count = temp_count;
         pnew->left = 0;
          pnew->right = 0;
    if (temp_count < prev->count) prev->left = pnew;
     else prev->right = pnew;
    return pnew;
}
// вивід дерева
void print_tree(tree *p, int level)
{
    if (p)
    {
        print_tree(p->left, level + 1);
         for (int i = 0; i<level; i++)
            cout << "   ";
        cout << p->eng;
         for (int i = 0; i<level; i++)
            cout << "   ";
        cout << p->rus;
         for (int i = 0; i<level; i++)
            cout << "   ";
        cout << p->count;
         print_tree(p->right, level + 1);
    }
}
