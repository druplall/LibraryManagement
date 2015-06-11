#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class Student{

public:

	Student( string firstName, string lastName, int studentID){
		first_Name = firstName;
		last_Name = lastName;
		Student_ID = studentID;
	}

	string getFirstName(){ return first_Name; }
	string getLastName(){ return last_Name; }
	int getID(){ return Student_ID; }



private:
	string first_Name;
	string last_Name;
	int Student_ID;

};


class Book{

public:

	Book(int x, string z, string y){
		book_ID = x;
		z = book_Name;
		y = book_Author;
	}


	int getBookID(){
		return book_ID;
	}

	string get_book_Name(){
		return book_Name;
	}

	string get_book_Author(){
		return book_Author;
	}

private:
	int book_ID;
	string book_Name;
	string book_Author;

};

void printVector(vector<Student> test);
void writeBooks(vector<Book> & x);

int main(){

	vector<Book> book_Container;

	vector<Student> student_Container;

	cout << "LIBRARY MANAGEMENT SYSTEM " << endl;
	cout << "Made by: Deodat Ruplall" << endl;
	cout << "SCHOOL: CUNY HUNTER COLLEGE \n";

	cout << "Main Menu \n";
	cout << "01. BOOK ISSUE \n";
	cout << "02. BOOK DEPOSIT \n";
	cout << "03. ADMINISTRATOR MENU \n";
	cout << "04. EXIT \n";

	int userChoice;
	int book_Number;

	int student_ID; // Student ID
	int look_UP_StudentID;

	cout << "Please Select Your Option (1-4) "; 
	cin >> userChoice;

	if (userChoice == 1){
		cout << "BOOK ISSUE.... \n";

		cout << "Enter The Student's admission no. "; cin >> look_UP_StudentID;

		cout << "Enter the book no. "; cin >> book_Number;

		for (size_t i = 0; i < book_Container.size(); i++){
			
			if (book_Container[i].getBookID() == book_Number){
				cout << "Book no. : " << book_Container[i].getBookID() << endl;
				cout << "Book Name : " << book_Container[i].get_book_Name() << endl;
				cout << "Author Name:  " << book_Container[i].get_book_Author() << endl;

				cout << "Book issued successfully \n";
				cout << "Please Note: Write the current date in backside of your book and sumbit within 15 days"
					<< " Rs. 1 for each day after 15 days period";

				/*
					NEED TO UPDATE STUDENT OBJECT!!
				*/
			}
		}
	}// User picked one

	/*
		Administrator Guide
	*/
	else if (userChoice == 3){
		
		cout << "ADMINISTRATOR MENU \n";
		cout << "1. CREATE STUDENT RECORD \n";
		cout << "2. DISPLAY ALL STUDENT RECORD \n";
		cout << "3. DISPLAY SPECIFIC STUDENT RECORD \n";
		cout << "4. MODIFY STUDENT RECORD \n";
		cout << "5. DELETE STUDENT RECORD \n";
		cout << "6. CREATE BOOK \n";
		cout << "7.	DISPLAY ALL BOOKS \n";
		cout << "8. DISPLAY SPECIFIC BOOK \n";
		cout << "9. MODIFY BOOK \n";
		cout << "10. DELETE BOOK \n";
		cout << "11. BACK TO MAIN MENU \n";

		int userSubChoice;
		cout << "Please Enter Your Choice (1-11) "; cin >> userSubChoice;
		//ERROR CHECKING CODE!
		if (userSubChoice < 1 || userSubChoice > 11){
			cout << "Error";
		}
		else{
		
			if (userSubChoice == 1){
				cout << "NEW STUDENT ENTRY...." << endl;
				int tempID;
				string tempFirstName;
				string tempLastName;

				cout << "Enter The admission no. "; cin >> tempID;
				cout << "Enter The first Name: "; cin >> tempFirstName;
				cout << "Enter The Last Name: "; cin >> tempLastName;

				Student * newOb = new Student(tempFirstName, tempLastName, tempID);
				student_Container.push_back(*newOb);

				printVector(student_Container);

			}
		

			/*
			  CREATE BOOK
			*/
			else if (userSubChoice == 6){
				cout << "NEW BOOK ENTRY...." << endl;
				int tempID;
				string tempBookTitle;
				string tempBookAuthor;

				cout << "Enter The book no. "; cin >> tempID;
				cout << "Enter The Name of the Book: "; cin >> tempBookTitle;
				cout << "Enter The Last Name: "; cin >> tempBookAuthor;

				Book * newOb = new Book(tempID, tempBookTitle, tempBookAuthor);
				book_Container.push_back(*newOb);

				writeBooks(book_Container);

			}


		}
	}
	//

	system("pause");
	return 0;
}

void printVector(vector<Student> test){

	for (size_t i = 0; i < test.size(); i++){
		cout << test[i].getFirstName() << " " << test[i].getLastName() << " " << test[i].getID() << endl;
	}
}


void writeBooks(vector<Book> & x){

	ofstream outfile;
	outfile.open("Books.txt",  ios::out);
	for (size_t i = 0; i < x.size(); i++){
		
		outfile.write((char *)&x[i],  sizeof(x[i]));
	}

	outfile.close();



}