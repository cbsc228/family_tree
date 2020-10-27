//------------------------------------------
//              class personNode
//------------------------------------------
// Describes a person with marriages and parents
//------------------------------------------
using namespace std;

class personNode {
public:
	//default constructor
	personNode(); 
	//overloaded constructor
	personNode(int parentsNum, int marriageNum);
	//gets marriage index
	int getMarriage();
	//gets parents index
	int getParents();
private:
	//index of family this person is connected to by marriage
	int marriage;
	//index of family containing parents (0 if there are none)
	int parents;
};