#include<iostream>//header file for  input&output functions like cin,cout e.t.c
#include<fstream>//header file for file handling functions
#include<string>//header file for string functions
using namespace std;//standard for c++ functions like cin,cout e.t.c
const int attributes = 4;//constant integer to be used in program sotaht its value does not change
const int num_of_records = 10;//constant integer to be used in program sotaht its value does not change
void  vehicle();//function-prototype
void addvehicles();//function-prototype
void viewvehicles();//function-prototype
void search();//function-prototype
void menu();//function-prototype
void update();//function-prototype
void remove();//function-prototype
void customer(int arr[][attributes], int current_record);//function-prototype
void add_record(int arr[][attributes], int& current_record);//function-prototype
void view_record(int(*arrptr)[attributes], int& current_record);//function-prototype
void search_record(int arr[][attributes], int current_record);//function-prototype
void update_record(int arr[][attributes], int& current_record);//function-prototype
void remove_record(int arr[][attributes], int& current_record);//function-prototype
void arrmenu(int arr[][attributes], int current_record);//function-prototype
int main()          // Main function from where the execution started
{
	int option, current_record = 0, myarray[num_of_records][attributes] = { 0 };  // Declaration of variables: option for user input, current_record to keep track of records, and myarray as a 2D array to store data
	char sure = 'n';  // Variable to confirm user's choice
	cout << "\n------------------------------------" << endl;  // Formatted output
	cout << "---CAR SHOWROOM MANAGEMENT SYSTEM---" << endl;      // Project Heading
	cout << "------------------------------------" << endl;  // Formatted output

	do//do while loop so that the body must execute for single time
	{
		cout << "\nChoose from the choices below \n1-Vehicles\n2-Customer\n3-Exit the Program\n";  // Displaying menu options to the user
		cin >> option;  // Reading user input

		switch (option)
		{
		case 1:
			cout << "\nCalling Add Vehicle Function";  // Informing the user about the function call
			vehicle();  // Calling the vehicle function
			break;
		case 2:
			cout << "\nCalling Add Customer Function";  // Informing the user about the function call
			customer(myarray, current_record);  // Calling the customer function with array and current_record as parameters
			break;
		case 3:
			cout << "\nAre you sure to exit (Y for Yes || N for No)";  // Confirming user's intention to exit
			cin >> sure;  // Reading user's confirmation
			cout << endl;  // Outputting a newline character
		}
	} while (sure == 'N' || sure == 'n');  // Continue the loop as long as the user does not confirm the intention to exit
}
void menu()//calling menu function
{
	int option;//integer data type variable used to hold 32 bit for user input as option,sure
	char sure = 'n';
	do//do while loop so that the body must execute for single time
	{
		cout << "\n1-Add Vehicle in Record\n2-View Vehicle from record\n3-Search Vehicle from record\n4-Update Vehicle Record\n5-Delete Vehicle from Record\n6-Exit the program" << endl;
		cin >> option;//taking input from user
		switch (option)// we used it to check equality...so that accordingly the case will execute
		{
		case 1://if option matches 1 it will execute statements below
			cout << "\nAdd Vehicle in Record" << endl;
			addvehicles();//calling function to add data
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		case 2://if option matches 2 it will execute statements below
			cout << "\nView Vehicles in Record" << endl;
			viewvehicles();//calling function to add data
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		case 3://if option matches 3 it will execute statements below
			cout << "\nSearch a Vehicle in Record" << endl;
			search();//calling function to add data
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		case 4://if option matches 4 it will execute statements below
			cout << "\nUpdate a Vehicle in Record" << endl;
			update();//calling function to add data
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		case 5://if option matches 5 it will execute statements below
			cout << "\nRemove a Vehicle from Record" << endl;
			remove();//calling function to add data
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		case 6://if option matches 6 it will execute statements below
			cout << "\nAre you sure to exit (Y for Yes || N for No)";
			cin >> sure;
			cout << endl;
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		default://when no case is matched default will be executed
			cout << "\nGOOD BYE";
			break;//if this case is exuted then it will stop here and exit from the body of switch statament
		}
	} while (sure == 'N' || sure == 'n');
}
void viewvehicles() // function name with function definition ahead
{
	try //exceptional handling
	{
		ifstream fin;//object for reading from file
		fin.open("vehicles.txt");//opening a file
		if (fin.fail())//checking whether the file is opened or not
		{
			throw 1;//throws error if file not opened
		}
		else//if above condition is fale this part will be executed
		{
			string name, registrationnum;//string data type variables that reserve 24 bytes of memory
			int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
			while (fin >> name >> price >> model >> registrationnum)//reading data fromwhile until the end of file
			{
				cout << "\nCar Name : " << name;//making us able to view data (car name) from file
				cout << "\nPRICE : " << price;//making us able to view data (price) from file
				cout << "\nModel : " << model;//making us able to view data (model) from file
				cout << "\nReg no. : " << registrationnum << endl << endl;//making us able to view data (registration no) from file
			}
			fin.close();//closing file
		}
	}
	catch (int error)//it cathes what is thrown from try block
	{
		cout << "\nAccess denied ";
		cout << "\nError number: " << error;//sends message on output screen
	}
}
void addvehicles() // function name with function definition ahead
{
	string name, registration;//string data type variables that reserve 24 bytes of memory for name and for registration number
	int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
	char check;//character data type variableto reserve 1 byte in memory for check
	ofstream fout;//object for writing to  file
	fout.open("vehicles.txt", ios::app);//opening a file on append mode
	do//do-while loop to ask your to enter data multiple time as far as user want to enter we may use while here
	{
		cout << "\nEnter car name : ";//ask the user to enter car name
		cin >> name;//taking name as input from user
		cout << "\nEnter the price : ";//ask the user to enter car price
		cin >> price;//taking price as input from user
		cout << "\nEnter the model : ";//ask the user to enter car model
		cin >> model;//taking model as input from user
		cout << "\nEnter the registration number : ";//ask the user to enter registration number
		cin >> registration;//taking registration number as input from user
		fout << name << "\t" << price << "\t" << model << "\t" << registration << endl;//writing entered data into the file with proper formatting
		cout << "\nEnter y or Y to input again otherwise program will terminates: ";//asking user whether he want more execution or not
		cin >> check;//taking check as input from user that will check will this loop will be continued or not
		cout << endl;//to move cursor to beginning of next line
	} while ((check == 'y') || (check == 'Y'));//checks for whther user want to input again or not
	fout.close();//closing file
}
void search()//function name with function definition ahead
{
	int search;//integer data type variables used to hold 32 bit for user input as search
	bool found = false;//flag value(base false)
	string name, carname, registrationnum, registrationno;//string data type variables that reserve 24 bytes of memory for name, car name, registration & registration number
	int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
	char check;//character data type variableto reserve 1 byte in memory for check
	do//do-while loop to ask your to enter data multiple time as far as user want to enter we may use while here
	{
		cout << "----How you want to search by-----" << endl;
		cout << "\nBy Name (Press 1) \nBy Registration number (Press 2) ";//giving choice to user whether he wants to search by name or by registration number
		cin >> search; //input choice from user for letting him option of according to which method he wants to search record by
		ifstream fin;//object for reading from  file
		fin.open("vehicles.txt");
		try//exceptional handling
		{
			if (fin.fail())//checking whether the file is opened or not
			{
				throw 3;//throws error if file not opened
			}
			else//if above condition is fale this part will be executed
			{//opening a file for reading
				switch (search)// we used it to check equalitywhther case 1 or case 2 is to be executed...so that accordingly the case will execute
				{
				case 1://if user enter choice as 1 this case will be executed
				{
					cout << "Enter car name : ";//asking user the name of car to be searched
					cin >> carname;//taking input of carname
					while (fin >> name >> price >> model >> registrationno)//reading data fromwhile until the end of file
					{
						if (name == carname)//check whether the entered data is present in the  or not
						{
							found = true;//flag value (true)
							break;//to exit from the body of if statement
						}
						else if (name != carname) // check whether the entered data is present in the or not
						{
							found = false;//flag value (false)
						}
					}
					if (found)//checking flag value
					{   //displaying the search results
						cout << "\nCAR NAME : " << name;//displaying the search results
						cout << "\nPRICE : " << price;//displaying the search results
						cout << "\nMODEL : " << model;//displaying the search results
						cout << "\nREGISTRATION NUMBER : " << registrationno << endl << endl;//displaying the search results
						break;
					}
					else//if above condition is fale this part will be executed
					{
						cout << endl << "RECORD NOT FOUND" << endl;
						break;//to exit from body of else//displaying the message record not found
					}
				}
				case 2://if user enter choice as 2 this case will be executed
				{
					cout << "\nEnter car Registration number : ";//asking user to enter  the registration no of car to be searched
					cin >> registrationnum;//taking input of registration number
					while (fin >> name >> price >> model >> registrationno)//reading data fromwhile until the end of file
					{
						if (registrationno == registrationnum)// check whether the entered data is present in the or not
						{
							found = true;//flag value (false)
							break;//to exit from body of if
						}
						else if (registrationno != registrationnum) // check whether the entered data is present in the or not
						{
							found = false;//flag value (false)

						}
					}
				}
				}
				if (found)// checking flag value
				{
					cout << "\nCAR NAME : " << name; //displaying the search results
					cout << "\nPRICE : " << price; // displaying the search results
					cout << "\nMODEL : " << model; //displaying the search results
					cout << "\nREGISTRATION NUMBER : " << registrationno << endl << endl; //displaying the search results
				}
				else//if above condition is fale this part will be executed
				{
					cout << endl << "RECORD NOT FOUND" << endl;//displaying the message record not found
				}
			}
		}
		catch (int error)//it cathces what is thrown from try block
		{
			cout << "\nAccess denied-File not found ";
			cout << "\nError : " << error;//sends message on output screen
		}
		cout << "\nWant to Search  Again Press 'y' or 'Y otherwise program will be terminated'";//checks for whther user want to input again or not
		cin >> check;
	} while (check == 'y' || check == 'Y');//asking user whether he want more execution or not
}
void update() // function name with function definition ahead
{
	int  price, new_price, model, new_model;//integer data type variables used to hold 32 bit for each user input as price,new price,model and new model
	string name, new_name, name_to_update, new_registration, registration;//string data type variables that reserve 24 bytes of memory for each  name ,name to update,registration and for registration number
	ofstream fout;//creating ofstream object
	fout.open("temp.txt");//opening a file for writing
	try//exceptional handling
	{
		bool flag = false;
		ifstream fin;//object for reading from  file
		fin.open("vehicles.txt");//opening a file for reading
		if (fin.fail())//checking whether the file is opened or not
		{
			throw 4;//throws error if file not opened
		}
		else//if above condition is fale this part will be executed
		{
			cout << "\nEnter the name of vehicle you want to update : ";//asking user tio enter name of record you want to update
			cin >> name_to_update;//getting input of the name to update
			while (fin >> name >> price >> model >> registration)//reading data fromwhile until the end of file
			{
				if (name_to_update != name)//check whether the entered data is present in the  or not
				{
					fout << name << "\t" << price << "\t" << model << "\t" << registration << endl;//writing entered data into the file with proper formatting
				}
				else if (name_to_update == name)//cheching if the record exist
				{
					cout << "\nEnter New name : ";//asking using to enter new name to store in file (by updating)
					cin >> new_name;//read new name entered by user
					cout << "\nEnter New price : ";//asking using to enter new name to store in file (by updating)
					cin >> new_price;//read new price entered by user
					cout << "\nEnter New model : ";//asking using to enter new name to store in file (by updating)
					cin >> new_model;//read new model entered by user
					cout << "\nEnter New registration number : ";//asking using to enter new name to store in file (by updating)
					cin >> new_registration;//read new registration number entered by user
					fout << new_name << "\t" << new_price << "\t" << new_model << "\t" << new_registration << endl;//writing entered data into the file with proper formatting
					flag = true;
					break;//used to exit from body of if (if condition is true
				}
			}
			if (flag)
			{
				cout << "\nThe record with the name " << name_to_update << " has been updated if it existed" << endl;//shows message on screen of update confirmed
			}
			fin.close();//closing file
			fout.close();//closing file
			remove("vehicles.txt");//removing file
			if (!rename("temp.txt", "vehicles.txt"))//renaming temp file to vehicles file
			{
				cout << "\n-";// just to show that file is renamed
			}
			else//if above condition is fale this part will be executed
			{
				cout << "\nCheck for error in renaming file";//runs if file is not renamed
			}
		}
	}
	catch (int error)//it cathces what is thrown from try block
	{
		cout << "\nAccess denied-File not found ";
		cout << "\nError : " << error;//sends message on output screen
	}
}
void remove() // function name with function definition ahead
{
	int price, model;//integer data type variables used to hold 32 bit for each user input as price and model
	string name_to_del, name, registration;//string data type variables that reserve 24 bytes of memory for each name ,name to delete and for registration number
	cout << "\nPlease Enter the name of vehicle you want to delete: ";//ask user to enter the name of vehicle you want to delete
	cin >> name_to_del;//reads the name entered by user
	ofstream fout;//object for writing to file
	fout.open("temp.txt");//opening a file for writing
	try//exceptional handling
	{
		ifstream fin;//object for reading from  file
		fin.open("vehicles.txt");//opening a file for reading
		if (fin.fail()) //checking whether the file is opened or not
		{
			throw 5;//throws error if file not opened
		}
		else//if above condition is fale this part will be executed
		{
			while (fin >> name >> price >> model >> registration)//reading data fromwhile until the end of file
			{
				if (name != name_to_del)//check whether the entered data is present in the  or not
				{
					fout << name << "\t" << price << "\t" << model << "\t" << registration << endl;//writing entered data into the file with proper formatting
				}
			}
			cout << "\nThe record with the name " << name_to_del << " has been deleted if it existed" << endl;//displaying message if record has been deleted
			fin.close();//closing file
			fout.close();
			remove("vehicles.txt");//removing/deleting file
			if (!rename("temp.txt", "vehicles.txt"))//renaming temp file to vehicles file
			{
				cout << "\n-";// to show that file is renamed
			}
			else//if above condition is fale this part will be executed
			{
				cout << "\nCheck for error";// to show that file is not-renamed
			}
		}
	}
	catch (int error)//it catches what is thrown from try block
	{
		cout << "\nAccess denied-File not found ";
		cout << "\nError : " << error;//sends message on output screen
	}

}
void arrmenu(int arr[][attributes], int current_record)
{
	int check1;  // Variable to store user's choice from the menu
	char sure = 'n';  // Variable to store user's confirmation for exit

	do//do while loop so that the body must execute for single time
	{
		cout << "\n1-Add Record\n2-View Record\n3-Search Record\n4-Update Record\n5-Delete  Record\n6-Exit\n";  // Displaying menu options to the user
		cin >> check1;  // Reading user input

		switch (check1)
		{
		case 1:
			add_record(arr, current_record);  // Calling the add_record function with array and current_record as parameters
			break;
		case 2:
			view_record(arr, current_record);  // Calling the view_record function with array and current_record as parameters
			break;
		case 3:
			search_record(arr, current_record);  // Calling the search_record function with array and current_record as parameters
			break;
		case 4:
			update_record(arr, current_record);  // Calling the update_record function with array and current_record as parameters
			break;
		case 5:
			remove_record(arr, current_record);  // Calling the remove_record function with array and current_record as parameters
			break;
		case 6:
			cout << "\nAre you sure to exit (Y for Yes || N for No)";  // Confirming user's intention to exit
			cin >> sure;  // Reading user's confirmation
			cout << endl;  // Outputting a newline character
		}
	} while (sure == 'N' || sure == 'n');  // Looping until the user chooses to exit
}
void view_record(int(*arrptr)[attributes], int& current_record)
{
	try
	{
		// Open the file "arrcus.txt" for reading
		ifstream fin;
		fin.open("arrcus.txt");

		// Check if the file opening is successful
		if (fin.fail())
		{
			// Throw an exception with error code 1 if file opening fails
			throw 1;
		}
		else
		{
			// Display a header for the customer records
			cout << "\n** ALL RECORD OF THE CUSTOMERS **" << endl;

			// Loop through each record and attribute in the file
			for (int i = 0; i < num_of_records; i++)
			{
				for (int j = 0; j < attributes; j++)
				{
					// Read data from the file into the array
					fin >> arrptr[i][j];
				}
			}

			// Display a separator line
			cout << "--------------------";

			// Loop through each record and display customer information
			for (int i = 0; i < num_of_records; i++)
			{
				// Print customer details only if Customer ID is not 0
				if (arrptr[i][0] != 0)
				{
					cout << "\nCustomer ID : " << arrptr[i][0];
					cout << "\nCar ID: " << arrptr[i][1];
					cout << "\nCar Category: " << arrptr[i][2];
					cout << "\nPaid Amount : " << arrptr[i][3] << endl << "--------------------";
				}
			}
		}
	}
	catch (int error)
	{
		// Handle exceptions by displaying an error message
		cout << "\nAccess denied ";
		cout << "\nError number: " << error;
	}
}
void add_record(int arr[][attributes], int& current_record)
{
	ofstream fout;	// Declare an object for writing to a file
	fout.open("arrcus.txt", ios::trunc);	// Open a file in truncate mode (existing content will be deleted)
	char check;	// Declare variables
	int customer_id, car_id, car_category, paid_amount;	// Declare variables
	do//do while loop so that the body must execute for single time
	{
		cout << "\nEnter Customer ID : ";	// Prompt the user for input
		cin >> customer_id;
		cout << "\nEnter Car ID: ";	// Prompt the user for input
		cin >> car_id;
		cout << "\nEnter New Car Category(1 - SUV) (2 - Sedan) (3 - Hatchback) : ";	// Prompt the user for input
		cin >> car_category;
		cout << "\nEnter Paid Amount : ";	// Prompt the user for input
		cin >> paid_amount;
		arr[current_record][0] = customer_id;		// Assign input values to the array
		arr[current_record][1] = car_id;		// Assign input values to the array
		arr[current_record][2] = car_category;		// Assign input values to the array
		arr[current_record][3] = paid_amount;		// Assign input values to the array
		cout << "\nEnter y or Y to input again otherwise program will terminate: ";		// Prompt the user whether  to input again
		cin >> check;
		cout << endl;
		current_record++;// Increment the current_record counter
	} while ((check == 'y') || (check == 'Y'));//whether user wants to enter data again by condition
	for (int i = 0; i < current_record; i++)
	{
		for (int j = 0; j < attributes; j++)
		{
			fout << arr[i][j] << " ";	// Write the array data to the file
		}
		fout << endl;
	}
	fout.close();	// Close the file
}
void search_record(int arr[][attributes], int current_record)
{
	int search_by_id, i, j;	// Declare variables
	bool find = false;//bool type variable to have either true or false answer
	ifstream fin; // object for reading
	fin.open("arrcus.txt");// Open the file "arrcus.txt" for reading
	try	// Try block to handle potential exceptions
	{
		if (fin.fail())// Check if the file opening is unsuccessful
		{
			throw 1;// Throw an exception with error code 1 if file opening fails
		}
		else
		{			// Input values from the file into the array
			for (i = 0; i < current_record; i++)
			{
				for (j = 0; j < attributes; j++)
				{
					fin >> arr[i][j];//read data from file to array
				}
			}
			cout << "\nEnter ID to search record : ";// Prompt the user to enter an ID to search
			cin >> search_by_id;
			for (i = 0; i < num_of_records; i++)// Loop through records to find a match with the entered ID
			{
				if (search_by_id == arr[i][0])//to find a match with the entered ID
				{
					find = true;
					break;
				}
			}
			if (find == true)// Check if a matching record was found
			{
				cout << "\n------Record found------"; //shows the searched record
				cout << "\nCustomer ID : " << arr[i][0];//shows the searched record
				cout << "\nCar ID : " << arr[i][1];//shows the searched record
				cout << "\n Car Category:  " << arr[i][2];//shows the searched record
				cout << "\nPaid Amount : " << arr[i][3] << endl << "------------------------";//shows the searched record
			}
			else// if a matching record was not found
			{
				cout << "\nRecord not found ! ";	// Display a message if the record is not found
			}
		}
	}
	catch (int error)// Catch block to handle exceptions thrown in the try block
	{
		cout << "\nAccess denied ";
		cout << "\nError number: " << error;
	}
}
void update_record(int arr[][attributes], int& current_record)
{	// Declare variables for updating records
	int update_by_id, i;
	int new_customer_id, new_car_id, new_car_category, new_paid_amount;
	bool flag = false;//bool type variable to have either true or false answer
	ifstream fin;	//object for file output to program
	fin.open("arrcus.txt");// Open the file "arrcus.txt" for reading
	try	// Try block to handle potential exceptions
	{
		if (fin.fail())		// Check if the file opening is unsuccessful
		{
			throw 1;			// Throw an exception with error code 1 if file opening fails
		}
		else
		{
			int temp_arr[num_of_records][attributes] = { 0 };// Declare a temporary array to store data from the file
			for (i = 0; i < num_of_records; i++)
			{
				for (int j = 0; j < attributes; j++)
				{
					fin >> temp_arr[i][j];			// Read data from the file into the temporary array
				}
			}
			fin.close();// Close the file after reading
			cout << "\nEnter ID to update record : ";// Prompt the user to enter an ID to update
			cin >> update_by_id;
			for (i = 0; i < num_of_records; i++)
			{
				if (update_by_id == temp_arr[i][0])			// Search for the record to update in the temporary array
				{
					flag = true;//bool variable true
					break;//if true then break to exit form body
				}
			}
			if (flag)			// Check if the record to update is found
			{
				cout << "\nEnter New ID : ";// Get new data from the user
				cin >> new_customer_id;
				cout << "\nEnter New Car ID : ";// Get new data from the user
				cin >> new_car_id;
				cout << "\nEnter New Car Category (1-SUV, 2-SEDAN, 3-HATCHBACK) : ";// Get new data from the user
				cin >> new_car_category;
				cout << "\nEnter New Paid Amount : ";// Get new data from the user
				cin >> new_paid_amount;			// Update the temporary array with the new data
				temp_arr[i][0] = new_customer_id;
				temp_arr[i][1] = new_car_id;
				temp_arr[i][2] = new_car_category;
				temp_arr[i][3] = new_paid_amount;
				ofstream fout; //file input mode object
				fout.open("arrcus.txt", ios::trunc);				// Open the file in truncation mode to clear its contents
				for (int j = 0; j < num_of_records; j++)
				{
					fout << temp_arr[j][0] << " " << temp_arr[j][1] << " " << temp_arr[j][2] << " " << temp_arr[j][3] << endl;// Write the updated data back to the file
				}
				fout.close();			// Close the file after writing
				cout << "\n------Updated Record------ ";
				cout << "\nCustomer ID : " << temp_arr[i][0];	// Display the updated record
				cout << "\nCar ID : " << temp_arr[i][1];	// Display the updated record
				cout << "\nCar Category : " << temp_arr[i][2];	// Display the updated record
				cout << "\nPaid Amount : " << temp_arr[i][3] << endl << "--------------------";	// Display the updated record
				cout << "\nRecord has been Updated ";
				cout << "\n--------------------";
			}
			else
			{
				cout << "\nRecord not found ! ";// Display a message if the record to update is not found
			}
		}
	}
	catch (int error)// Catch block to handle exceptions thrown in the try block
	{
		cout << "\nAccess denied ";
		cout << "\nError number: " << error;
	}
}
void remove_record(int arr[][attributes], int& current_record)
{
	int remove_by_id, i, j;	// Declare variables for removing records
	bool flag = false;//bool type variable to have either true or false answer
	ifstream fin; //object for output from file
	ofstream fout; //object for input to file
	try// Try block to handle potential exceptions
	{
		fin.open("arrcus.txt");		// Open the file "arrcus.txt" for reading
		if (fin.fail())		// Check if the file opening is unsuccessful
		{
			throw 1;			// Throw an exception with error code 1 if file opening fails
		}
		else
		{
			int temp_arr[num_of_records][attributes];			// Read data from the file into a temporary array
			for (i = 0; i < num_of_records; i++)
			{
				for (j = 0; j < attributes; j++)
				{
					fin >> temp_arr[i][j];//read from file to temp array
				}
			}
			fin.close();
			cout << "\nEnter ID to delete record : ";			// Prompt the user to enter an ID to delete
			cin >> remove_by_id;
			for (i = 0; i < num_of_records; i++)
			{
				if (remove_by_id == temp_arr[i][0])			// Search for the record to delete in the temporary array
				{
					flag = true;//bool variable true
					break;//if true then break to exit form body
				}
			}
			if (flag)			// Check if the record to delete is found
			{
				// Copy the modified data back to the original array,
				for (i = 0; i < current_record; i++)
				{
					if (temp_arr[i][0] != remove_by_id) // help excluding the record to delete
					{
						for (j = 0; j < attributes; j++)
						{
							arr[i][j] = temp_arr[i][j];//copying the array
						}
					}
				}
				current_record--;				// Update the number of current records
				fout.open("arrcus.txt", ios::trunc);				// Open the file in truncation mode to clear its contents
				for (i = 0; i < current_record; i++)
				{
					for (j = 0; j < attributes; j++)
					{
						fout << arr[i][j] << " ";			// Write the modified data back to the file
					}
					fout << endl;//formatted output
				}
				fout.close();				// Close the file after writing
				cout << "\nRecord has been deleted! ";				// Display a message indicating that the record has been deleted
			}
			else
			{
				cout << "\nRecord not found! ";				// Display a message if the record to delete is not found
			}
		}
	}
	catch (int error)	// Catch block to handle exceptions thrown in the try block
	{
		cout << "\nAccess denied ";
		cout << "\nError number: " << error;
	}
}
void customer(int arr[][attributes], int current_record)
{
	int myarray[num_of_records][attributes] = { 0 };// Declare a temporary array
	arrmenu(myarray, current_record); //call the function arrmenu with the original arrayand current_record
}
void vehicle()
{
	menu();	// Call the function menu for vehicle-related operations
}