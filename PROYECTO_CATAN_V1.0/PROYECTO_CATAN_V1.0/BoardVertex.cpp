#include "BoardVertex.h"

BoardVertex::BoardVertex(int _indexVertex, bool _hasSettlement, bool _hasCity, int _player, bool _isTerrain, int _terrain) {
	indexVertex = _indexVertex;
	hasSettlement = _hasSettlement;
	hasCity = _hasCity;
	player = _player;
	isTerrain = _isTerrain;
	terrain = _terrain;
	nextVextex = NULL;
	edge = NULL;

}
