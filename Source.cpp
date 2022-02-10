#include <iostream>
#include <ctime>
#include "myconsole.h"
#include "mygraphics.h"

using namespace std;

class linklist
{
	class node 
	{
	public:
		node* next;
		int i;
		int j;
		int val;
		friend class linklist;
		node()
		{
			next = nullptr;
			i = 0;
			j = 0;
			val = 0;
		}

		~node()
		{
			next = nullptr;
			i = 0;
			j = 0;
			val = 0;
		}
	};
private:
	node* head;
public:
	friend class stack;
	linklist()
	{
		head = nullptr;
	}

	void insert_at_tail(int i, int j,int val)
	{
		if (head == nullptr)
		{
			node* n = new node;
			n->next = nullptr;
			n->i = i;
			n->j = j;
			n->val = val;
			head = n;
		}
		else if(head->next == nullptr)
		{
			node* n = new node;
			n->next = nullptr;
			n->i = i;
			n->j = j;
			n->val = val;
			head->next = n;
			
		}
		else
		{
			node* curr = head;
			while (curr-> next != nullptr)
			{
				curr = curr->next;
			}

			node* n = new node;
			n->next = nullptr;
			n->i = i;
			n->j = j;
			n->val = val;

			curr->next = n;

		}
	}

	void remove_From_Tail()
	{
		if (head != nullptr)
		{
			if (head->next == nullptr)
			{
				head = nullptr;
			}
			else
			{
				node* curr = head;
				node* temp = head;
				while (curr->next != nullptr)
				{
					curr = curr->next;
					if (curr->next != nullptr)
					{
						temp = temp->next;
					}
				}

				temp->next = nullptr;
				delete curr;

			}
		}
	}

	void print()
	{

		if(head != nullptr)
		{
			if (head->next == nullptr)
			{
				cout << "i is : " << head->i << " j is : " << head->j << " val is : " << head->val << endl;
			}
			else
			{
				node* curr = head;
				while (curr != nullptr)
				{
					cout << "i is : " << curr->i << " j is : " << curr->j << " val is : " << curr->val << endl;
					curr = curr->next;
				}
			}
		}
		
	}

	void top(int& i, int& j, int& val)
	{
		if (head != nullptr)
		{
			node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			i = curr->i;
			j = curr->j;
			val = curr->val;
		}
	}

	bool is_emp()
	{
		if (head == nullptr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	~linklist()
	{
		node* current = head;
		while (current != nullptr) 
		{
			node* next = current->next;
			delete current;
			current = next;
		}
		head = 0;
		cout << "\nDESTRUCTOR CALLED";
	}
};

class stack
{
private:
	linklist l;
public:
	void push(int i,int j, int val)
	{
		l.insert_at_tail(i,j,val);
	}
	void pop()
	{
		l.remove_From_Tail();
	}
	void s_data(int& i, int& j, int& val)
	{
		l.top(i, j, val);
	}
	void show()
	{
		l.print();
	}
	bool is_emp()
	{
		if (l.is_emp())
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

stack s;
void show(int**& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void allocate(int **&arr, int size)
{
	srand(time(0));
	arr = new int*[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = 0;
		}
	}


	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 2;
		}
		i++;
	}
}

void movement(int**& arr, int size, int i, int j,int x , int y)
{
	int val = 1;
	int flag = 0;
	int t_i = 0;
	int t_ii = 0;
	s.push(i, j, 1);
	while (arr[i][j] != arr[x][y] && s.is_emp() != 1)
	{

		if (j + 1 < size && arr[i][j + 1] != 1 && arr[i][j + 1] != 4 && arr[i][j + 1] != 2)
		{
						j++;
						s.push(i, j, 1);
						arr[i][j] = 4;
		}
		else if (i + 1 < size && arr[i + 1][j] != 1 && arr[i + 1][j] != 4 && arr[i + 1][j] != 2)
		{
					i++;
					s.push(i, j, 1);
					arr[i][j] = 4;
		}
		else if (j - 1 >= 0 && arr[i][j - 1] != 1 && arr[i][j - 1] != 4 && arr[i][j - 1] != 2)
		{
					j--;
					s.push(i, j, 1);
					arr[i][j] = 4;
		}
		else if (i - 1 >= 0 && arr[i - 1][j] != 1 && arr[i - 1][j] != 4 && arr[i - 1][j] != 2)
		{
					i--;
					s.push(i, j, 1);
					arr[i][j] = 4;
		}
		//else if (arr[i][j] == 4 && (arr[i - 1][j] != 1 || arr[i][j - 1] != 1 || arr[i + 1][j] != 1 || arr[i][j + 1] != 1) )
		//{

		//}
		else
		{
				arr[i][j] = val;
				s.pop();
				s.s_data(i, j, val);
			//arr[i][j] = val;
		}


		drawboard(arr, size);
		if (arr[i][j] == arr[x][y])
		{
			cout << "PATH FOUND : ";
			flag = 1;
			while (s.is_emp() != 1)
			{
				arr[i][j] = 2;
				s.s_data(i, j, val);
				s.pop();
				drawboard(arr, size);
			}
			break;
		}

		if (s.is_emp() == 1)
		{
			cout << "\nPATH NOT FOUND\n";
		}

		Sleep(30);
		//ClearScreen();
	}
}

int main()
{
	maximized();

	cout << "ENTER THE SIZE OF MAZE : ";
	int size = 0;
	cin >> size;
	int** arr = nullptr;
	allocate(arr,size);
	//show(arr,size);
	drawboard(arr, size);

	int i = 0, x = 0;
	int j = 0, y = 0;
	int flag = 0, flagi = 0;
	cout << "ENTER SOURCE STARTING POINT I : ";
	cin >> i;
	cout << "ENTER SOURCE STARTING POINT J : ";
	cin >> j;
	if (i > size || j > size || arr[i][j] == 1)
	{
		cout << " \nUnsuccessfull Path Due To Source/Destination Is Hurdle \n\n";
		flag = 0;
	}
	else
	{
		arr[i][j] = 2;
		flag = 1;
	}

	cout << "ENTER SOURCE ENDING POINT I : ";
	cin >> x;
	cout << "ENTER SOURCE ENDING POINT J : ";
	cin >> y;
	if (i > size || j > size || arr[x][y] == 1)
	{
		cout << " \nUnsuccessfull Path Due To Source/Destination Is Hurdle\n\n";
		flagi = 0;
	}
	else
	{
		arr[x][y] = 3;
		flagi = 1;
	}
	drawboard(arr, size);
	//show(arr,size);

	movement(arr,size,i,j,x,y);



	return 0;
}