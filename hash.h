#pragma once
#ifndef __HASH___
#define __HASH___
#include <iostream>
#include <string>
using namespace std;

#define MAX_TABLE 5 // 테이블 크기
#define MAX_KEY 8 // include null
#define MAX_DATA 12 // 해시테이블에 넣을 데이터의 수
#define DELETE_COUNT 6 // 삭제할 데이터의 수
#define FIND_COUNT 8 // 찾을 데이터의 수

//collision 대비 : 링크드 리스트. 단방향 링크드 리스트 사용

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
	HASH_NODE* HASH_TABLE[MAX_TABLE];//해시 테이블
public:
	HASH_MAP();
	void add(const char*, int);
	bool find(const char*, int&);
	bool destroy(const char*);
};

#endif