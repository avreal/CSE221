#include <iostream>

template<typename ElemType>
class Item {
private:
	int key;
	ElemType elem;

public:
	int *loco;
	Item(const int k=0, const ElemType& e = ElemType(), int* l=0)	: key(k), elem(e), loco(l){ } //constructor
	const int getKey() const { return key; }
	const ElemType& getElem() const { return elem; }
	void setKey(const int k) { key = k; }
	void setElem(const ElemType& e) { elem = e; }
	const int getLoc() const { return *loco; }

	bool operator<(const Item& i) { return elem < i.elem; }
	bool operator>(const Item& i) { return elem > i.elem; }
	bool operator==(const Item& i) { return elem == i.elem; }
};

template<typename ElemType>
class PQComp {
public:
	int operator()(const Item<ElemType>& e1,
		const Item<ElemType>& e2) {
			return e1.getKey() - e2.getKey();
	}
};
