#include <iostream>

class node {
	int element;
	node* next;

public:
	node() {};
	int Getvalue() { return element; }
	node* GetLink() { return next; }
	void SetValue(int val) { element = val; }
	void SetLink(node* l) { next = l; }
};

class linked_list
{
	node* m_head;

public:

	linked_list::linked_list()
	{
		m_head = nullptr;
	}

	linked_list::linked_list(node* h)
	{
		m_head = h;
	}

	node* Start()
	{
		return m_head;
	}

	node* End()
	{
		node* head = m_head;
		while (head != nullptr)
		{
			if (head->GetLink() == nullptr)
				return head;

			head = head->GetLink();
		}

		return head;
	}

	void Print()
	{
		node* head = Start();
		while (head)
		{
			std::cout << head->Getvalue() << " --->  ";
			head = head->GetLink();
		}
		std::cout << "\n";
	}

	void Insert(int value)
	{
		node* item = new node();
		item->SetValue(value);
		item->SetLink(nullptr);

		node* pointer = Start();
		if (pointer == nullptr)
		{
			pointer = item;
			m_head = pointer;
			return;
		}

		pointer = End();
		pointer->SetLink(item);
	}

	void Delete(int value)
	{
		node* pointer = Start();
		if (pointer == nullptr)
			return;

		node* previous_pointer = nullptr;
		while (pointer)
		{
			if (pointer->Getvalue() == value)
			{
				if (pointer == Start())
				{
					m_head = pointer->GetLink();
					return;
				}

				previous_pointer->SetLink(pointer->GetLink());
				delete pointer;
				return;
			}
			previous_pointer = pointer;
			pointer = pointer->GetLink();
		}
	}
};

int main()
{
	linked_list list;
	list.Insert(200);
	list.Insert(50);
	list.Insert(500);
	list.Insert(100);
	list.Insert(10);
	list.Print();
	list.Delete(100);
	list.Print();
	list.Insert(23);
	list.Delete(200);
	list.Delete(50);
	list.Print();
	system("pause");
	return 0;
}