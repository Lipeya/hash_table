#pragma once
#ifndef __HASH___
#define __HASH___
#include <iostream>
#include <string>
using namespace std;

#define MAX_TABLE 5 // ���̺� ũ��
#define MAX_KEY 8 // include null
#define MAX_DATA 12 // �ؽ����̺� ���� �������� ��
#define DELETE_COUNT 6 // ������ �������� ��
#define FIND_COUNT 8 // ã�� �������� ��

//collision ��� : ��ũ�� ����Ʈ. �ܹ��� ��ũ�� ����Ʈ ���

struct HASH_NODE{
	char key[MAX_KEY];
	int value;
	HASH_NODE* next;
	HASH_NODE(const char* the_key, int the_value, HASH_NODE* the_next =NULL): value(the_value) {
		strcpy(this->key, the_key);
		this->next = the_next;
	}
};

int hash_function(const char*);

class HASH_MAP {
	friend class HASH_NODE;
	friend int hash_function(const char*);
	friend ostream& operator<< (ostream&, HASH_MAP&);
private:
	HASH_NODE* HASH_TABLE[MAX_TABLE];//�ؽ� ���̺�
public:
	HASH_MAP();
	void add(const char*, int);
	bool find(const char*, int&);
	bool destroy(const char*);
};

#endif