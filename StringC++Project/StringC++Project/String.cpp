#include <iostream>
using namespace std;

// class: User
// fields: username, password

// class: Database
// field: User* users(array)
// field: int size;

// method: bool SignIn(User)
// method: bool SignUp(User)
// method: User GetUserByUsername(username)


class User {
	string username;
	string password;
public:
	User() {}

	User(string username, string password) {
		SetUserName(username);
		SetPassword(password);
	}


	User& operator=(User& other) {
		SetUserName(other.username);
		SetPassword(other.password);
	}



	void SetUserName(string username) {
		this->username = username;
	}

	void SetPassword(string password) {
		this->password = password;
	}

	friend class Database;

	string GetUserName() const { return username; }
	string GetPassword() const { return password; }
};


class Database {
	User* users = nullptr;
	int size = 0;
public:

	Database() :size(0), users(nullptr) {}

	Database(User* users) :Database() {
		SetUsers(users);
	}

	Database(User* users, int size) :Database(users) {
		SetSize(size);
	}

	void SetUsers(User* users) {
		this->users = users;
	}

	void SetSize(int size) {
		this->size = size;
	}

	User* GetUsers()const { return users; }

	int GetSize() { return size; }


	// 1

	bool SignIn(User user) {
		for (int i = 0; i < size; i++) {
			if (users[i].username == user.username && users[i].password == user.password) {
				return 1;
			}
		}
		for (int i = 0; i < size; i++) {
			if (users[i].username != user.username && users[i].password != user.password) {
				return 0;
			}
		}
	}



	// 2

	bool SignUp(User user) {

		for (int i = 0; i < size; i++) {
			if (users[i].username != user.username && users[i].password != user.password) {
				User* temp = new User[size + 1];
				for (int j = 0; j < size; j++) {
					temp[i].SetUserName(users[i].GetUserName());
					temp[i].SetPassword(users[i].GetPassword());
				}

				temp[size].username = user.username;
				temp[size].password = user.password;


				delete[] users;
				users = temp;
				size++;
				temp = nullptr;
				return 1;
			}
		}
	}


	// 3

	User GetUserByUsername(string username) {
		for (int i = 0; i < size; i++) {
			if (users[i].username == username) {
				return users[i];
			}
		}
	}

	~Database() {
		delete[] users;
	}

};


void main() {
	User user1("togrul", "12345");
	User user2("Hakuna", "matata");
	User user3("Hakunaa", "matataa");


	User* users = new User[2]{ user1, user2 };

	Database d(users, 2);
	//cout << d.SignIn(user3);
	//cout << d.SignUp(user3);
	//d.GetUserByUsername("togrul");
}