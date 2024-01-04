#include <iostream>
using namespace std;

int allocation[5][5], maximum[5][5], need[5][5], available[5], initialResources[5];
int processes, resources, numbbb;

// A function to print the table to the console for the users benefit.
void table()
{
	cout << "\n\n\tBankers Table\n";
	for (int i = 0; i < resources; ++i)
    {
		// Reset the initial resources [i] for all resources, to allow for correct addition.
        initialResources[i] = 0;
    };
    // Sum up allocations and available resources to get the initial resources.
    for (int i = 0; i < resources; ++i)
    {
        for (int j = 0; j < processes; j++)
        {
            initialResources[i] += allocation[j][i];
        };
        initialResources[i] += available[i];
    };
	// Print out the initial resources for the system 
	cout << "Initial Resources: ";
    for (int j = 0; j < resources; j++)
    {
        cout << initialResources[j] << " ";
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

		cout << "\n\n";
	};
	cout << "Available Resources: ";
	for (int i = 0; i < resources; ++i)
	{
		cout << available[i] << " ";
	};
	cout << "\n\n";
};

// A function to attain the number of resources, processes and the details for each process from the user.
// This includes the allocation and maximum need from the resources for each process.
void getInput()
{
	cout << "Enter the amount of resources for the system (max 5): ";
	cin >> resources;

	cout << "Enter the amount of processes for the system (max 5): ";
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
		cin >> available[i];
	};
};


// A function to attain the safety state of the system.
bool checkForSafeState()
{
	cout << "not Yet Complete\n";
	numbbb += 1;
	if (numbbb == 2) {
	return true;
	}
	else return false;
};

// A function to attain a new request from the user.
void newRequest()
{

	cout << "not Yet Complete\n";
};

// A function to attain and present the outcome of the bankers algorithm for the user.
void calculateBAOutcome()
{
	// If the system is in a safe state, inform the user and allow for a new request.
	if (checkForSafeState())
	{
		cout << "Your request has been granted, the system is in a safe state.\n";
		newRequest();
		table();
		calculateBAOutcome();
	}
	// Else no new requests will be granted and the system will exit.
	else
	{
		cout << "Your request has been denied as the system would enter a non safe-state.\n"
			 << "The program will now exit.";
	}
};

// The main function for the code. Calling functions within the file.
int main()
{
	cout << "This code will simulate Bankers Algorithm.\nPlease follow the steps presented.\nPlease enter the information clearly as to the programs specifications.\n\n";
	getInput();
	table();
	calculateBAOutcome();
}
