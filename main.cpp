#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

// NOTE: hanni = hanni -> index: 0, rei = rei => index: 1
char user[100][100] = {"hanni", "rei"}, pass[100][100] = {"hanni", "rei"};

char name[100][100], yr_sec[25][100], st_num[25][100];

char blood_type[25][100], allergies[25][100], med_history[25][100],
med_condition[25][100], medcation_status[25][100], sugery_status[25][100];

int age[100];
int userCount = 0;
int edit_index = 0;

void menu();
void signIn();
void login();
void med_survey();
void find_user();
void edit_user();
void edit_info();


void main(){
	menu();
	getch();
}

void menu(){
	fail:
	clrscr();
	int op;
	cout << "Student Medical Logbook" << endl;
	cout << "1. Sign Up" << endl;
	cout << "2. Find a User" << endl;
	cout << "3. Edit User" << endl;
	cout << "4. Delete User" << endl;
	cout << "5. Exit" << endl;
	cout << ">" << endl;
	cin >> op;
	switch (op){
	case 1:
	signIn();
	break;
	case 2:
	find_user();
	break;
	case 3:
	edit_user();
	break;
	default:
	cout << "Input Error!" << op;
	break;
	}
}
void signIn(){
char username[20];
int user_exists = 0;
cout << "Enter your Student Number: ";
gets(username);
	for (int i = 0; i <= userCount; i++){
		if(strcmp(st_num[i], username) == 0){
		cout << "User Already Exists!";
		user_exists = 1;
		}
	 }
	 if (user_exists == 0){
		cout << "Enter your Name: ";
		gets(name[userCount]);
		cout << "Enter your Age: ";
		cin >> age[userCount];
		cout << "Year and Section: ";
		gets(yr_sec[userCount]);
		strcpy(st_num[userCount], username);
	 //cout << "Enter Password:\n > ";
	//
	 //cin >> pass[userCount];
	cout << "Sign up successful!";
	// 
	 getch();
	 med_survey();
	 }

}
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

void med_survey(){
	clrscr();
	cout << "What is your Medical Profile" << endl;
	cout << "What is your Blood Type: \n";
	gets(blood_type[userCount]);
	cout << "What are your Allergies (if any): \n";
	gets(allergies[userCount]);
	cout << "Are you currently taking any medication? \n";
	gets(medcation_status[userCount]);
	cout << "Have you had any major surgeries? \n";
	gets(sugery_status[userCount]);
	cout << "What are your Medical Conditions? (if any): \n";
	gets(med_condition[userCount]);
	cout << "Medical Profile Survey Finished!";
	userCount++;
	getch();
	menu();


}
void find_user(){
	char find_st[25];
	int found = 0;
	cout << "Enter Student Number to search: ";
	cin >> find_st;
	for (int i = 0; i < userCount; i++){
		if (strcmp(st_num[i], find_st) == 0){
			found = 1;
			// List Medication Record
			clrscr();
			cout << "Student Info" << endl;
			cout << "Name: " << name[i] << endl;
			cout << "Age: " << age[i] << endl;
			cout << "Year and Section: " << yr_sec[i] << endl;
			cout << "\n";
			cout << "Blood Type: " << blood_type[i] << endl;
			cout << "Allergies: " << allergies[i] << endl;
			cout << "Medication Status: " << medcation_status[i] << endl;
			cout << "Major Surgery History: " << sugery_status[i] << endl;
			cout << "Medical Conditions: " << med_condition[i] << endl;
			cout << "\n";
			cout << "Press ENTER to go back";
			getch();
			menu();
		}
	}
	if (found == 0){
		cout << "User not Found!";
		getch();
		menu();
	}

}
void edit_user(){
	clrscr();
	cout << "Admin Login" << endl;
	char login_user[20], login_pass[20];
	int login_check = 1;
	char st_edit[25];
	cout << "Enter Username: \n";
	cin >> login_user;
	cout << "Enter Password: \n";
	cin >> login_pass;
	for (int i = 0; i <= userCount; i++){
		if(strcmp(pass[i], login_pass) == 0 && strcmp(user[i], login_user) == 0){
			login_check = 0;
		}
	}
		if (login_check == 0){
			cout << "Login Success!";
			getch();
			edit_info();

		} else {
			cout << "Login Failed!";
			getch();
			menu();
		}
		clrscr();
	
}
void edit_info(){
	clrscr();
	int user_check = 0;
	char st_edit[25];
	cout << "Type the Student Number To edit: \n";
	cin >> st_edit;
	for (int x = 0; x <= userCount; x++){
		if (strcmp(st_num[x], st_edit) == 0){
			user_check = 1;
			edit_index = x;
		}
	}
	if (user_check == 1){
		cout << "User Found!";
		getch();
		clrscr();
		cout << "Medical Profile Edit Mode" << endl;
		cout << "What is your Blood Type: \n";
		gets(blood_type[edit_index]);
		cout << "What are your Allergies (if any): \n";
		gets(allergies[edit_index]);
		cout << "Are you currently taking any medication? \n";
		gets(medcation_status[edit_index]);
		cout << "Have you had any major surgeries? \n";
		gets(sugery_status[edit_index]);
		cout << "What are your Medical Conditions? (if any): \n";
		gets(med_condition[edit_index]);
		cout << "Medical Profile Survey Finished!\n";
		cout << edit_index;
		getch();
		menu();
	} else {
		cout << "User Not Found!" << x;
		getch();
		menu();
	}
}
