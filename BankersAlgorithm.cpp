#include <iostream>	 // Allows for input/output stream library within the code.
using namespace std; // Allows me to avoid prefixing std:: in the code.

int allocation[5][5], maximum[5][5], need[5][5], available[5], initialResources[5], requestedResources[5], safeSequence[5];
int processes, resources, processRequested;

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
	// Display the initial resources for the system
	cout << "Initial Resources: ";
	for (int j = 0; j < resources; j++)
	{
		cout << initialResources[j] << " ";
	};
	cout << "\n\n";
	// Display the titles for each column of the table.
	cout << "Process   Allocation   maximum   Need\n";
	// Display the corresponding value from each matrix to display the information to the user.
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
	// Display the available resources to the user beneath the table.
	cout << "\nAvailable Resources: ";
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
	while (resources <= 0 || resources > 5) // Validation on the user input.
	{
		cout << "Invalid resource number <<(1 to 5)>>\n";
		cout << "Enter the amount of resources for the system (max 5): ";
		cin >> resources;
	}

	cout << "Enter the amount of processes for the system (max 5): ";
	cin >> processes;
	while (processes <= 0 || processes > 5) // Validation on the user input.
	{
		cout << "Invalid process number <<(1 to 5)>>\n";
		cout << "Enter the amount of resources for the system (max 5): ";
		cin >> processes;
	}

	for (int i = 0; i < processes; i++) // For each of the processes, attain the data for each resource.
	{
		cout << "\nFor process " << i << " please confirm its details.\n";

		for (int j = 0; j < resources; j++) // Attain the allocation data.
		{
			cout << "Enter the allocation for resource " << j << ": ";
			cin >> allocation[i][j];
			while (allocation[i][j] < 0) // Validation on the user input.
			{
				cout << "Invalid allocation for resource <<(This needs to be greater than or equal to 0)>>\n";
				cout << "Enter the allocation for resource " << j << ": ";
				cin >> allocation[i][j];
			}
		};
		for (int k = 0; k < resources; k++) // Attain the maximum request data.
		{
			cout << "Enter the maximum for resource " << k << ": ";
			cin >> maximum[i][k];
			while (maximum[i][k] < allocation[i][k] || maximum[i][k] < 0) // Validation on the user input.
			{
				cout << "Invalid maximum for resource <<(This needs to be greater than or equal to the processes allocation)>>\n";
				cout << "Enter the maximum for resource " << k << ": ";
				cin >> maximum[i][k];
			}
		};
		for (int j = 0; j < resources; j++)
		{
			need[i][j] = maximum[i][j] - allocation[i][j]; // Calculate the need matrix via: need = maximum - allocation for each [i][i].
		};
	};
	cout << "\nPlease enter the amount of available resources the system has.\n";
	for (int i = 0; i < resources; i++)
	{
		cout << "Resource " << i << ": ";
		cin >> available[i];
	};
};

// A function to attain the safety state of the system.
bool checkForSafeState()
{
	// Declaring work and finish as arrays, the same size as their respective needs [i].
	int work[resources];
	bool finish[processes] = {false}; // finish[] will be the same length as processes and each index will be boolean false to start.
	int n = 0;

	// Assigning each index of work to be equal to each index of available.
	for (int i = 0; i < resources; i++)
	{
		work[i] = available[i];
	}
	// A while (true) loop to keep the safety algorithm going until instructed to break.
	while (true)
	{
		bool found = false;
		// Find an index where finish[i] is equal to false, and need[i] is less than or equal to work[i].
		for (int i = 0; i < processes; i++)
		{
			if (!finish[i])
			{
				bool possible = true;
				for (int j = 0; j < resources; j++)
				{
					if (need[i][j] > work[j])
					{
						possible = false;
						break;
					}
				}
				if (possible)
				{
					// If all need[i] is less than or equal to work[i], add allocation[i] to work[i] and set finish[i] to true.
					for (int k = 0; k < resources; k++)
					{
						work[k] += allocation[i][k];
					}
					finish[i] = true;
					found = true;
					safeSequence[n] = i;
					n++;
				}
			}
		}
		// If no processes were possible in this pass (found never updated to true), break the while loop.
		if (!found)
		{
			break;
		}
	}

	// A for loop to check each indexes boolean value within finish.
	for (int i = 0; i < processes; i++)
	{
		if (!finish[i]) // If an index of finish is false then its need surpassed the available resources and it was never able to execute.
		{
			return false; // If a finish[i] is equal to false, return false. The system is not in a Safe state.
		}
	}
	return true; // If finish[i] is equal to true for all indexes, then return true. the system is in a Safe state.
};

// This function attains and prints the safe sequence for the user.
void showSafeSequence()
{
	cout << "Your request has been granted, the system is in a safe state.\nThe safe sequence found is: ";
	for (int i = 0; i < processes; i++)
	{
		cout << "P" << safeSequence[i];
		if (i < processes - 1)
		{
			cout << " --> ";
		}
		else
		{
			cout << ".";
		};
	};
};

// A function to hold the resource request algorithm.
// This function will update the needed matrices if the request can be granted safely.
void resourceRequestAlgorithm()
{
	// Initialising some temporary arrays to save the state of the Bankers Algorithm.
	int temporaryAvailable[5], temporaryAllocation[5][5], temporaryNeed[5][5];

	// If the the user resource request input is greater than the need or greater than the available resources the request will not be granted.
	for (int i = 0; i < resources; i++)
	{

		if (requestedResources[i] > need[processRequested][i] || requestedResources[i] > available[i])
		{
			cout << "Invalid request amount. It cannot be more than the need of the chosen process, more than the available resources, or a negative value.\n";
			cout << "\nYour request has been denied as the system would enter an unsafe state.\nThe execution of these processes may result in deadlocks or resource starvation.\nThe program will now exit.";
			return;
		}
	}

	// Saving the curent state of the available, allocation and need matrices.
	for (int i = 0; i < resources; i++)
	{
		temporaryAvailable[i] = available[i];
	}
	for (int i = 0; i < processes; i++)
	{
		for (int j = 0; j < resources; j++)
		{
			temporaryAllocation[i][j] = allocation[i][j];
			temporaryNeed[i][j] = need[i][j];
		}
	}

	// Make the necessary changes to the system to then check for a safe state.
	for (int i = 0; i < resources; i++)
	{
		available[i] -= requestedResources[i];
		allocation[processRequested][i] += requestedResources[i];
		need[processRequested][i] -= requestedResources[i];
	}

	// Check if the new state of the system is safe.
	if (checkForSafeState()) // If the system is in a safe state present the table, the safe sequence found and an end message.
	{
		table();
		showSafeSequence();
		cout << "\nThe program will now exit.";
	}
	else // else if the system is in an unsafe state revert the data and print an error message.
	{
		cout << "\nYour request has been denied as the system would enter an unsafe state.\nThe execution of these processes may result in deadlocks or resource starvation.\nThe program will now exit.";

		// Revert to the saved safe state, before the new request, because the request leads to an unsafe system state.
		for (int i = 0; i < resources; i++)
		{
			available[i] = temporaryAvailable[i];
		}
		for (int i = 0; i < processes; i++)
		{
			for (int j = 0; j < resources; j++)
			{
				allocation[i][j] = temporaryAllocation[i][j];
				need[i][j] = temporaryNeed[i][j];
			}
		}
	};
};

// A function to attain a new request from the user.
// This function will determine if the resource request can be granted, if so it will call the resource request algorithm.
void newRequest()
{
	cout << "\nPlease enter the process you wish to make a request on (0 to " << processes - 1 << "): ";
	cin >> processRequested;
	while (processRequested < 0 || processRequested >= processes) // Validation on the user input.
	{
		cout << "Invalid process number <<(0 to " << processes - 1 << ")>>\n";
		cout << "Please enter the process you wish to make a request on (0 to " << processes - 1 << "): ";
		cin >> processRequested;
	}
	cout << "Please enter the new request figures for Process " << processRequested << ".\n";

	for (int i = 0; i < resources; i++)
	{
		cout << "Resource allocation " << i << ": ";
		cin >> requestedResources[i];
	}
	// The user entered information will then be passed on to the resource request algorithm below.
	resourceRequestAlgorithm();
};

// A function to attain and present the outcome of the bankers algorithm for the user.
void calculateBAOutcome()
{
	// If the system is in a safe state, inform the user and allow for a new request.
	if (checkForSafeState())
	{
		showSafeSequence();
		newRequest();
	}
	// Else no new requests will be granted and the system will exit.
	else
	{
		cout << "Your request has been denied as the system would enter a non safe-state.\nThe execution of these processes may result in deadlocks or resource starvation.\nThe program will now exit.";
	};
};

// The main function for the code. Calling functions within the file.
int main()
{
	cout << "This code will simulate Bankers Algorithm.\nPlease follow the steps presented.\nPlease enter the information clearly as to the programs specifications.\n\n";
	getInput();
	table();
	calculateBAOutcome();
};