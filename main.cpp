#include"hash.h"
using namespace std;

char keys[MAX_DATA][MAX_KEY]; // ���ڿ� key��
int values[MAX_DATA]; // key�� �����ϴ� ����

int main(void) {

	HASH_MAP map;
	int result;

	map.add("Gildong", 11111111);
	map.add("HiDong", 22222222);
	map.add("Doolri", 3333333);
	map.add("douneo", 4444444);
	map.add("DDochi", 5555555);
	map.add("Michol", 6666666);
	map.add("chulsoo", 77777777);
	map.add("younghi", 88888888);


	cout << map << endl;

	//find

	if (map.find("Gildong", result)) cout <<"Gildong�� ��ȭ��ȣ�� 010"<< result << endl;;

	if (map.destroy("chulsoo")) {
		cout << "�����Ϸ�" << endl;
		cout << map << endl;
	}
	else {
		cout << "key���� �ش��ϴ� value�� �����" << endl;
		cout << map << endl;
	}

	return 0;

}