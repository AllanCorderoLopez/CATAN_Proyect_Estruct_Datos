#include "NodeTerrain.h"

NodeTerrain::NodeTerrain(Terrain* _data, NodeTerrain* _nextNode = NULL) {
	data = _data;
	nextNode = _nextNode;

}


void NodeTerrain::setDataTerrain(Terrain* _data) {
	data = _data;
}


void NodeTerrain::setNextNode(NodeTerrain* _nextNode) {
	nextNode = _nextNode;
}

Terrain* NodeTerrain::getDataTerrain() {
	return data;
}


NodeTerrain* NodeTerrain::getNextNode() {
	return nextNode;
}
