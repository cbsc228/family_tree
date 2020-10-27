//------------------------------------------
//              class familyNode
//------------------------------------------
// Describes a person with marriages and parents
//------------------------------------------
using namespace std;

const int MAX_NUM_CHILDREN_ = 10;

class familyNode {
public:
	//default constructor
	familyNode(); 
	//overloaded constructor
	familyNode(int husbandNum, int wifeNum, int childrenNums[]);
	//returns husband index
	int getHusband();
	//returns wife index
	int getWife();
	//returns array pointer of children indices
	int *getChildren();
private:
	//index of husband (0 if none)
	int husband;
	//index of wife (0 if none)
	int wife;
	//list of children indices
	int children[MAX_NUM_CHILDREN_];
};