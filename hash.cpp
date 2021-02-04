#include "hash.h"
using namespace std;

int hash_function(const char* str) {
// 해시 함수
	int hash = 401;
	int c;

	while (*str != NULL) {
		hash = ((hash << 4) + (int)(*str)) % MAX_TABLE;
		str++;
	}

	return hash % MAX_TABLE;
}

ostream& operator<<(ostream& os, HASH_MAP& map) {
//해시 테이블 전체 출력
	for (int i = 0; i < MAX_TABLE; ++i) {
		if (map.HASH_TABLE[i] != NULL) {

			os << "index: " << i << endl;

			HASH_NODE* cur = map.HASH_TABLE[i];

			while (cur != NULL) {
				os << "{" << cur->key << ", " << cur->value << "} ";
				cur = cur->next;
			}
			cout << endl;
		}
	}

	return os;
}

HASH_MAP::HASH_MAP() {

	for (int i = 0; i < MAX_TABLE; i++) {
		HASH_TABLE[i] = NULL;
	}

}


void HASH_MAP::add(const char* the_key, int the_value) {
	//새로운 <key,value> 추가
	int index = hash_function(the_key); //index에 해시 적용

	if (this->HASH_TABLE[index] == NULL) {
		this->HASH_TABLE[index] = new HASH_NODE(the_key, the_value, NULL);
	}
	else {
		HASH_NODE* cur = this->HASH_TABLE[index];
		while (cur != NULL) {
			//key값 중복 시 값만 변경
			if (!strcmp(cur->key, the_key)) {
				cur->value = the_value;
				return;
			}
			cur = cur->next;
		}
		//중복이 아닐 시 맨 앞에 추가
		this->HASH_TABLE[index] = new HASH_NODE(the_key, the_value, this->HASH_TABLE[index]);

	}

}

bool HASH_MAP::find(const char* the_key, int& result) {
	//해당 key값에 value가 있는지 확인하고 있으면 result에 반환

	int index = hash_function(the_key);

	HASH_NODE* cur = this->HASH_TABLE[index];

	while (cur != NULL) {
		//cur->key와 the_key비교
		if (!strcmp(cur->key, the_key)) {
			result = cur->value;
			return true;
		}
		cur = cur->next;
	}

	return false;

}

bool HASH_MAP::destroy(const char* the_key) {
	//해당 key에 value가 있으면 삭제 있으면 true 반환 없으면 false 반환
	int index = hash_function(the_key);

	if (this->HASH_TABLE[index] == NULL) return false;

	HASH_NODE* cur = this->HASH_TABLE[index];
	if (!strcmp(cur->key, the_key)) {
		this->HASH_TABLE[index] = cur->next;
		delete cur;
		return true;
	}
	else {
		while (cur) {
			if (!strcmp(cur->key, the_key)) {
				cur->next = cur->next->next;
				delete cur;
				return true;
			}
			cur = cur->next;
		}
	}


	return false;
}