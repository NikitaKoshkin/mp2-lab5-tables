#include "hash.h"
#include "ordered.h"
#include "unordered.h"

void main()
{
	UnorderedTable table;

	Polynomial p1, p10, p11, p2, p20, p21, p22, p3;
	p1.addMonom(2, 200);
	p10.addMonom(3, 100);
	p11.addMonom(4, 0);
	Polynomial p12 = p1 + p10 - p11;
    table.insert("p1", p12);

	p2.addMonom(1, 300);
    p20.addMonom(2, 200);
    p21.addMonom(1, 100);
    p22.addMonom(1, 0);
    Polynomial p23 = p2 - p20 + p21 - p22;
    table.insert("p2", p23);

    // Печать всей таблицы
    table.printTable();

    // Поиск полинома по ключу
    try 
    {
        Polynomial foundPoly = table.findByKey("p2");
        cout << "Found polynomial: ";
        foundPoly.print();
        cout << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }

    // Удаление полинома по ключу
    table.remove("p2");

    // Печать таблицы после удаления
    table.printTable();

    // Печать полинома по ключу
    try {
        table.printByKey("p1");
    }
    catch (const char* e) {
        cout << e << endl;
    }

    cout << "------\n";

    HashTable table_h(10);
    table_h.insert("poly1", p12);
    table_h.insert("poly2", p23);
    table_h.printTable(); // выводит всю таблицу
    table_h.remove("poly1");
    table_h.printTable(); // выводит таблицу после удаления


}