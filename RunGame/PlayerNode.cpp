#include "PlayerNode.h"



PlayerNode::PlayerNode()
{
}
PlayerNode::PlayerNode(int x, int y) {
	posX = x;
	posY = y;

}
PlayerNode* PlayerNode::SetPref() {
	_pref = new PlayerNode(posX, posY - 1);
	return _pref;
}
PlayerNode::~PlayerNode()
{
}
