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
	linked_list list; int choice , variable; char exit = 'y';

	while (exit == 'y' || exit == 'Y')
	{
		std::cout << "\nWhat do you want to do?\n";
		std::cout << "1. Insert\n2. Delete\n3. Print\n";
		std::cin >> choice;

		if (choice == 1)
		{
			std::cout << "\n" << "What number do you want to insert?";
			std::cin >> variable;
			list.Insert(variable);
		}

		if (choice == 2)
		{
			std::cout << "\n" << "What number do you want to delete?";
			std::cin >> variable;
			list.Delete(variable);
		}

		if (choice == 3) list.Print();

		std::cout << "Do you want to continue with more list operations? Y/N?\n";
		std::cin >> exit;
	}
	system("pause");
	return 0;
}