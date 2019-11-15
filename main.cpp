#include <iostream>
#include <fstream>
#include <string>
#include<time.h>

using namespace std;

void findFile(string file);
void saveFile(string file, int woom);
void loadFile(string file, string data);

void arena();
int damageCalc(string type);
void monster();
void block(int attack);
void shop(bool swordspawn, bool loop);
void attack(string weaponslot);
int moneycalc(string type);

string inventory[] = { "Empty","Empty","Empty","Empty","Empty" };
string armor[] = { "Empty","Empty","Empty","Empty" };
int health = 100;
int monsterhealth;
int monstersfought;
int money = 0;
int potatodamage = 0;


int main() {
	srand(time(NULL));
	int gamestate = 0, menu = 0, woom = 0, slot, shopprisces[] = { 9000, 0, 10, 30, 0 }, keyslot = -1;
	int foundwoom = 0;
	bool swordspawn = true;
	bool keyspawn = true;
	bool potato = false;
	string input;
	string answer;
	string shopitems[] = { "God Tier Armor", "Potato", "Stick", "Ball", "Instant Crash", "[Out Of Stock]" };
	string shopprices[] = { "9000", "Free", "10", "30", "Free" };
	while (health > 0) {
		switch (menu) {
		case 0:
			cout << "-1- Start --\n-2- Open Save File --\n\n\np.s All items are needed to win!" << endl;
			getline(cin, input);
			if (input == "Start" || input == "1"){
				menu = 1;
		}
			if (input == "Open Save File" || input == "2") {
				menu = 2;
			}
			if (input == "Georgi Dimitrov") {
				exit(0);
			}
			break;
			
			case 1:
				cout << "Starting Game...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLoading..." << endl;
				menu = 4;
				if (foundwoom == 0) {
					woom = 1;
				}
				else {
					woom = foundwoom;
				}
			break;

			case 2:
				cout << "Loading Save Files...\n" << endl;
				findFile("save1.txt");
				findFile("save2.txt");
				findFile("save3.txt");
				findFile("save4.txt");
				findFile("save5.txt");
				cout << "\nEnter File Name To Load it! -------- Enter E To Exit" << endl;
				getline(cin, input);

				if (input == "save1" || input == "save1.txt") {
					ifstream myfile;
					myfile.open("save1.txt");
					cout << "Loading Map Placement!" << endl;
					myfile >> foundwoom;
					cout << "Loading Inventory!" << endl;
					for (int i = 0; i < 5; i++) {
						getline(myfile, inventory[i]);
						cout << "\nSlot " << i << ": " << inventory[i] << "\n" << endl;
					}
				}
				if (input == "save2" || input == "save2.txt") {
					ifstream myfile;
					myfile.open("save2.txt");
					cout << "Loading Map Placement!" << endl;
					myfile >> woom;
					cout << "Loading Inventory!" << endl;
					for (int i = 0; i < 5; i++) {
						getline(myfile, inventory[i]);
						cout << "\nSlot " << i << ": " << inventory[i] << "\n" << endl;
					}
				}
				if (input == "save3" || input == "save3.txt") {
					ifstream myfile;
					myfile.open("save3.txt");
					cout << "Loading Map Placement!" << endl;
					myfile >> woom;
					cout << "Loading Inventory!" << endl;
					for (int i = 0; i < 5; i++) {
						getline(myfile, inventory[i]);
						cout << "\nSlot " << i << ": " << inventory[i] << "\n" << endl;
					}
				}
				if (input == "save4" || input == "save4.txt") {
					ifstream myfile;
					myfile.open("save4.txt");
					cout << "Loading Map Placement!" << endl;
					myfile >> woom;
					cout << "Loading Inventory!" << endl;
					for (int i = 0; i < 5; i++) {
						getline(myfile, inventory[i]);
						cout << "\nSlot " << i << ": " << inventory[i] << "\n" << endl;
					}
				}
				if (input == "save5" || input == "save5.txt") {
					ifstream myfile;
					myfile.open("save5.txt");
					cout << "Loading Map Placement!" << endl;
					myfile >> woom;
					cout << "Loading Inventory!" << endl;
					for (int i = 0; i < 5; i++) {
						getline(myfile, inventory[i]);
						cout << "\nSlot " << i << ": " << inventory[i] << "\n" << endl;
					}
				}
				if (input == "E" || input == "e" || input == "exit" || input == "Exit")
					menu = 0;
			break;
		}//menu switch
		if (!woom == 0) {
			cout << "\nHealth: " << health << " \nMoney: " << money  << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
		}
		if (potato) {
			potatodamage = potatodamage + 5;
			health = health - 5;
			cout << "You are getting eaten by the potato! Health is now at " << health << "\nPs the turret will turn the potato into mashed potato\n" << endl;
		}
		switch (woom) {
			case 1: 
				cout << "You wake up and pick up a potato nearby....\nThe room is dark but the potato is... glowing\nyou walk down a pair of staircases but fall through them" << endl;
				inventory[1] = "Glowing Potato";
				woom = 2;
				system("pause");
			break;
			case 2:
				cout << "\nYou're Now in a basement...\n" << endl;
				system("pause");
				woom++;
			break;
			case 3:
				cout << "\nThere is a door leading lower into the basement\nWould You Like To Continue" << endl;
				getline(cin, answer);
				if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y") {
					cout << "\nYou open the door and feel some regret. you are worried and hear a sound\n" << endl;
					woom++;
				}
				else {
					cout << "\nWelp the floor cracks and you fall even lower\n" << endl;
					woom++;
				}
				
				break;
			case 4:
				cout << "\nYou can see a light east and west from you.\nWhere would you want to go? (East, West || e, w)" << endl;
				
				getline(cin, answer);
				if (answer == "East" || answer == "east" || answer == "e" || answer == "E" || answer == "EAST") {
					woom = 5;
				}
				if (answer == "West" || answer == "west" || answer == "w" || answer == "W" || answer == "WEST") {
					woom = 6;
				}
				break;
			case 5:
				cout << "You can't see a thing but you feel a door (South || West || S || W)." << endl;
				getline(cin, answer);
					if (answer == "South" || answer == "south" || answer == "s" || answer == "S" || answer == "SOUTH") {
						woom = 6;
					}
				if (answer == "West" || answer == "west" || answer == "w" || answer == "W" || answer == "WEST") {
					woom = 4;
				}
				break;
			case 6: 
				cout << "There is a loud bang. The Door Infront of you just got barricated. Fortunately there is another door. (South || East || S || E)" << endl;
				if (keyspawn) {
					cout << "You See A Broken Sword Decide to pick it up and set it as your weapon" << endl;
					keyspawn = false;
					inventory[0] = "Broken Sword";
				}
				getline(cin, answer);
				if (answer == "East" || answer == "east" || answer == "e" || answer == "E" || answer == "EAST") {
					woom = 4;
				}
				if (answer == "South" || answer == "south" || answer == "s" || answer == "S" || answer == "SOUTH") {
					woom = 7;
				}
				break;
			case 7:
				cout << "You feel a shiver and slowly see the ground. Now you look stupid.... (East || North || E || N)" << endl;
				getline(cin, answer);
				if (answer == "East" || answer == "east" || answer == "e" || answer == "E" || answer == "EAST") {
					woom = 9;
				}
				if (answer == "North" || answer == "north" || answer == "n" || answer == "N" || answer == "NORTH") {
					woom = 6;
				}
				break;
			case 8:
				cout << "A friendly turret is in the room. There is a vault door That has a keyhole. (West || South || W || S)" << endl;
				if (potato) {
					health = health + potatodamage;
					cout << "The turret turns red, you think it is targeting you and you see water come out. The potato is now a mashed potato and you eat it for " << potatodamage << " Health. You're now at " << health << " Health" << endl;
					potatodamage = 0;
					potato = false;
				}
						if (inventory[0] == "Key") {
							keyslot = 0;
							cout << "You have a key, and are curious to try it. (Open)" << endl;
						}
					
						if (inventory[1] == "Key") {
							keyslot = 1;
							cout << "You have a key, and are curious to try it. (Open)" << endl;
						}
						
						if (inventory[2] == "Key") {
							keyslot = 2;
							cout << "You have a key, and are curious to try it. (Open)" << endl;
						}
					
						if (inventory[3] == "Key") {
							keyslot = 3;
							cout << "You have a key, and are curious to try it. (Open)" << endl;
						}
						
						if (inventory[4] == "Key") {
							keyslot = 4;
							cout << "You have a key, and are curious to try it. (Open)" << endl;
						}
				 getline(cin, answer);
				 if (keyslot != -1 && answer == "Open" || keyslot != -1 && answer == "open" || keyslot != -1 && answer == "O" || keyslot != -1 && answer == "o") {
					 cout << "You open the door and see a endless void. You think to yourself, 'Should i keep going?' (Yes || No) \nP.S: You cannot revert from this point on!\nP.S x2: You will need a weapon!.\n\nThis is a save point (save)" << endl;
					 getline(cin, answer);
					 if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "y" || answer == "Y") {
						 cout << "\nYou go through the door and feel some regret. you are worried\n" << endl;
						 arena();
						 woom = 14;
					 }
					 if (answer == "save") {
						 cout << "save1 - save5" << endl;
						 getline(cin, answer);
						 if (answer == "save1" || answer == "save1.txt") {
							 saveFile("save1.txt", woom);
						 }
						 if (answer == "save2" || answer == "save2.txt") {
							 saveFile("save2.txt", woom);
						 }
						 if (answer == "save3" || answer == "save3.txt") {
							 saveFile("save3.txt", woom);
						 }
						 if (answer == "save4" || answer == "save4.txt") {
							 saveFile("save4.txt", woom);
						 }
						 if (answer == "save5" || answer == "save5.txt") {
							 saveFile("save5.txt", woom);
						 }
					 }
					 if (answer == "no" || answer == "NO" || answer == "No") {
						 cout << "Thats A Nope" << endl;
						 woom = 8;
					 }
				 }
				if (answer == "South" || answer == "south" || answer == "s" || answer == "S" || answer == "SOUTH") {
					woom = 12;
				}
				if (answer == "West" || answer == "west" || answer == "w" || answer == "W" || answer == "WEST") {
					woom = 13;
				}
				break;
			case 9:
				cout << "Something is banging the wall. You see a crack expand. (South || West || S || W)" << endl;
				if (swordspawn) {
					cout << "You notice a key in the ground. (P to pick it up)" << endl;
				}
				getline(cin, answer);
				if (swordspawn && answer == "P" || swordspawn && answer == "p" || swordspawn && answer == "pick up") {
					cout << "\n\nItem Picked Up\n\nWhat inventory slot would you like to set it to? (0-4)" << endl;
					cin >> slot;
					if (slot >= 5) {
						cout << "This number is too big." << endl;
						cin >> slot;
					}
					if (inventory[slot] != "Empty") {
						cout << "This slot is not empty." << endl;
						cin >> slot;
					}
					inventory[slot] = "Key";
					swordspawn = false;
				}
				if (answer == "South" || answer == "south" || answer == "s" || answer == "S" || answer == "SOUTH") {
					woom = 10;
				}
				if (answer == "West" || answer == "west" || answer == "w" || answer == "W" || answer == "WEST") {
					woom = 7;
				}
				break;
			case 10:
				cout << "Something is chasing you." << endl;
				if (potato == false) {
					cout << " A Potato Gets On Your Leg. (South || North || S || N)" << endl;
					potato = true;
				}
				else {
					cout << " (South || North || S || N)" << endl;
				}
				getline(cin, answer);
				if (answer == "South" || answer == "south" || answer == "s" || answer == "S" || answer == "SOUTH") {
					woom = 11;
				}
				if (answer == "North" || answer == "north" || answer == "n" || answer == "N" || answer == "NORTH") {
					woom = 9;
				}
				break;
			case 11:
				cout << "Nice green corner. Not bad at all. Other than the fact its green. (North || West || N || W)" << endl;
				getline(cin, answer);
				if (answer == "North" || answer == "north" || answer == "n" || answer == "N" || answer == "NORTH") {
					woom = 10;
				}
				if (answer == "West" || answer == "west" || answer == "w" || answer == "W" || answer == "WEST") {
					woom = 12;
				}
					break;
			case 12:
				cout << "Nice Red corner. Not bad at all but its off that there is a green one. (North || East || N || E)" << endl;
				getline(cin, answer);
				if (answer == "North" || answer == "north" || answer == "n" || answer == "N" || answer == "NORTH") {
					woom = 8;
				}
				if (answer == "East" || answer == "east" || answer == "e" || answer == "E" || answer == "EAST") {
					woom = 11;
				}
				break;
			case 13: 
				cout << "Welcome to my shop! (E to exit)\nThe shops items are\n0) " << shopitems[0] << "\n1) " << shopitems[1] << "\n2) " << shopitems[2] << "\n3) " << shopitems[3] << "\n4) " << shopitems[4] << "\n5) " << shopitems[5] << endl;
				if (keyspawn == false) {
					cout << "Hey i see that you have a broken sword\nI will take that from you and give you a new one" << endl;
					inventory[0] = "Sword";
				}
				getline(cin, answer);
				if (answer == "E" || answer == "e" || answer == "Exit" || answer == "exit") {
					cout << "Bai" << endl;
					woom = 8;
				}
				if (answer == shopitems[0] || answer == "0") {
					cout << "\n\n\n\n\n" << endl;
					int skill = money - shopprisces[0];
					if (skill < 0) {
						cout << "Sorry But You Cannot Afford This!" << endl;
					}
					else {
						cout << "\n\nItem Bought\n\nWhat inventory slot would you like to set it to? (0-4)" << endl;
						cin >> slot;
						if (inventory[slot] != "Empty") {
							cout << "This slot is not empty." << endl;
							cin >> slot;
						}
						if (slot >= 5) {
							cin >> slot;
						}
						money = money - shopprisces[0];
						inventory[slot] = shopitems[0];
					}
				}
				if (answer == shopitems[1] || answer == "1") {
					cout << "\n\n\n\n\n" << endl;
					int skill = money - shopprisces[1];
					if (skill < 0) {
						cout << "Sorry But You Cannot Afford This!" << endl;
					}
					else {
						cout << "\n\nItem Bought\n\nWhat inventory slot would you like to set it to? (0-4)" << endl;
						cin >> slot;
						if (inventory[slot] != "Empty") {
							cout << "This slot is not empty." << endl;
							cin >> slot;
						}
						if (slot >= 5) {
							cin >> slot;
						}
						money = money - shopprisces[1];
						inventory[slot] = shopitems[1];
					}
				}
				if (answer == shopitems[2] || answer == "2") {
					cout << "\n\n\n\n\n" << endl;
					int skill = money - shopprisces[2];
					if (skill < 0) {
						cout << "Sorry But You Cannot Afford This!" << endl;
					}
					else {
						cout << "\n\nItem Bought\n\nWhat inventory slot would you like to set it to? (0-4)" << endl;
						cin >> slot;
						if (inventory[slot] != "Empty") {
							cout << "This slot is not empty." << endl;
							cin >> slot;
						}
						if (slot >= 5) {
							cin >> slot;
						}
						money = money - shopprisces[2];
						inventory[slot] = shopitems[2];

					}
				}
				if (answer == shopitems[3] || answer == "3") {
					cout << "\n\n\n\n\n" << endl;
					int skill = money - shopprisces[3];
					if (skill < 0) {
						cout << "Sorry But You Cannot Afford This!" << endl;
					}
					else {
						cout << "\n\nItem Bought\n\nWhat inventory slot would you like to set it to? (0-4)" << endl;
						cin >> slot;
						if (inventory[slot] != "Empty") {
							cout << "This slot is not empty." << endl;
							cin >> slot;
						}
						if (slot >= 5) {
							cin >> slot;
						}
						money = money - shopprisces[3];
						inventory[slot] = shopitems[3];

					}
				}
				if (answer == shopitems[4] && shopitems[4] == "Instant Crash" || answer == "4" && shopitems[4] == "Instant Crash") {
					exit(0);
					cout << "\n\n\n\n\n" << endl;
					int skill = money - shopprisces[4];
					if (skill < 0) {
						cout << "Sorry But You Cannot Afford This!" << endl;
					}
					else {
						cout << "\n\nItem Bought\n\nWhat inventory slot would you like to set it to? (0-4)" << endl;
						cin >> slot;
						if (inventory[slot] != "Empty") {
							cout << "This slot is not empty." << endl;
							cin >> slot;
						}
						if (slot >= 5) {
							cin >> slot;
						}
						money = money - shopprisces[4];
						inventory[slot] = shopitems[4];

					}
				}
				if (answer == shopitems[5] || answer == "5") {
					cout << "sorry this is out of stock" << endl;
				}
				break;
				case 14:

					break;
		}//woom switch
		
	}//while switch
}

void findFile(string file) {
	string line;
	ifstream savefiles;
	savefiles.open(file);
	getline(savefiles, line);
	if (line == "") {
		cout << "File: ['" << file << "'] Has No data or does not exist!" << endl;
	}
	else {
		cout << "File: ['" << file << "'] Has Been Found!" << endl;
	}
	savefiles.close();
}

void saveFile(string file, int woom) {
	ofstream myfile(file);
	myfile << woom;
	for (int i = 0; i < 5; i++) {
		myfile << inventory[i] << endl;
	}
}



int stage;
string monstertype;

void arena() {
	
	cout << "A Monster Spawned, ";
	monster();
	cout << "Health: " << health << endl;
	system("pause");
	while (health > 0) {
		cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
		block(damageCalc(monstertype));
		attack(inventory[0]);
		system("pause");
	}
	while (health <= 0) {
		if (monstersfought > 5) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou pass out after fighting " << monstersfought << " monster(s) and you wake up a couple hours later to a " << monstertype << " in your face.\nYou realise you where dreaming and leave off to visit some friends\n\n\n\n\n\n\n\n\n\n" << endl;
			system("color 02");
			system("pause");
			exit(0);
		}
		else {
			stage++;
		}
		if (stage == 3) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nCongrats you fought and killed " << monstersfought << " monster(s) and died to a " << monstertype << "\n\n\n\n\n\n\n\n\n\n" << endl;
			system("color 04");
			system("pause");
		}
		if (stage == 200) {
			exit(0);
		}
	}
}

void monster() {
	int monstergen = rand() % 100 + 1;
	if (monstergen <= 20) {
		cout << "It is A BOAT!" << endl;
		monstertype = "BOAT";
		monsterhealth = 67;
	}
	else
		if (monstergen >= 21 && monstergen <= 30) {
			cout << "It is A BURNT FISH!" << endl;
			monstertype = "BURNT FISH";
			monsterhealth = 12;
		}
		else
			if (monstergen == 31) {
				cout << "It is A FISH!" << endl;
				monstertype = "FISH";
				monsterhealth = 36;
			}
			else
				if (monstergen >= 32 && monstergen <= 36) {
					cout << "It is A APPLE!" << endl;
					monstertype = "APPLE";
					monsterhealth = 5;
				}
				else
					if (monstergen >= 37 && monstergen <= 50) {
						cout << "It is A SHOE!" << endl;
						monstertype = "SHOE";
						monsterhealth = 32;
					}
					else
						if (monstergen >= 51 && monstergen <= 72) {
							cout << "It is A POTATO!" << endl;
							monstertype = "POTATO";
							monsterhealth = 12;
						}
						else
							if (monstergen >= 73 && monstergen <= 100) {
								cout << "It is a BANANA!" << endl;
								monstertype = "BANANA";
								monsterhealth = 27;
							}
	cout << "The Fight Starts NOW!!!!!" << endl;
}
int damageCalc(string type) {
	if (type == "BOAT") {
		int boatatt = rand() % 15;
		system("color 96");
		return boatatt;
	}
	else
		if (type == "BURNT FISH") {
			int brntfish = rand() % 20;
			system("color 90");
			return brntfish;
		}
		else
			if (type == "FISH") {
				int fish = rand() % 50;
				system("color 91");
				return fish;
			}
			else
				if (type == "APPLE") {
					int apple = rand() % 12;
					system("color 24");
					return apple;
				}
				else
					if (type == "SHOE") {
						int shoe = rand() % 7;
						system("color 06");
						return shoe;
					}
					else
						if (type == "POTATO") {
							int potato = rand() % 73;
							system("color 0F");
							return potato;
						}
						else
							if (type == "BANANA") {
								int banana = rand() % 3;
								system("color 60");
								return banana;
							}
	return 0;
}


double blocked;
double percentblock;
void block(int attack) {
	if (monsterhealth >= 1) {
		if (armor[0] == "Potato" && armor[1] == "Potato" && armor[2] == "Potato" && armor[3] == "Potato") {
			percentblock = rand() % 2;
			blocked = attack * (percentblock / 100);
			blocked = round(blocked);
			attack = attack - blocked;
		}
		if (armor[0] == "Wood" && armor[1] == "Wood" && armor[2] == "Wood" && armor[3] == "Wood") {
			percentblock = rand() % 25;
			blocked = attack * (percentblock / 100);
			blocked = round(blocked);
			attack = attack - blocked;
		}
		if (armor[0] == "Diamond" && armor[1] == "Diamond" && armor[2] == "Diamond" && armor[3] == "Diamond") {
			percentblock = attack / 2;
			blocked = attack * (percentblock / 100);
			blocked = round(blocked);
			attack = attack - blocked;
		}
		if (armor[0] == "Godlike" && armor[1] == "Godlike" && armor[2] == "Godlike" && armor[3] == "Godlike") {
			blocked = attack * 2;
			attack = attack - blocked;
		}
		health = health - attack;
		cout << "Your armor Blocked : " << blocked << " of their attack" << " | Your Health: " << health << " | Their attack: " << attack + blocked << " | After Armor: " << attack << endl;
	}
}

void attack(string weaponslot) {
	if (monsterhealth >= 1 && health >= 1) {
		int damage;
		if (weaponslot == "None" || weaponslot == "Glowing Potato") {
			damage = rand() % 3;
			monsterhealth = monsterhealth - damage;
			cout << "You hit " << monstertype << " for " << damage << " damage || it has " << monsterhealth << " health left" << endl;
		}
		if (weaponslot == "Lightning") {
			damage = rand() % (monsterhealth / 2);
			monsterhealth = monsterhealth - damage;
			cout << "You hit " << monstertype << " for " << damage << " damage || it has " << monsterhealth << " health left" << endl;
		}
		if (weaponslot == "Bat") {
			damage = rand() % 30;
			monsterhealth = monsterhealth - damage;
			cout << "You hit " << monstertype << " for " << damage << " damage || it has " << monsterhealth << " health left" << endl;
		}
		if (weaponslot == "Fireball") {
			damage = rand() % 99999999;
			monsterhealth = monsterhealth - damage;
			cout << "You blew up " << monstertype << " for " << damage << " damage || it has " << monsterhealth << " health left" << endl;
		}
		if (weaponslot == "Broken Sword") {
			damage = rand() % 22;
			monsterhealth = monsterhealth - damage;
			cout << "You hit " << monstertype << " for " << damage << " damage || it has " << monsterhealth << " health left" << endl;
		}
		if (weaponslot == "Sword") {
			damage = rand() % 36;
			monsterhealth = monsterhealth - damage;
			cout << "You hit " << monstertype << " for " << damage << " damage || it has " << monsterhealth << " health left" << endl;
		}
	}
	if (monsterhealth <= 0) {
		cout << "Would You Like To Go To The Shop? (Yes/No)" << endl;
		system("color 03");
		string answer;
		getline(cin, answer);
		
		if (answer == "Yes" || answer == "yes" || answer == "y" || answer == "Y" || answer == "Ya") {
			shop(false, true);
		}
		if (answer == "No" || answer == "no" || answer == "N" || answer == "n") {
			monstersfought++;
			money = money + moneycalc(monstertype);
			cout << "Money: " << money << endl;
			cout << "Another Monster Spawned, ";
			monster();
		}
	}
}

int moneycalc(string type) {
	if (type == "BOAT") {
		int rowboat = rand() % 20;
		return rowboat;
	}
	else
		if (type == "BURNT FISH") {
			int burnedfish = rand() % 20;
			return burnedfish;
		}
		else
			if (type == "FISH") {
				int fish = rand() % 20;
				return fish;
			}
			else
				if (type == "APPLE") {
					int apple = rand() % 20;
					return apple;
				}
				else
					if (type == "SHOE") {
						int shoe = rand() % 4;
						return shoe;
					}
					else
						if (type == "POTATO") {
							int potato = rand() % 75;
							return potato;
						}
						else
							if (type == "BANANA") {
								int banana = rand() % 50;
								return banana;
							}
	return 0;
}
/*
if (answer == "North" || answer == "north" || answer == "n" || answer == "N" || answer == "NORTH") {
					woom = ;
				}
if (answer == "East" || answer == "east" || answer == "e" || answer == "E" || answer == "EAST") {
					woom = ;
				}
if (answer == "South" || answer == "south" || answer == "s" || answer == "S" || answer == "SOUTH") {
					woom = ;
				}
if (answer == "West" || answer == "west" || answer == "w" || answer == "W" || answer == "WEST") {
					woom = ;
				}
*/

void shop(bool swordspawn, bool loop) {
	string answer;
	int state = 0;
	bool looper = loop;
		while (looper) {
			switch (state) {
				case 0:
					cout << "\n\nWelcome To My Shop (0 || Exit || E)\nCategories:\n1) Armor\n2) Weapons\n3) Food\n\nEnter The Category Name or Number -----\n" << endl;
					getline(cin, answer);
					if (answer == "Exit" || answer == "exit" || answer == "e" || answer == "0") {
						looper = false;
					}
					if (answer == "Armor" || answer == "armor" || answer == "1" || answer == "one") {
						state = 1;
					}
					if (answer == "Weapons" || answer == "weapons" || answer == "2" || answer == "two") {
						state = 2;
					}
					if (answer == "Food" || answer == "food" || answer == "3" || answer == "three") {
						state = 3;
					}
					break;
				case 1:
					cout << "1) Godlike Armor : 90000 Coins\n2) Diamond Armor : 1000 Coins\n3) Wood Planks : 100 Coins\n4) Potato Armor : 0 Coins || Free!" << endl;
					getline(cin, answer);
					if (answer == "1" || answer == "Godlike Armor") {
						if (money < 9000) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 9000) {
							cout << "Armor is equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							armor[1] = "Godlike";
							armor[2] = "Godlike";
							armor[3] = "Godlike";
							armor[0] = "Godlike";
							money = money - 9000;
						}
					}
					if (answer == "2" || answer == "Diamond Armor") {
						if (money < 1000) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 1000) {
							cout << "Armor is equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							armor[1] = "Diamond";
							armor[2] = "Diamond";
							armor[3] = "Diamond";
							armor[0] = "Diamond";
							money = money - 1000;
						}
					}
					if (answer == "3" || answer == "Wood Planks") {
						if (money < 100) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 100) {
							cout << "Armor is equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							armor[1] = "Wood";
							armor[2] = "Wood";
							armor[3] = "Wood";
							armor[0] = "Wood";
							money = money - 100;
						}
					}

					if (answer == "4" || answer == "Potato Armor") {
							cout << "Armor is equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							armor[1] = "Potato";
							armor[2] = "Potato";
							armor[3] = "Potato";
							armor[0] = "Potato";
					}
					state = 0;
						break;
				case 2:
					cout << "1) Fireball : 90000 Coins\n2) Lightning : 1000 Coins\n3) Bat : 100 Coins\n4) Stick : [Out Of Stock]" << endl;
					getline(cin, answer);
					if (answer == "1" || answer == "Fireball") {
						if (money < 9000) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 9000) {
							cout << "Weapons are equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							inventory[0] = "Fireball";
							money = money - 9000;
						}
					}
					if (answer == "2" || answer == "Lightning") {
						if (money < 1000) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 1000) {
							cout << "Weapons are equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							inventory[0] = "Lightning";
							money = money - 1000;
						}
					}
					if (answer == "3" || answer == "Bat") {
						if (money < 100) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 100) {
							cout << "Weapons are equipped automatically!" << endl;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							inventory[0] = "Bat";
							money = money - 100;
						}
					}
					state = 0;
					break;
				case 3:
					cout << "You will eat food instantly!\n\n1) Salad : 90000 Coins\n2) Glowing Potato : 1000 Coins\n3) Potato : 100 Coins\n4) Mashed Potato : [Out Of Stock]" << endl;
					getline(cin, answer);
					if (answer == "1" || answer == "Salad") {
						if (money < 9000) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 9000) {
							health = health + 9000;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							money = money - 9000;
						}
					}

					if (answer == "2" || answer == "Glowing Potato") {
						if (money < 1000) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 1000) {
							health = health + 1000;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							money = money - 1000;
						}
					}

					if (answer == "3" || answer == "Potato") {
						if (money < 100) {
							cout << "You cant afford this!" << endl;
						}
						if (money > 100) {
							health = health + 100;
							cout << "\nHealth: " << health << " \nMoney: " << money << " \nArmor: " << armor[0] << " : " << armor[1] << " : " << armor[2] << " : " << armor[3] << " \nInventory: " << inventory[0] << " : " << inventory[1] << " : " << inventory[2] << " : " << inventory[3] << " : " << inventory[4] << "\n" << endl;
							money = money - 100;
						}
					}
					state = 0;
					break;
			}
		}
}
