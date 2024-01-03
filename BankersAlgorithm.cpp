#include <iostream>
using namespace std;

int allocation[5][5], maximum[5][5], need[5][5], available[5][5];
int processes, resources;




void table(){
	cout << "\n\n\tBankers Table\n";
	cout << "Available Resources: ";
	for (int i = 0; i < resources; ++i)
	{
		int j = 0;
		cout << available[i][j] << " ";
		j++;
	};
	cout << "\n\n";
	cout << "Process   Allocation   maximum   Need\n";
	for (int i = 0; i < processes; i++)
	{
		cout << "  P" << i << "        ";
		for (int j = 0; j < resources; j++)
		{
			cout << allocation[i][j] << " ";
		};
		cout << "      ";
		for (int j = 0; j < resources; j++)
		{
			cout << maximum[i][j] << " ";
		};
		cout << "   ";
		for (int j = 0; j < resources; j++)
		{
			cout << need[i][j] << " ";
		};

		cout << "\n";
	};
	cout << "\n";
};



void getInput(){
	cout << "Enter the amount of resources for the system: ";
	cin >> resources;

	cout << "Enter the amount of processes for the system: ";
	cin >> processes;

	for (int i = 0; i < processes; i++)
	{
		cout << "\nFor process " << i << " please confirm its details.\n";

		for (int j = 0; j < resources; j++)
		{
			cout << "Enter the allocation for resource " << j << ": ";
			cin >> allocation[i][j];
		};
		for (int k = 0; k < resources; k++)
		{
			cout << "Enter the maximum for resource " << k << ": ";
			cin >> maximum[i][k];
		};
		for (int j = 0; j < resources; j++)
		{
			need[i][j] = maximum[i][j] - allocation[i][j];
		};
	};

	cout << "Enter the amount of available resources the system has: ";

	for (int i = 0; i < resources; i++)
	{
		int j = 0;
		cin >> available[i][j];
		j++;
	};
};

void calculateBankersAlgorithm(){

};


int main()
{

	getInput();
	table();
	calculateBankersAlgorithm();
}
