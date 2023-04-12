// 11 стек.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
struct stack {
	int data;
	stack* prev;
};

stack* push(stack*& head, int val) {
	stack* p = new stack;
	p->data = val;
	p->prev = head;
	head = p;
	return head;
}

stack* makeStack(int n) {
	stack* head = nullptr;
	for (int i = 1; i <= n; i++) {
		head = push(head, i);
	}return head;
}

int printStack(stack* head) {
	int count = 0;
	stack* a = head;
	if (a == nullptr) {
		cout << "список пуст";
		return 0;
	}
	while (a != nullptr) {
		cout << a->data << " ";
		a = a->prev;
		count++;
	}
	return count;
}

int pop(stack*& head) {
	stack* p = head;
	stack* t = p->prev;
	int temp = p->data;
	head = t;
	delete p;
	return temp;
}

int printStack2(stack*& st) { // печать стека в правильном порядке
	int count = 0;
	int data;
	stack* current = st;
	stack* st2 = makeStack(0);
	if (current == nullptr) {
		cout << "список пуст";
		return 0;
	}
	while (current != nullptr) { //переписываем весь стек st в стек st2 (в обратном порядке)
		data = pop(st);
		push(st2, data);
		current = st;
	}
	current = st2;
	while (current != nullptr) {
		data = pop(st2);
		cout << data << " ";
		push(st, data);
		count++;
		current = st2;
	}
	return count;
}

void popEl(int k, int pos, int len, stack*& st) {
	stack* current = st;
	int data;
	stack* st2 = makeStack(0);
	for (int i = 1; i <= len - pos - k + 1; i++) {
		current = st;
		data = pop(st);
		push(st2, data);
	}
	for (int j = 1; j <= k; j++) {
		pop(st);
	}
	while (st2 != nullptr) {
		data = pop(st2);
		push(st, data);
	}
	delete st2;
}

void Addval(stack*& st, int key, int number) {
	stack* st2 = makeStack(0);
	stack* current = st;
	int data;
	bool flag = 1;
	while (st != nullptr and flag == 1) {
		current = st;
		data = current->data;
		if (current->data == key) {
			pop(st);
			push(st2, data);
			push(st, number);
			flag = 0;
		}
		else {
			pop(st);
			push(st2, data);
		}
	}
	while (st2 != nullptr) {
		data = pop(st2);
		push(st, data);
	}
	if (flag == 1) {
		cout << "Элемента с ключом " << key << " не найдено" << endl;
	}
	delete st2;
}


int main() {
	setlocale(0, "ru");
	cout << "введите кол-во элементов: ";
	int n, p, k, pos, len, key, newkey;
	cin >> n;
	cout << "исходный стек: ";
	stack* st = makeStack(n);
	len = printStack2(st);
	cout << endl;
	cout << "Введите номер, с которого удалять: "; cin >> pos;
	cout << "введите кол - во удаляемых элементов : "; cin >> k;
	popEl(k, pos, len, st);
	cout << "Стек после удаления элементов: ";
	len = printStack2(st);
	cout << endl;
	cout << "Введите ключ, перед которым необходимо добавить элемент: "; cin >> key;
	cout << "Введите значение нового элемента: "; cin >> newkey;
	Addval(st, key, newkey);
	cout << "Стек после добавления элемента: ";
	len = printStack2(st);
	cout << endl;
	return 0;
}