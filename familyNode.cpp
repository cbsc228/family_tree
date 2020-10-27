#include "familyNode.h"

familyNode::familyNode() {
	husband = 0;
	wife = 0;
	for(int i = 0; i < MAX_NUM_CHILDREN_; i++)
		children[i] = 0;
} // constructor (default)

familyNode::familyNode(int husbandNum, int wifeNum, int childrenNums[]) {
	husband = husbandNum;
	wife = wifeNum;
	for(int i = 0; i <MAX_NUM_CHILDREN_; i++){
		children[i] = childrenNums[i];
	}
} // overloaded constructor

int familyNode::getHusband(){
	return husband;
}

int familyNode::getWife(){
	return wife;
}

int *familyNode::getChildren(){
	return children;
}