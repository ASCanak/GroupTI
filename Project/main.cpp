#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

void spel(vector<vector<int>> rooms, int &index, int &input, int wumpus, int valKuil, int valKuil1, int bat, int bat1){
	cout << endl << "(Typ '-1' als je wilt stoppen met spelen, snoepie!)" << endl;
	while(input != -1){
		if(input == -2 && wumpus != index){
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "Je zit nu in kamer: " << index << endl << "Deze kamer is verbonden met: ";
			for(int j = 0; j < 3; j++){ 
				cout << rooms[index][j] << " ";
			}
			cout << endl << endl << "--------------------------------------------------------------------------------------" << endl;
			if((valKuil == rooms[index][0] || valKuil == rooms[index][1] || valKuil == rooms[index][2] || valKuil1 == rooms[index][0] || valKuil1 == rooms[index][1] || valKuil1 == rooms[index][2]) && (bat == rooms[index][0] || bat == rooms[index][1] || bat == rooms[index][2] || bat1 == rooms[index][0] || bat1 == rooms[index][1] || bat1 == rooms[index][2]) && (wumpus != rooms[index][0] || wumpus == rooms[index][1] || wumpus == rooms[index][2])){
				cout << endl << "Multiple Warnings: I feel a cold breeze, and I hear Flapping Nearby!!!" << endl;
				cout << endl << "--------------------------------------------------------------------------------------" << endl;
			}
			else if((bat == rooms[index][0] || bat == rooms[index][1] || bat == rooms[index][2] || bat1 == rooms[index][0] || bat1 == rooms[index][1] || bat1 == rooms[index][2]) && (wumpus != rooms[index][0] || wumpus == rooms[index][1] || wumpus == rooms[index][2])){
				cout << endl << "Warning: Flapping Nearby!!!" << endl; 
				cout << endl << "--------------------------------------------------------------------------------------" << endl;
			}
			else if((valKuil == rooms[index][0] || valKuil == rooms[index][1] || valKuil == rooms[index][2] || valKuil1 == rooms[index][0] || valKuil1 == rooms[index][1] || valKuil1 == rooms[index][2]) && (wumpus != rooms[index][0] || wumpus == rooms[index][1] || wumpus == rooms[index][2])){
				cout << endl << "Warning: Is it cold in here?" << endl;
				cout << endl << "--------------------------------------------------------------------------------------" << endl;
			}
			cout << endl << "Naar welke kamer zou je willen verplaatsen: ";
			cin >> input;
		}
		else if(cin.fail()){
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "!!!Foutieve Syntax!!!" << endl; 
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << endl << "Naar welke kamer zou je willen verplaatsen: ";
			cin >> input;
		}
		else if(index == input){
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "!!!Je zit al in die kamer!!!" << endl;
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "Naar welke kamer zou je willen verplaatsen: ";
			cin >> input;
		}
		else if(input != rooms[index][0] && input != rooms[index][1] && input != rooms[index][2]){
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "!!!Ongeldige Keuze!!!" << endl;
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "Naar welke kamer zou je willen verplaatsen: ";
			cin >> input;
		}
		else if(wumpus == input){
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "The Wumpus was in that room. You died." << endl; //"My Nigga!, you got devoured."
			input = -1;
		}
		else if((valKuil == input || valKuil1 == input) && wumpus != input){
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "There is a AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH! You died." << endl; //"My Nigga!, you fell to your death."
			input = -1;
		}
		else if((bat == input || bat1 == input) && wumpus != input){
			index = rand() % 20;
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl <<"There were bats inside that room. You teleported to " << index << endl; //"My Nigga!, Don't eat them! SO naar Wuhan." << endl "Player: You are what you eat and I'm Batman! *Teleports to random room*"
			input = -2;
		}
		else{ 
			index = input;
			input = -2;
		}
	}
	cout << endl << "--------------------------------------------------------------------------------------" << endl;
	cout << endl << "Dit project is mede-mogelijk gemaakt door 'int saus' free mijn niffo saus." << endl;
	cout << endl << "--------------------------------------------------------------------------------------" << endl;
	exit(0);
}

vector<unsigned int> configureerTraps(const unsigned int start){
	unsigned int valKuil = start, valKuil1 = start, bat = start, bat1 = start, wumpus = start;
    vector<unsigned int> trapRooms;
    while(wumpus == start)
		wumpus = rand() % 20;
	while(valKuil == start)
		valKuil = rand() % 20;
    while(valKuil1 == start || valKuil1 == valKuil)
        valKuil1 = rand() % 20;
    while(bat == start || bat == valKuil || bat == valKuil1)
        bat = rand() % 20;
    while(bat1 == start || bat1 == valKuil || bat1 == valKuil1 || bat1 == bat)
        bat1 = rand() % 20;
    trapRooms.push_back({wumpus});trapRooms.push_back({valKuil});trapRooms.push_back({valKuil1});trapRooms.push_back({bat});trapRooms.push_back({bat1});
	return trapRooms;
}

void configuratie(const string &File){
	vector<vector <int>> rooms= {
								{10, 11, 19},  	//0
								{2, 10, 11},   	//1
								{1, 3, 12},	//2
								{2, 4, 13},	//3
								{3, 5, 14},	//4
								{4, 6, 15},	//5
								{5, 7, 16},	//6
								{6, 8, 17},	//7
								{7, 9, 18},	//8
								{8, 10, 19},	//9
								{0, 1, 9},	//10
								{0, 1, 12},	//11
								{2, 11, 13},	//12
								{3, 12, 14},	//13
								{4, 13, 15},	//14
								{5, 14, 16},	//15
								{6, 15, 17},	//16
								{7, 16, 18},	//17
								{8, 17, 19},	//18
								{0, 9, 18}};	//19
	ofstream writeFile(File);
	if(writeFile.is_open()){
		for(unsigned int i = 0; i < rooms.size(); i++){
			for(unsigned int j = 0; j < rooms[i].size(); j++){
				writeFile << rooms[i][j] << " " ;
			}
			writeFile << endl;
		}
	unsigned int configureerStart = rand() % 20;
	vector<unsigned int> traps = configureerTraps(configureerStart);
	writeFile << -1 << " " << configureerStart << endl;
	for(unsigned int i = 0; i < 5; i++){
		if(i == 0)
			writeFile << -2 << " " << traps[i] << endl;	
		else if(i == 1 || i == 2){
			writeFile << -3 << " " << traps[i] << " " << -3 << " " << traps[i + 1] << endl;
			i++;
		}
		else{
			writeFile << -4 << " " << traps[i] << " " << -4 << " " << traps[i + 1] << endl;
			i++;
		}
	}
	writeFile.close();
    }
	else
        cout << "Can't open file" << endl;
}

vector<vector<int>> configuratie_Rooms_Lezen(vector<vector<int>> &rooms, const string &File){
	ifstream readFile(File);
	int arr[60], cnt = 0, x = 0;
	
	if(readFile.is_open()){
		while (cnt < 60 && readFile >> x)
			arr[cnt++] = x;
		for (int i = 0; i < 60; i += 3)
			rooms.push_back({arr[i], arr[i+1], arr[i+2]});		
	readFile.close();
    }
	else
        cout << "Can't open file" << endl;
	return rooms;
}

vector<int> configuratie_TrapRooms_Lezen(vector<int> &trapRooms, const string &File){
	ifstream readFile(File);
	int arr[72], cnt = 0, x = 0;
	
	if(readFile.is_open()){
		while(cnt < 72 && readFile >> x)
			arr[cnt++] = x;
		for(int i = 60; i < 72; i += 2){
			if(arr[i] == -1)
				trapRooms.push_back({arr[i + 1]});
			else if(arr[i] == -2)
				trapRooms.push_back({arr[i + 1]});
			else if(arr[i] == -3)
				trapRooms.push_back({arr[i + 1]});
			else if(arr[i] == -4)
				trapRooms.push_back({arr[i + 1]});
		}		
	readFile.close();
    }
	else
        cout << "Can't open file" << endl;
	return trapRooms;
}

int main(){
	srand(time(NULL));
	vector<vector<int>> rooms = {};
	vector<int> trapRooms = {};
	string file = "Project/configuratie.txt";
	int state = 0;
	cout << "--------------------------------------------------------------------------------------" << endl;
	cout << endl << "Als je een nieuw doolhof wilt voer '1' in, zo niet voer '2' in: "; 
	cin >> state;
	cout << endl << "--------------------------------------------------------------------------------------" << endl;
	
	while(state != 1 || state != 2){
		if(state == 1)
			configuratie(file);
		else if(state == 2){
			configuratie_Rooms_Lezen(rooms, file);
			configuratie_TrapRooms_Lezen(trapRooms, file);
			int index = trapRooms[0], input = -2;
			int wumpus = trapRooms[1], valKuil = trapRooms[2], valKuil1 = trapRooms[3], bat = trapRooms[4], bat1 = trapRooms[5]; 
			spel(rooms, index, input, wumpus, valKuil, valKuil1, bat, bat1);
		}
		else if(cin.fail()){
			cout << endl << "Error: Dat is geen geldige optie!" << endl; 
			cout << endl << "--------------------------------------------------------------------------------------" << endl;
			cout << endl << "Als je een nieuw doolhof wilt voer '1' in, zo niet voer '2' in: ";
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> state;
		}
		else{
			cout << endl << "Error: Dat is geen geldige optie!" << endl; 
			cout << endl << "--------------------------------------------------------------------------------------" << endl; 
			cout << endl << "Als je een nieuw doolhof wilt voer '1' in, zo niet voer '2' in: "; 
			cin >> state;
		}
		cout << endl << "--------------------------------------------------------------------------------------" << endl;
	}
	return 0;
}
