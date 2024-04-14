#include <iostream>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

Font Satoshi_Black, Satoshi_BlackItalic, Satoshi_Bold, Satoshi_BoldItalic, Satoshi_Italic, Satoshi_Light, Satoshi_LightItalic, Satoshi_Medium, Satoshi_MediumItalic, Satoshi_Regular;
Texture headerTexture, closeTexture, mininmizeTexture, optionsTexture, backgroundTexture, bigButtonTexture, smallButtonTexture, darkBackgroundTexture, darkBackgroundLargeTexture, darkBackgroundSmallTexture, enterValuesBackgroundTexture;

const int MaxUsers = 100;
const int MaxSub = 100;
int numUsers = 2;
int numSub = 2;
struct Account {
	string email;
	string password;
};
struct Subscription {
	string subName;
	int ValidityDays;
	float SubPrice;
	int index;
};
struct User {
	int id;
	Account UserAccount;
	float Balance;
	Subscription Sub;

};
struct Header {
    Sprite background;
    Text user, metro;
};
struct signUpBox {
    Sprite background;
    Sprite valueField1;
    Sprite valueField2;
    Sprite valueField3;
    Sprite valueField4;
    Sprite valueField5;
    Sprite button1;
    Text buttonText1;
    Text value1;
    Text value2;
    Text value3;
    Text value4;
    Text value5;
    Text heading1;
    Sprite button2;
    Text signIn;

};

struct signInBox {
    Sprite background;
    Sprite valueField1;
    Sprite valueField2;
    Sprite button1;
    Text buttonText1;
    Text value1;
    Text value2;
    Text heading1;
    Sprite button2;
    Text signUp;

};
void TexturesAndFonts();
void drawHeader(Header header);
void setHeader(Header& header);        
void drawSignIn(signInBox box);      
void setSingIn(signInBox& box);        // by reference to implement in the main function
void drawSignUp(signUpBox box);
void setSingUp(signUpBox& box);

Subscription UsersSubscriptionTypes[MaxSub];
User users[MaxUsers];
void GetCurrentTime() {
	cout << __TIME__;

}
void CurrentDateAndTime() {
	// current date and time on the current system
	time_t now = time(0);

	string CurrentDateAndTime = ctime(&now);
	cout << CurrentDateAndTime;
}
void GetCurrentDate() {
	cout << __DATE__;
	
}
void ViewUsersAccounts(User users[MaxUsers], int numUsers) {
	cout << "Accounts:\n";
	for (int i = 0; i < numUsers; i++) {
		cout << "Email: " << users[i].UserAccount.email << "\n";
	}
}
void EditUsersAccounts(User users[MaxUsers], int numUsers, int id) {
	string NewEmail;
	for (int i = 0; i < numUsers;i++) {
		if (id == users[i].id) {
			cout << "Enter the new email for the user:" << endl;
			cin >> NewEmail;
			users[i].UserAccount.email = NewEmail;
			return;
		}
	}
	cout << "User Not Found";
	
}
void DeleteUsersAccounts(User users[MaxUsers], int &numUsers, int id) {
	for (int i = 0; i < numUsers; i++) {
		if (id == users[i].id) {

			users[i] = users[i + 1];
			numUsers = numUsers - 1; // Decrement the count of users
			cout << "User account deleted successfully!\n";
			return;


			cout << "User not found!\n";




		}
	}
}
void CreateNewPlan(Subscription UserSubscriptionTypes[], int& numSub) {
	string newName;
	int newValidityDays;
	float newPrice;
	int NewIndex;
	bool IndexExists = false;

	cin >> newName;
	cin >> newValidityDays;
	cin >> newPrice;
	cin >> NewIndex;

	if (numSub <= 100) {
		UserSubscriptionTypes[numSub].subName = newName;
		UserSubscriptionTypes[numSub].ValidityDays = newValidityDays;
		UserSubscriptionTypes[numSub].SubPrice = newPrice;

		// Check for existing index throughout all elements
		for (int i = 0; i < numSub; i++) {
			if (UserSubscriptionTypes[i].index == NewIndex) {
				IndexExists = true;
				break;
			}
		}

		while (IndexExists) {
			cout << "Subscription index already exists. Please enter a new index: ";
			cin >> NewIndex;

			IndexExists = false;
			for (int i = 0; i < numSub; i++) {
				if (UserSubscriptionTypes[i].index == NewIndex) {
					IndexExists = true;
					break;
				}
			}
		}

		UserSubscriptionTypes[numSub].index = NewIndex;
		numSub++;
	}
	else {
		cout << "Maximum number of subscription plans reached.\n";
	}
}
void ModifySubscriptionAdmin(Subscription UsersSubscriptionTypes[],int index,int numSubscriptions) {
	string newName;
	int newValidityDays;
	float newPrice;
	int NewIndex;
	bool IndexExists;
	cin >> newName;
	cin >> newValidityDays;
	cin >> newPrice;
	cin >> NewIndex;
	for (int i = 0; i < numSub;i++) {
		if (index==UsersSubscriptionTypes[i].index) {
			UsersSubscriptionTypes[i].subName = newName;
			UsersSubscriptionTypes[i].ValidityDays = newValidityDays;
			UsersSubscriptionTypes[i].SubPrice = newPrice;
			bool IndexExists = false;
			for (int i = 0; i < numSub; i++) {
				if (UsersSubscriptionTypes[i].index == NewIndex) {
					IndexExists = true;
					
				}
				else {
					UsersSubscriptionTypes[i].index = NewIndex;
				}
			}

			while (IndexExists) {
				cout << "Subscription index already exists. Please enter a new index: ";
				cin >> NewIndex;

				IndexExists = false;
				for (int i = 0; i < numSub; i++) {
					if (UsersSubscriptionTypes[i].index == NewIndex) {
						IndexExists = true;
						break;
					}
				}
			}
			

						
		}
	}
	
}
void DeleteSubscriptions(Subscription UsersSubscriptionTypes[], int& numSub, int index) {
	for (int i = 0; i < numSub; i++) {
		if (index == users[i].id) {

			UsersSubscriptionTypes[i] = UsersSubscriptionTypes[i + 1];
			numSub = numSub - 1; // Decrement the count of users
			cout << "User Subscription Plan deleted successfully!\n";
			return;

						
			cout << "Subscription Plan not found!\n";




		}
	}
}
int main() {
	
}


void TexturesAndFonts() {
    Satoshi_Black.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_Black.otf");
    Satoshi_BlackItalic.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_BlackItalic.otf");
    Satoshi_Bold.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_Bold.otf");
    Satoshi_BoldItalic.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_BoldItalic.otf");
    Satoshi_Italic.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_Italic.otf");
    Satoshi_Light.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_Light.otf");
    Satoshi_LightItalic.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_LightItalic.otf");
    Satoshi_Medium.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_Medium.otf");
    Satoshi_MediumItalic.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_MediumItalic.otf");
    Satoshi_Regular.loadFromFile("D:/FCIS Project/1st year/SP project/Fonts/Satoshi_Regular.otf");
    headerTexture.loadFromFile("D:/FCIS Project/1st year/SP project/Textures/headerTexture.jpg");
    darkBackgroundLargeTexture.loadFromFile("D:/FCIS Project/1st year/SP project/Textures/2.png");
    smallButtonTexture.loadFromFile("D:/FCIS Project/1st year/SP project/Textures/smallButtonTexture.png");
    enterValuesBackgroundTexture.loadFromFile("D:/FCIS Project/1st year/SP project/Textures/enterValuesBackgroundTexture.png");
}
void drawHeader(Header header) {
    window.draw(header.background);
    window.draw(header.user);
    window.draw(header.metro);

}
void setHeader(Header& header) {
    header.background.setTexture(headerTexture);  
    header.background.setPosition(0,-70);
    header.background.setScale(1.5,.3);
    header.user.setFont(Satoshi_Black);
    header.user.setString("User");
    header.user.setCharacterSize(60);
    header.user.setPosition(100, 60);
    header.metro.setFont(Satoshi_Bold);
    header.metro.setString("MetroMate");
    header.metro.setCharacterSize(70);
    header.metro.setPosition(1920 /2 -200, 25);

}
void drawSignIn(signInBox box) {
    window.draw(box.background);
    window.draw(box.valueField1);
    window.draw(box.valueField2);
    window.draw(box.button1);
    window.draw(box.buttonText1);
    window.draw(box.value1);
    window.draw(box.value2);
    window.draw(box.heading1);
    window.draw(box.button2);
    window.draw(box.signUp);


}
void drawSignUp(signUpBox box) {
    window.draw(box.background);
    window.draw(box.valueField1);
    window.draw(box.valueField2);
    window.draw(box.valueField3);
    window.draw(box.valueField4);
    window.draw(box.valueField5);
    window.draw(box.button1);
    window.draw(box.buttonText1);
    window.draw(box.value1);
    window.draw(box.value2);
    window.draw(box.value3);
    window.draw(box.value4);
    window.draw(box.value5);
    window.draw(box.heading1);
    window.draw(box.button2);
    window.draw(box.signIn);


}

void setSingIn(signInBox& box) {

    box.background.setTexture(darkBackgroundLargeTexture);
    box.background.setScale( 1.3,1);
    box.background.setPosition(1920/2 , 1080/2 + 25);
    box.background.setOrigin(box.background.getLocalBounds().width/2, box.background.getLocalBounds().height / 2); // to change the origin point to the center instead of the top left.
    box.button1.setTexture(smallButtonTexture); 
    box.button1.setOrigin(box.button1.getLocalBounds().width / 2, box.button1.getLocalBounds().height / 2);
    box.button1.setPosition(1920 / 2 + 400, 1080 / 2 + 200);
    box.button1.setScale(.11, .11);
    box.buttonText1.setFont(Satoshi_Medium);
    box.buttonText1.setString("Sign In");
    box.buttonText1.setCharacterSize(30);
    box.buttonText1.setOrigin(box.buttonText1.getLocalBounds().width / 2, box.buttonText1.getLocalBounds().height / 2);
    box.buttonText1.setPosition(box.button1.getPosition().x -5 ,box.button1.getPosition().y - 5 );
    box.value1.setFont(Satoshi_Regular);
    box.value1.setCharacterSize(28);
    box.value1.setString("Email: ");
    box.value1.setOrigin(box.value1.getLocalBounds().width / 2, box.value1.getLocalBounds().height / 2);
    box.value1.setPosition(1920 / 2 + 50, 1080 / 2 -100);
    box.value2.setFont(Satoshi_Regular);
    box.value2.setCharacterSize(28);
    box.value2.setString("Password: ");
    box.value2.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value2.setPosition(1920 / 2 + 50, 1080 / 2);
    box.valueField1.setTexture(enterValuesBackgroundTexture);
    box.valueField1.setScale(1.7, .9);
    box.valueField1.setOrigin(box.valueField1.getLocalBounds().width / 2, box.valueField1.getLocalBounds().height / 2);
    box.valueField1.setPosition(box.value1.getPosition().x + 340, box.value1.getPosition().y + 20);
    box.valueField2.setTexture(enterValuesBackgroundTexture);
    box.valueField2.setScale(1.7, .9);
    box.valueField2.setOrigin(box.valueField2.getLocalBounds().width / 2, box.valueField2.getLocalBounds().height / 2);
    box.valueField2.setPosition(box.value2.getPosition().x + 340, box.value2.getPosition().y + 20);
    box.heading1.setFont(Satoshi_BoldItalic);
    box.heading1.setCharacterSize(32);
    box.heading1.setString("Dont have an account? ");
    box.heading1.setOrigin(box.heading1.getLocalBounds().width / 2, box.heading1.getLocalBounds().height / 2);
    box.heading1.setPosition(box.value1.getPosition().x -440, box.value1.getPosition().y );
    box.button2.setTexture(smallButtonTexture);
    box.button2.setOrigin(box.button2.getLocalBounds().width / 2, box.button2.getLocalBounds().height / 2);
    box.button2.setPosition(box.value2.getPosition().x - 440, box.value2.getPosition().y);
    box.button2.setScale(.11, .11);
    box.signUp.setFont(Satoshi_Medium);
    box.signUp.setString("Sign Up");
    box.signUp.setCharacterSize(30);
    box.signUp.setOrigin(box.signUp.getLocalBounds().width / 2, box.signUp.getLocalBounds().height / 2);
    box.signUp.setPosition(box.button2.getPosition().x - 5, box.button2.getPosition().y - 5);


}

void setSingUp(signUpBox& box) {

    box.background.setTexture(darkBackgroundLargeTexture);
    box.background.setScale(1.45, 1);
    box.background.setPosition(1920 / 2, 1080 / 2 + 25);
    box.background.setOrigin(box.background.getLocalBounds().width / 2, box.background.getLocalBounds().height / 2);
    box.value1.setFont(Satoshi_Regular);
    box.value1.setCharacterSize(28);
    box.value1.setString("      Username: ");
    box.value1.setOrigin(box.value1.getLocalBounds().width / 2, box.value1.getLocalBounds().height / 2);
    box.value1.setPosition(1920 / 2 + 50, 1080 / 2 -300);
    box.value2.setFont(Satoshi_Regular);
    box.value2.setCharacterSize(28);
    box.value2.setString("Email: ");
    box.value2.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value2.setPosition(1920 / 2 + 50, 1080 / 2 -200);
    box.value3.setFont(Satoshi_Regular);
    box.value3.setCharacterSize(28);
    box.value3.setString("Password: ");
    box.value3.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value3.setPosition(1920 / 2 + 50, 1080 / 2 - 100);
    box.value4.setFont(Satoshi_Regular);
    box.value4.setCharacterSize(28);
    box.value4.setString("Confirm Password: ");
    box.value4.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value4.setPosition(1920 / 2 + 50, 1080 / 2 );
    box.value5.setFont(Satoshi_Regular);
    box.value5.setCharacterSize(28);
    box.value5.setString("Balance: ");
    box.value5.setOrigin(box.value2.getLocalBounds().width / 2, box.value2.getLocalBounds().height / 2);
    box.value5.setPosition(1920 / 2 + 50, 1080 / 2 + 100);
    box.valueField1.setTexture(enterValuesBackgroundTexture);
    box.valueField1.setScale(1.9, .9);
    box.valueField1.setOrigin(box.valueField1.getLocalBounds().width / 2, box.valueField1.getLocalBounds().height / 2);
    box.valueField1.setPosition(box.value1.getPosition().x + 450, box.value1.getPosition().y + 20);
    box.valueField2.setTexture(enterValuesBackgroundTexture);
    box.valueField2.setScale(1.9, .9);
    box.valueField2.setOrigin(box.valueField2.getLocalBounds().width / 2, box.valueField2.getLocalBounds().height / 2);
    box.valueField2.setPosition(box.value2.getPosition().x + 450, box.value2.getPosition().y + 20);
    box.valueField3.setTexture(enterValuesBackgroundTexture);
    box.valueField3.setScale(1.9, .9);
    box.valueField3.setOrigin(box.valueField3.getLocalBounds().width / 2, box.valueField3.getLocalBounds().height / 2);
    box.valueField3.setPosition(box.value3.getPosition().x + 450, box.value3.getPosition().y + 20);
    box.valueField4.setTexture(enterValuesBackgroundTexture);
    box.valueField4.setScale(1.9, .9);
    box.valueField4.setOrigin(box.valueField4.getLocalBounds().width / 2, box.valueField4.getLocalBounds().height / 2);
    box.valueField4.setPosition(box.value4.getPosition().x + 450, box.value4.getPosition().y + 20);
    box.valueField5.setTexture(enterValuesBackgroundTexture);
    box.valueField5.setScale(1.9, .9);
    box.valueField5.setOrigin(box.valueField5.getLocalBounds().width / 2, box.valueField5.getLocalBounds().height / 2);
    box.valueField5.setPosition(box.value5.getPosition().x + 450, box.value5.getPosition().y + 20);
    box.button1.setTexture(smallButtonTexture);
    box.button1.setOrigin(box.button1.getLocalBounds().width / 2, box.button1.getLocalBounds().height / 2);
    box.button1.setPosition(1920 / 2 + 500, 1080 / 2 + 250);
    box.button1.setScale(.11, .11);
    box.buttonText1.setFont(Satoshi_Medium);
    box.buttonText1.setString("Register");
    box.buttonText1.setCharacterSize(30);
    box.buttonText1.setOrigin(box.buttonText1.getLocalBounds().width / 2, box.buttonText1.getLocalBounds().height / 2);
    box.buttonText1.setPosition(box.button1.getPosition().x - 5, box.button1.getPosition().y - 5); box.heading1.setFont(Satoshi_BoldItalic);
    box.heading1.setCharacterSize(32);
    box.heading1.setString("Already have an account? ");
    box.heading1.setOrigin(box.heading1.getLocalBounds().width / 2, box.heading1.getLocalBounds().height / 2);
    box.heading1.setPosition(box.value3.getPosition().x - 500, box.value3.getPosition().y);
    box.button2.setTexture(smallButtonTexture);
    box.button2.setOrigin(box.button2.getLocalBounds().width / 2, box.button2.getLocalBounds().height / 2);
    box.button2.setPosition(box.heading1.getPosition().x , box.heading1.getPosition().y + 100);
    box.button2.setScale(.11, .11);
    box.signIn.setFont(Satoshi_Medium);
    box.signIn.setString("Sign In");
    box.signIn.setCharacterSize(30);
    box.signIn.setOrigin(box.signIn.getLocalBounds().width / 2, box.signIn.getLocalBounds().height / 2);
    box.signIn.setPosition(box.button2.getPosition().x - 5, box.button2.getPosition().y - 5);


}




