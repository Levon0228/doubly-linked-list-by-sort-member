#include <iostream>
template <typename T>
class List 
{
public:
	List():m_head ( nullptr), m_size(0) {};
	struct Node {
		T value;
		Node* next;
		Node* prev;
		Node():next(nullptr), prev(nullptr) {};
	};
	void insert (int pos, const T& value);
	void remove (int pos);
	void sort();
	void print();
private:
	Node* m_head;
	int m_size;
};

int main () {
	List<int> list;
	list.insert(0,2);
	list.insert(0, 4);
	list.insert(0,3);
	list.insert(0, 1);
	list.insert (0, 8);
	list.insert(3, 22);
	list.insert(1,15);
	list.insert(3,33);
//	list.remove(3);
	list.sort();


}
template<typename T>
void List<T>::insert(int pos, const T& value) {
	if(pos > m_size) {
		std::cout << "Range error!!!" << std::endl;
		return;
	}else if (pos == 0) {
		Node* tmp = new Node();
		tmp->value = value;
		tmp->next = m_head;
		tmp->prev = nullptr;
		if (m_head != nullptr) {
      			 m_head->prev = tmp;
    		}	
		m_head = tmp;
		Node* curr = m_head;
		++m_size;	
	}else if (pos == m_size) {
		Node* curr = m_head;
		Node* tmp = new Node();
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		tmp->prev = curr;
		tmp->next = nullptr;
		curr->value = value;
		++m_size;
	} else {
  		Node* curr = m_head;
		int count = 1;
		while (count < pos) {
			curr = curr->next;
			++count;
		}
		Node* tmp= new Node();	
		tmp->value = value;
		tmp->next = curr->next;
		tmp->prev = curr;
		curr->next = tmp;
		++m_size;
	}
}
template<typename T>
void List<T>::remove(int pos) {
	if(pos > m_size-1 || pos < 0) {
		std::cout << "error!!!" <<std::endl;
		return;
	}else if (pos == 0) {
		Node* curr = m_head;
		m_head = m_head->next;
		m_head->prev = nullptr;
		delete curr; 
		--m_size;
	} else if(pos == m_size - 1) {
		Node* curr = m_head;
		while(curr->next != nullptr) {
			curr = curr->next;
			}
		curr->prev->next = nullptr;
		delete curr;
		--m_size;
		} else {
		Node* curr = m_head;
		int count = 1;
		while(count < pos) {
			curr = curr->next;
			++count;
		}
		curr->next->prev = curr->prev;
		curr->prev->next = curr->next;
		delete curr;
		--m_size;
		}
	
}

template<typename T>
void List<T>::print() {
	int count = 0;
	Node* curr = m_head;
	while (curr != nullptr) {
		std::cout<<curr->value<<std::endl;
		curr = curr->next;
	}

}


template<typename T>
void List<T>::sort() {
	int k = 0;
	Node* curr = m_head;
	Node* iter;
	while(k < m_size - 1) {
		iter = curr->next;
		curr = m_head;
		//T tmp = carr->val;
		int n = 0;
		++k;
		while(n < k) {
			T tmp = curr->value;
		
			if ( iter->value < curr->value) {
				curr->value = iter->value;
				iter->value = tmp;
			}
			++n;
			curr = curr->next;



	
		}
	}
	print();
}
