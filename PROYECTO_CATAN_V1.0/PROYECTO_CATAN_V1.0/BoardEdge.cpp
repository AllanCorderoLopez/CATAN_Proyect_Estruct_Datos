#include "BoardEdge.h"

BoardEdge::BoardEdge(BoardVertex* _term, bool _cloggedRoad, int _player) {
	cloggedRoad = _cloggedRoad;
	term = _term;
	player = _player;
	next = NULL;

}
