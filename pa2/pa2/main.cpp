#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
Sylvan Brander
day completed 
10/12/18

This program is designed to load in a file of a grocery list 
and alter the contense of the file in three ways
*add an item
*remove an item 
*alter the details of the item
then output them back to the file they were loded in from 
*/



class List
{
public:
	string name;
	int quantity;
	int price;
	
	void	set_name(string);
	void	set_quantity(int);
	void	set_price(int);
	string	return_name(void);
	int		return_quantity(void);
	int		return_price(void);

};

void List::set_name(string item)
{
	name = item;
}

void List::set_quantity(int amount)
{
	quantity = amount;
}

void List::set_price(int value)
{
	price = value;
}

string List::return_name(void)
{
	return name;
}

int List::return_quantity(void)
{
	return quantity;
}

int List::return_price(void)
{
	return price;
}

// this is a function that prompts the user for an item to update then the new demesions of the item 
void updating_list(vector<List> &lists)
{
	int i = 0;
	string to_update, new_price, new_quantity;
	cout << " Which element would you like to update :" << endl;

	while (i < (lists.size()))
	{
		cout << "[" << (i + 1) << "] :  " << lists[i].name << endl;
		i++;
	}
	cout << " Your answer : ";
	getline(cin, to_update);
	cout << endl << " Current price : " << lists[stoi(to_update) - 1].price << endl;
	cout << " New Price : ";
	getline(cin, new_price);
	lists[stoi(to_update) - 1].set_price(stoi(new_price));
	cout << endl << "Current Quantity : " << lists[stoi(to_update) - 1].quantity << endl;
	cout << " New Quantity : ";
	getline(cin, new_quantity);
	lists[stoi(to_update) - 1].set_quantity(stoi(new_quantity));


	cout << endl << "item has been sucessfully updated " << endl << endl;


}
// this function removes an item from the list 
void remove_list(vector<List> &lists)
{
	int i = 0, x;
	string to_delete;
	cout << " Which element would you like to erase :" << endl;

	while (i < (lists.size()))
	{
		cout << "[" << (i + 1) << "] :  " << lists[i].name << endl;
		i++;
	}
	cout << "your answer : ";
		getline(cin, to_delete);
	cout << endl;
	x = stoi(to_delete);
	if (x < lists.size())
	{
		x = x - 1;

		while (x < (lists.size() - 1))
		{
			lists[x] = lists[x + 1];
			x++;
		}
	}
	else
	{
		x = x - 1;

		lists[x] = {};

	}
	cout << endl << " Item has been deleted " << endl;
	lists.resize(lists.size() - 1);

}

// this function takes in the vector of List and adds or updates a particular item 
void add_to_list(vector<List> &lists)
{
	bool is_new = true;
string to_add, ans;
int i = 0, to_update;



	cout << " What item would you like to add : ";

	getline(cin, to_add);
	cout << endl;

	if (lists.size() != 0)
	{
		while (i < (lists.size() - 1))
		{
			if (lists[i].name == to_add)
			{
				is_new = false;
				to_update = i;
			}
			i++;
		}
	}
		if (is_new == false)
		{
			cout << " This item alreay exists " << endl;
			cout << " Would you like to update this element (y/n): ";
			getline(cin, ans);
			if (ans == "y")
			{
				int i = 0;
				string new_price, new_quantity;

					cout << endl << " Current price : " << lists[to_update].price << endl;
				cout << " New Price : ";
				getline(cin, new_price);
				lists[to_update].set_price(stoi(new_price));
				cout << endl << "Current Quantity : " << lists[to_update].quantity << endl;
				cout << " New Quantity : ";
				getline(cin, new_quantity);
				lists[to_update].set_quantity(stoi(new_quantity));

				cout << endl << "item has been sucessfully updated " << endl << endl;
			}
			else
			{
				cout << "Alright then " << endl << endl;
			}
		}
		else
		{
			string new_price, new_quantity;
			lists.resize(lists.size() + 1);
			lists[lists.size() - 1].set_name(to_add);
			cout << "What is the price of this product : $";
			getline(cin, new_price);
			lists[lists.size() - 1].set_price(stoi(new_price));
			cout << endl << "What is the quantity of this item : ";
			getline(cin, new_quantity);
			lists[lists.size() - 1].set_quantity(stoi(new_quantity));

			cout << "Item sucessfully added" << endl << endl;
		}


}



int main()
{
	vector<List> lists{};
	string file_name, item_name, input, ans = "y";
	int item_price, item_quantity, i = 0;
	cout << "What is the name of the file you would like to use : ";
	getline(cin, file_name);

	fstream csv_file;
	csv_file.open(file_name);

	if (csv_file.is_open())
	{
		cout << endl << endl << " File is open " << endl;

		getline(csv_file, item_name);

		while (csv_file.good())
		{
			lists.resize(lists.size() + 1);


			getline(csv_file, input, ',');
			item_name = input;
			lists[i].set_name(item_name);

			if (input == "")
			{
				lists.resize(lists.size() - 1);
				break;
			}

			getline(csv_file, input, ',');
			item_quantity = stoi(input);
			lists[i].set_quantity(item_quantity);

			getline(csv_file, input);
			item_price = stoi(input);
			lists[i].set_price(item_price);
		i++;
		}

		csv_file.close();
	}
		while (ans != "-1")
		{
			// this menu is depicted how it will apear to the user
			// prompting what to do next

			cout << endl << endl << "What would you like to do : " << endl
				<< "............................................." << endl << endl
				<< "[a] : To add an item to the list " << endl
				<< "[b] : To remove an item from the list " << endl
				<< "[c] : To update an existing item in the list " << endl
				<< "[-1]: To exit the program " << endl << " Your answer : ";

			getline(cin, ans);
			cout << endl << endl;

			if (ans == "-1" || ans == "a" || ans == "b" || ans == "c")
			{
				if (ans != "-1")
				{
						if (ans == "c")
						{
							// this if else makes sure we dont try to modify a secion of the list tht dose not exist
							if (lists.size() != 0)
							{
								updating_list(lists);
							}
							else
							{
								cout << endl << "There is nothing to update" << endl << endl;
							}
						}
						if (ans == "b")
						{
							// this if else makes sure we dont try to modify a secion of the list tht dose not exist
							if (lists.size() != 0)
							{
								remove_list(lists);
							}
							else
							{
								cout << endl << "There is nothing to remove" << endl << endl;
							}
						}

						if (ans == "a")
						{
							add_to_list(lists);
						}
					
				}

			}
			else
			{
					cout << "INVALID RESPONSE" << endl << endl;
			}



		}



		ofstream output_file(file_name);

		output_file << "NAME,QUANTITY,PRICE" << "\n";
		i = 0;
		while (i < lists.size())
		{
			output_file << lists[i].name << ",";
			output_file << lists[i].quantity << ",";
			output_file << lists[i].price << "\n";

			i++;
		}

		csv_file.close();




		return 0;

}









