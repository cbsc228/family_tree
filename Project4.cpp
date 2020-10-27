#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "personNode.h"
#include "familyNode.h"
//#include "queue.h"

using namespace std;

const int MAX_GRAPH_SIZE = 100;
const int MAX_NUM_CHILDREN = 10;

void insertCommand(stringstream &line, personNode people[]){
	//holds index of new personNode
	int individualNum;
	//holds index of parent familyNode
	int parentNum;
	//holds index of marriage familyNode
	int marriageNum;
	//holds command input
	string command;
	line >> individualNum;
	line >> command;
	if(command == "Parent")
	line >> parentNum;
	line >> command;
	if(command == "Marriage")
		line >> marriageNum;
	//creates new personNode
	personNode newPerson = personNode(parentNum, marriageNum);
	//inserts new personNode into graph
	people[individualNum] = newPerson;
	cout << "Individual " << individualNum << " has parents " << parentNum << " and is married in family " << marriageNum << endl;
}

void familyCommand(stringstream &line, familyNode families[]){
	//holds index of new family
	int familyNum;
	//holds index of husband
	int husbandNum;
	//holds index of wife
	int wifeNum;
	//holds indices of children
	int childrenNums[MAX_NUM_CHILDREN];
	//holds command input
	string command;
	//holds index to insert next child into
	int childCount = 0;
	line >> familyNum;
	line >> command;
	//gets husband index
	if(command == "Husband")
		line >> husbandNum;
	line >> command;
	//gets wife index
	if(command == "Wife")
		line >> wifeNum;
	//gets all numbers of children
	while(line >> command){
		line >> childrenNums[childCount];
		childCount += 1;
	}
	//inserts new familyNode
	families[familyNum] = familyNode(husbandNum, wifeNum, childrenNums);
	//outputs to user that new familyNode was inserted
	cout << "Family " << familyNum << " has husband " << husbandNum << ", wife " << wifeNum << ", and children ";
	for(int i = 0; i < childCount; i++){
		cout << childrenNums[i] << " ";
	}
	cout << endl;
}

bool isInFamily(int personNum, int familyNum, bool &foundFlag, familyNode families[], personNode people[]){
	int husbandNum = families[familyNum].getHusband();
	int wifeNum = families[familyNum].getWife();
	int *childrenNums = families[familyNum].getChildren();
	
	if(personNum == husbandNum || personNum == wifeNum){//person is the husband or wife
		return true;
	}
	for(int i = 0; i < MAX_NUM_CHILDREN; i++){
		if(personNum == childrenNums[i]){
			return true;
		}
	}
	return false;
}

void checkCommand(familyNode families[], personNode people[]){
	//checks for consistency from individual to familyNode
	bool consistencyFlag = true;
	for(int i = 1; i < MAX_GRAPH_SIZE; i++){
		int parentIndex = people[i].getParents();
		int marriageIndex = people[i].getMarriage();
		bool foundFlag;
		
		
		//need to make this part not run when a particular part of the family does not exist (value == 0)
		if(parentIndex != 0){
			foundFlag = isInFamily(i, parentIndex, foundFlag, families, people);
			if(foundFlag == false){
				consistencyFlag = false;
				cout << "Individual " << i << " points to parent family " << parentIndex << " but there is no backpointer." << endl;
			}	
		}
		
		if(marriageIndex != 0){
			foundFlag = isInFamily(i, marriageIndex, foundFlag, families, people);
			if(foundFlag == false){
				consistencyFlag = false;
				cout << "Individual " << i << " points to marriage family " << marriageIndex << " but there is no backpointer." << endl;
			}
		}
	}
	if(consistencyFlag == true)
		cout << "The data is consistent" << endl;
}

void relateCommand(stringstream &line){
	int person1;
	int person2;
	line >> person1;
	line >> person2;
	cout << "Relate function called on person " << person1 << " and person " << person2 << "." << endl;
}

string getFileName(){
	string inputFile;
	cout << "Input file: ";
	cin >> inputFile;
	cout << endl;
	return inputFile;
}

int readInputFile(familyNode families[], personNode people[]){
	ifstream fileIn;
	string inputFile = getFileName();
	fileIn.open(inputFile);
	
	if(fileIn.fail())
		//reading file failed
		return -1;
	else{
		string newLine;
		while(getline(fileIn, newLine)){
			stringstream line(newLine);
			string action;
			line >> action;
			if(action == "Insert"){
				insertCommand(line, people);
			}
			else if(action == "Family"){
				 familyCommand(line, families);
			}
			else if(action == "Check"){
				checkCommand(families, people);
			}
			else if(action == "Relate"){
				relateCommand(line);
			}
			else{
				//input command not recognized
				return -2;
			}
			
		}
		//reading file succeeded
		return 0;
	}
}

int main(){
	familyNode families[MAX_GRAPH_SIZE];
	personNode people[MAX_GRAPH_SIZE];
//	for(int i = 0; i < MAX_GRAPH_SIZE; i++){
//		families[i] = 0;
//		people[i] = 0;
//	}
	int readFlag;
	readFlag = readInputFile(families, people);
	
	if(readFlag == -1)
		cout << "Error: Could not open requested file" << endl;
	else if(readFlag == -2)
		cout << "Error: Command input not recognized" << endl;
	
	return 0;
}