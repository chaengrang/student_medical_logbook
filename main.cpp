#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream.h>

// NOTE: admin credentials, hanni = hanni -> index: 0, rei = rei => index: 1
char user[100][100] = {"hanni", "rei"}, pass[100][100] = {"hanni", "rei"};

char name[100], yr_sec[25], st_num[25];
// NOTE: add sample entry, update userCount.
char blood_type[25], allergies[25], med_history[25],
med_condition[25], medcation_status[25], sugery_status[25];
// TODO: suggest for optimisation
int age;
int menu_status = 0, adminCount = 1, userCount, edit_index = 0, admin_index = 0;
char current_user[50];

void menu();
void signIn();
void login();
void med_survey();
void find_user();
void admin_login();
void admin_dashboard();
void edit_info();
void all_user();


void main(){
		menu();
	getch();
}
// NOTE: final layout?
void menu(){
	fail:
	clrscr();
	int op;
	cout << "Student Medical Logbook" << endl;
	cout << "1. Sign Up" << endl;
	cout << "2. Find a User" << endl;
	cout << "3. Admin Dashboard" << endl;
	cout << "4. Exit" << endl;
	cout << "> ";
	cin >> op;
	switch (op){
	case 1:
	signIn();
	break;
	case 2:
	find_user();
	break;
	case 3:
	admin_login();
	break;
	case 4:
	exit(0);
	break;
	default:
	cout << "Input Error!" << op; // NOTE: op = status checking
	getch();
	menu_status = 1;
	break;
	}
}
// TODO: suggest for optimisation
void signIn(){
// start fstream database
//ofstream activeUser("accounts.txt");
char username[25];
int user_exists = 1;
char activeAccounts;
cout << "Enter your Student Number: ";
cin >> username;
char *extension = ".txt";
strcat(username, extension); // concatenate student id (username) to .txt, ex. 202010891.txt
ifstream checkStudent(username); // fstream read mode
if (!checkStudent){
	ofstream createStudent(username); // fstream create database (.txt)
	strcpy(current_user, username);
	cout << "New user! Creating Account" << endl;
	user_exists = 0;
	
	createStudent.close(); // close stream
} else {
	cout << "User Already Exists!";
	getch();
	menu();
}
	 if (user_exists == 0){
		cout << "Enter your Name: ";
		gets(name);
		cout << "Enter your Age: ";
		cin >> age;
		cout << "Year and Section: ";
		gets(yr_sec);
		strcpy(st_num, username);
		ofstream activeUser("accounts.txt", ios::app); // ios::app = append mode 
		activeUser << "Name: " << name << " (Data Location: " << username << ")" << endl; // for admin use, registred user
		cout << "Sign up successful!";
	
	checkStudent.close();
	activeUser.close();
	 getch();
	 med_survey();
	 
	 }

}
// NOTE: no function, just for referrence
// START REFERRENCE
void login(){
char login_user[20], login_pass[20];
int login_check = 1;
cout << "Enter Username:\n >";
cin >> login_user;
cout << "Enter Password:\n >";
cin >> login_pass;
	for (int i = 0; i <= userCount; i++){
		if(strcmp(pass[i], login_pass) == 0 && strcmp(user[i], login_user) == 0){
			login_check = 0;
		}
	}
		if (login_check == 0){
			cout << "Login Success!";
			getch();
		} else {
			cout << "Login Failed!";
			getch();
			menu();
		}

}
// END REFERRENCE
// NOTE: survey info correct? -> commit changes
void med_survey(){
	clrscr();
	cout << "What is your Medical Profile" << endl;
	cout << "What is your Blood Type: \n";
	gets(blood_type);
	cout << "What are your Allergies (if any): \n";
	gets(allergies);
	cout << "Are you currently taking any medication? \n";
	gets(medcation_status);
	cout << "Have you had any major surgeries? \n";
	gets(sugery_status);
	cout << "What are your Medical Conditions? (if any): \n";
	gets(med_condition);
	cout << "Medical Profile Survey Finished!";
	userCount++;
	// start fstream input
	ofstream writeData(current_user);
	writeData << "Student Info" << endl;
	writeData << "Name: " << name << endl;
	writeData << "Age: " << age << endl;
	writeData << "Year and Section: " << yr_sec << endl;
	writeData << "" << endl;
	writeData << "Blood Type: " << blood_type << endl;
	writeData << "Allergies: " << allergies << endl;
	writeData << "Medication Status: " << medcation_status << endl;
	writeData << "Major Surgery History: " << sugery_status << endl;
	writeData << "Medical Conditions: " << med_condition << endl;
	writeData.close();
	getch();
	menu();


}
void find_user(){
	clrscr();
	char find_st[25];
	char *database = ".txt";
	cout << "Enter Student Number to search: ";
	cin >> find_st;
	strcat(find_st, database);
	ifstream findUser(find_st);
	if (findUser){
		clrscr();
		cout << "Student Medical Database" << endl;
		char data;
    	while (findUser.get(data)) {
       	 cout << data;
   		}
		cout << "\n";
		cout << "Press ENTER to EXIT" << endl;
		getch();
		menu();
	} else {
		cout << "User not found!";
		getch();
		menu();
	}
	findUser.close();
	getch();
}
// TODO: check for bugs
void admin_login(){
	clrscr();
	cout << "Admin Login" << endl;
	char login_user[20], login_pass[20];
	int login_check = 1;
	char st_edit[25];
	cout << "Enter Username: \n";
	cin >> login_user;
	cout << "Enter Password: \n";
	cin >> login_pass;
	for (int i = 0; i <= adminCount; i++){
		if(strcmp(pass[i], login_pass) == 0 && strcmp(user[i], login_user) == 0){
			login_check = 0;
			admin_index = i;
		}
	}
		if (login_check == 0){
			cout << "Login Success!";
			getch();
			admin_dashboard();

		} else {
			cout << "Login Failed!" << admin_index;
			getch();
			menu();
		}
		clrscr();
	
}
void edit_info(){
	clrscr();
	char *database = ".txt";
	char st_edit[25];
	cout << "Type the Student Number To edit: " << endl;
	cin >> st_edit;
	strcat(st_edit, database);
	ifstream readDatabase(st_edit);
	if (readDatabase){
		ofstream editInfo(st_edit);

		cout << "Medical Profile Edit Mode" << endl;
		cout << "Enter your Name: ";
		gets(name);
		cout << "Enter your Age: ";
		cin >> age;
		cout << "Year and Section: ";
		gets(yr_sec);

		clrscr();
		cout << "What is your Medical Profile" << endl;
		cout << "What is your Blood Type: ";
		gets(blood_type);
		cout << "What are your Allergies (if any): ";
		gets(allergies);
		cout << "Are you currently taking any medication? ";
		gets(medcation_status);
		cout << "Have you had any major surgeries? ";
		gets(sugery_status);
		cout << "What are your Medical Conditions? (if any): ";
		gets(med_condition);

		editInfo << "Student Info" << endl;
		editInfo << "Name: " << name << endl;
		editInfo << "Age: " << age << endl;
		editInfo << "Year and Section: " << yr_sec << endl;
		editInfo << "" << endl;
		editInfo << "Blood Type: " << blood_type << endl;
		editInfo << "Allergies: " << allergies << endl;
		editInfo << "Medication Status: " << medcation_status << endl;
		editInfo << "Major Surgery History: " << sugery_status << endl;
		editInfo << "Medical Conditions: " << med_condition << endl;
		cout << "Medical Profile Survey Finished!" << endl;
		editInfo.close();
		getch();
		menu();
	} else {
		cout << "User Not Found!";
		getch();
		menu();
	}
	readDatabase.close();
	getch();

}
void admin_dashboard() {
	clrscr();
	int option;
	cout << "Admin Dashboard: Logged in as " << user[admin_index] << endl;
	cout << "1. Edit User" << endl;
	cout << "2. Show All Registed User" << endl;
	cout << "3. Exit" << endl;
	cin >> option;
	switch(option){
		case 1:
		edit_info();
		 break;
		case 2:
		all_user();
		break;
		case 3:
		menu();
		break;
	}
}
void all_user(){
	clrscr();
	cout << "Showing All Registered User" << endl;
	ifstream readData("accounts.txt");
	char data;
	while (readData.get(data)) {
		cout << data;
    }
	cout << "\nPress ENTER to Exit" << endl;
	getch();
	menu();
	readData.close();
}
// TODO: optimise overall code
