#include "personNode.h"

personNode::personNode() {
	marriage = 0;
	parents = 0;
} // constructor (default)

personNode::personNode(int parentsNum, int marriageNum) {
	marriage = marriageNum;
	parents = parentsNum;
} // overloaded constructor

int personNode::getMarriage(){
	return marriage;
}

int personNode::getParents(){
	return parents;
}