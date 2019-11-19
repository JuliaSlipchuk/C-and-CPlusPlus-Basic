
#include <iostream>

using namespace std;

class Node
{
public:
	Node(int val);
	int value;
	~Node();
	Node* next;
	Node* prev;
};
Node::Node(int val) : value(val), next(nullptr), prev(nullptr)
{
	cout << "+Node" << endl;
}
Node::~Node()
{
	cout << "-Node" << endl;
}
class List
{
public:
	List();
	List(List &list);
	void push_front(int value);
	bool pop_front(int value);
	Node* search(int value);
	Node* previous(Node* node);
	int size();
	void push_back(int value);
	bool pop_back(int value);
	int at(int index);
	void insert_at(int index, int value);
	void remove_at(int index);
private:
	Node* head;
	Node* tail;
};
//List::List() : head(nullptr)
//{
//}
List::List() : head(nullptr), tail(nullptr)
{
}
List::List(List &list) : head(nullptr), tail(nullptr)
{
	for (int i = 0; i < list.size(); i++)
	{
		this->push_back(list.at(i));
	}
}
void printList(List list)
{
	for (int i = 0; i < list.size(); i++)
	{
		cout << "list[" << i << "] == " << list.at(i) << endl;
	}
}
int List::at(int index)
{
	int ind = 0;
	Node* node = this->head;
	while (node != nullptr)
	{
		if (ind == index)
		{
			return node->value;
		}
		node = node->next;
		ind++;
	}
	return -1;
}
void List::insert_at(int index, int value)
{
	Node* newNode = new Node(value);
	int nextIndex = this->size();
	if (index == 0)
	{
		Node* thisHead = search(this->head->value);
		if (thisHead != nullptr)
		{
			newNode->next = thisHead;
			thisHead->prev = newNode;
			this->head = newNode;
		}
		else
		{
			this->head = newNode;
			this->tail = newNode;
		}
	}
	else if (index == nextIndex)
	{
		Node* thisTail = search(this->tail->value);
		if (thisTail != nullptr)
		{
			thisTail->next = newNode;
			this->tail = newNode;
			this->tail->prev = thisTail;
		}
		else
		{
			this->head = newNode;
			this->tail = newNode;
		}
	}
	else if (index > 0 && index < nextIndex)
	{
		int prevValue = this->at(index - 1);
		Node* prev = search(prevValue);
		int currValue = this->at(index);
		Node* currNode = search(currValue);
		currNode->prev = newNode;
		newNode->next = currNode;
		newNode->prev = prev;
		prev->next = newNode;
	}
	else
	{
		cout << "You entered the index not at the range of the list";
	}
}
void List::remove_at(int index)
{
	int indexLastElem = this->size() - 1;
	if (index == 0)
	{
		int thisValue = this->at(0);
		Node* thisNode = search(thisValue);
		int nextValue = this->at(1);
		if (nextValue != -1)
		{
			Node* nextNode = search(nextValue);
			nextNode->prev = nullptr;
			this->head = nextNode;
		}
		else
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		delete thisNode;
	}
	else if (index == indexLastElem)
	{
		int thisValue = this->at(indexLastElem);
		Node* thisNode = search(thisValue);
		int prevValue = this->at(indexLastElem - 1);
		if (prevValue != -1)
		{
			Node* prevNode = search(prevValue);
			prevNode->next = nullptr;
			this->tail = prevNode;
		}
		else
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		delete thisNode;
	}
	else if (index > 0 && index < indexLastElem)
	{
		int thisValue = this->at(index);
		Node* thisNode = search(thisValue);
		int prevValue = this->at(index - 1);
		Node* prevNode = search(prevValue);
		int nextValue = this->at(index + 1);
		Node* nextNode = search(nextValue);
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		delete thisNode;
	}
	else
	{
		cout << "You entered the index not at the range of the list";
	}
}
int List::size()
{
	int res = 0;
	Node* node = this->head;
	while (node != nullptr)
	{
		res++;
		node = node->next;
	}
	return res;
}
bool List::pop_back(int value)
{
	Node* currNode = this->search(value);
	if (currNode != nullptr)
	{
		Node* prev = previous(currNode);
		if (prev != nullptr)
		{
			this->tail = prev;
		}
		else
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		currNode->~Node();
		return true;
	}
	return false;
}
void List::push_front(int value)
{
	Node* new_head = new Node(value);
	Node* prevHead = search(this->head->value);
	prevHead->prev = new_head;
	new_head->next = prevHead;
	head = new_head;
	if (this->size() == 1)
	{
		tail = new_head;
	}
}
void List::push_back(int value)
{
	Node* node = new Node(value);
	if (tail != nullptr)
	{
		Node* taill = search(tail->value);
		taill->next = node;
		node->prev = taill;
		this->tail = node;
	}
	else
	{
		head = node;
		tail = node;
	}
}
Node* List::search(int value)
{
	Node* node = this->head;
	while (node != nullptr)
	{
		if (node->value == value)
		{
			return node;
		}
		node = node->next;
	}
	return nullptr;
}
Node* List::previous(Node* node)
{
	Node* prev = this->head;
	while (prev != nullptr)
	{
		if (prev->next == node)
		{
			return prev;
		}
		prev = prev->next;
	}
	return nullptr;
}
bool List::pop_front(int value)
{
	Node* currNode = this->search(value);
	if (currNode != nullptr)
	{
		Node* prev = previous(currNode);
		int nextValue = this->at(1);
		if (nextValue != -1)
		{
			Node* nextNode = search(nextValue);
			if (prev != nullptr)
			{
				nextNode->prev = prev;
				prev->next = currNode->next;
			}
			else
			{
				nextNode->prev = nullptr;
				this->head = currNode->next;
			}
		}
		delete currNode;
		return true;
	}
	return false;
}
int main()
{
	// twenty part

	List list1;
	list1.push_back(5);
	list1.push_back(8);
	list1.push_back(18);
	list1.push_back(9);
	printList(list1);

	list1.pop_front(8);
	printList(list1);

	list1.insert_at(2, 97);
	printList(list1);

	list1.remove_at(0);
	printList(list1);
	return 0;
}

