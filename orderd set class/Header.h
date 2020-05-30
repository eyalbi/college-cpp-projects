#include <iostream>
#include <string>
#define ZERO 0
#define ONE 1
using namespace std;
class OrderedSet {				//����� �� �����
private:						//	����� ����� ����� �� ����� ������ ��������� ���
	int * Group;
	int Size;
	void Sort_G(int *, int);		//������� ����� ���� ������
	bool Orderd_G(int *, int);			//�������� ������ �� ���� �����
	int ReturningValue(int * group, int size);			//�������� ������ �� ���� ������ ������� �����
	bool inArray(int*, int, int);					//������� ������ �� ���� ��� ���� �����
	int SameValues(OrderedSet obj);					//������� ������ ���� ����� ������ ��� ��� ������ �����

public:
	OrderedSet() : Group(NULL), Size(ZERO) {} //���� ��������
	OrderedSet(int *group, int size);			//���� �� ������
	OrderedSet(const OrderedSet & obj);			// ���� �����
	~OrderedSet() { delete[] Group; }				// ���� ������ �� �������
	int *Get_Group() { return Group; }					//�������� ����� ����� �����
	int Get_Size() { return Size; }
	bool Contain(int);									//������� ������ �� ���� ��� ����� ������ ������
	void ChangeGroup(int * group, int size);		// ����� ����� ����� ����� ������ ��� ��������(�� �� ����� ������ ����� ������ 
	OrderedSet Def(OrderedSet obj);						//�������� ������ ���� ��� ������
	OrderedSet intersect(OrderedSet obj);				// �������� ������ ����� ��� ������
	OrderedSet Union(OrderedSet obj);						// �������� ������ ����� �� ������
	bool EqualGroups(OrderedSet obj);						// �������� ������ �� ������ ����
	bool EmptyGroup();										//������� ������ �� ����� ��� ������ �����
	bool Contain(OrderedSet obj);							//�������� ������ �� ����� ��� ����� �� ������ 
	void PrintGroup();		//�������� ������� �����
	
};