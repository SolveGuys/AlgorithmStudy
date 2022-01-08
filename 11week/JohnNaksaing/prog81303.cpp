#include <string>
#include <vector>
#include <stack>
#include <set>

#include <iostream>

#define __USING_STL__ 1

struct node
{
	int num;
	node* next;
	node* prev;
public:
	node(int num) :num(num), next(nullptr), prev(nullptr) {}

	node* operator*() { return this; }
};

class double_ll
{
	node* head;
	node* tail;

public:

	node* find(int k);
	void insert(int val);
	void insert(node* node);
	node* erase(node* target);

	node* begin() { return head; }
	node* end() { return tail; }

	double_ll() : head(nullptr),tail(nullptr) {}
};

node* double_ll::find(int k)
{
	node* temp = head;
	do
	{
		if (temp->num == k) return temp;
		else temp = temp->next;
	} while (temp->next != nullptr);
	return nullptr;
}

//insert when initializing
void double_ll::insert(int val) 
{
	node* temp = new node(val);

	if (head == nullptr) head = temp;
	if (tail != nullptr) 
	{
		temp->prev = tail;
		tail->next = temp;
	}
	tail = temp;
}

//revert
void double_ll::insert(node* node) 
{
	if (node->prev == nullptr && node->next == nullptr) 
	{
		head = node;
		tail = node;
	}
	else if (node->prev == nullptr) 
	{
		node->next = head;
		head = node;
	}
	else if (node->next == nullptr) 
	{
		tail->next = node;
		tail = node;
	}	
	else 
	{
		node->prev->next = node;
		node->next->prev = node;
	}
}

node* double_ll::erase(node* target) 
{
	if (target == head) 
	{
		if(target->next)
			target->next->prev = nullptr;
		head = target->next;
	}
	else if (target == tail) 
	{
		if(target->prev)
			target->prev->next = nullptr;
		tail = target->prev;
		return tail;
	}
	else 
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
	}

	return target->next;
}

node* prev(node* iter, int offset = 1)
{
	while (offset--) iter = iter->prev;
	return iter;
}

node* next(node* iter, int offset = 1)
{
	while (offset--) iter = iter->next;
	return iter;
}


std::string solution(int n, int k, std::vector<std::string> cmd) {

#if __USING_STL__
	using table_ds = std::set<int>;
	using iterator = std::set<int>::iterator;
    using stack_ds = std::stack<int>;
	using std::prev;
	using std::next;

	std::cout << "from __USING_STL__" << '\n';
#else
    using table_ds = double_ll;
	using iterator = node*;
	using stack_ds = std::stack<node*>;


	std::cout << "from __USING_DOUBLEL_LL__\n";
#endif
    
	std::string answer(n, 'X');
	{
		table_ds table;

		for (int i = 0; i < n; i++)
		{
			table.insert(i);
		}

		iterator cursor = table.find(k);
		stack_ds stack_history;

		for (std::string query : cmd)
		{
			char control = query[0];

			switch (control)
			{
			case 'U':
			case 'D':
			{
				int X = std::stoi(query.substr(2));

				control == 'U' ? cursor = prev(cursor, X) : cursor = next(cursor, X);

				//std::cout << *cursor << ',';
				break;
			}
			case 'C':
            #if __USING_STL__        
				stack_history.push(*cursor);
            #else
                stack_history.push(cursor);   
            #endif
				cursor = table.erase(cursor);
            #if __USING_STL__
				if (cursor == table.end()) cursor = prev(cursor);
            #endif
				break;

			case 'Z':
			{
				auto revert = stack_history.top();
				stack_history.pop();
				table.insert(revert);
				break;
			}
			default:
				return "oops";
				break;
			}
		}

#if __USING_STL__
		for (int i : table) /*std::cout << i << ' ',*/ answer[i] = 'O';
#else
		iterator temp = table.begin();
		while (temp != nullptr) 
		{
			/*std::cout << i << ' ',*/ 
			int i = temp->num;
			answer[i] = 'O'; 
			temp = temp->next;
		}
#endif

	}
	return answer;
}
