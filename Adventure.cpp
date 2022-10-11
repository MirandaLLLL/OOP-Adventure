#include<iostream>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<ctime>


using namespace std;

struct room {
	int east;
	int west;
	int north;
	int south;
};                         //set the room's exits have at most four directions 

int FindRoom(string direct, room BedRoom) {
	int number = -5;
	if (direct == "east")
		number = BedRoom.east;
	if (direct == "west")
		number = BedRoom.west;
	if (direct == "south")
		number = BedRoom.south;
	if (direct == "north")
		number = BedRoom.north;
	return number;
}

int main() {
	unsigned seed;// Random generator seed
	// Use the time function to get a "seed¡± value for srand
	seed = time(0);
	srand(seed);// Now generate 
	int Mroom, Proom;//Mroom is the number of room where the monster is ;Proom is the number of room where the princess is ;
	Mroom = rand() % 8;
	Proom = rand() % 8;
	while (Proom == Mroom) {
		Proom = rand() % 8 + 1;
	}                             // randomly choose the numbers of room to put the monster and princess into,respectively;

	room lobby;
	lobby.east = 0;
	lobby.south = 1;
	lobby.west = 2;
	lobby.north = 3;              //arrange the rooms around the lobby;

	room Room[8];                 //set 8 rooms in this castle besides the lobby;

	Room[2].north = 4;
	Room[4].south = 2;
	Room[2].south = 7;
	Room[7].north = 2;
	Room[2].east = -1;
	Room[4].east = 3;
	Room[3].west = 4;
	Room[3].east = 5;
	Room[5].west = 3;
	Room[3].south = -1;
	Room[5].south = 0;
	Room[0].north = 5;
	Room[0].west = -1;
	Room[0].south = 6;
	Room[6].north = 0;
	Room[6].west = 1;
	Room[1].east = 6;
	Room[1].north = -1;
	Room[1].west = 7;
	Room[7].east = 1;      //arrange each room with its exits and the rooms which the exits are connected with;
						   //"-1" represents the lobby;

	cout << "Welcome to the lobby. There are 4 exits: east, west, south and north." << endl;
	cout << "Enter your command:" << endl;

	string go;
	string direction;
	cin >> go >> direction;


	int EnterRoom;
	int judge = 0;// to judge if the player come back with the princess;
	EnterRoom = FindRoom(direction, lobby); //using this function to find the which room the player enters;
	while (EnterRoom <-1||(EnterRoom>7)) {
		cout << "Cannot be identified. Please input again." << endl;
		cin >> go >> direction;
		EnterRoom = FindRoom(direction, lobby);
	}

	while (1) {
		if (EnterRoom == Mroom) {
			cout << "Welcome to Room" << EnterRoom << ". ";
			cout << "What a pity! There is a monster in this room." << endl;
			cout << "Game Over.";
			system("pause");
			return 0;
		}                                       //if the player enter the room which has the monster, game over;
		else {
			if (EnterRoom == -1) {
				cout << "Welcome to the lobby. ";
				if (judge == 1) {
					cout << "Congratulations! You find the way to get out of the castle and succed in rescueing the princess" << endl;
					system("pause");
					return 0;
				}
			}
			else
				cout << "Welcome to Room" << EnterRoom << ". ";
			if (EnterRoom == Proom && (judge == 0)) {
				cout << "Congratulations! You find the princess here." << endl;
				cout << "Now you need to find out the way to get out via the lobby with the princess." << endl;
				cout << "hint: you can return along the route you came to this room." << endl;
				judge = 1;
			}                                   //if the player enter the room which has the princess;
			cout << "Please continue." << endl;
			if (EnterRoom == 0)
				cout << "There are 3 exits: west, south and north." << endl;
			if (EnterRoom == 1)
				cout << "There are 3 exits: east, west, and north." << endl;
			if (EnterRoom == 2)
				cout << "There are 3 exits: east, south, and north." << endl;
			if (EnterRoom == 3)
				cout << "There are 3 exits: east, west, and south." << endl;
			if (EnterRoom == 4)
				cout << "There are 2 exits: east and south." << endl;
			if (EnterRoom == 5)
				cout << "There are 2 exits: west and south." << endl;
			if (EnterRoom == 6)
				cout << "There are 2 exits: west and north." << endl;
			if (EnterRoom == 7)
				cout << "There are 2 exits: east and north." << endl;
			if (EnterRoom == -1)
				cout << "There are 4 exits: east, west, south and north." << endl;
			cout << "Enter your command:" << endl;

		}
		cin >> go >> direction;

		room BedRoom;
		if (EnterRoom == -1)
			BedRoom = lobby;
		else
			BedRoom = Room[EnterRoom];
		EnterRoom = FindRoom(direction, BedRoom);
		while (EnterRoom <-1||(EnterRoom>7)) {
			cout << "Cannot be identified. Please input again." << endl;
			cin >> go >> direction;
			EnterRoom = FindRoom(direction, BedRoom);
		}
	}
}
