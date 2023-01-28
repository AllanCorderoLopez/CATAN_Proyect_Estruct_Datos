#include "BoardGraph.h"
#include "Board.h"


bool firstTime = true;

BoardGraph::BoardGraph() {
	first = NULL;
	size = 0;
}

bool BoardGraph::graphIsEmpty() {
	return size == 0;
}


int BoardGraph::getSize() {
	return size;
}

BoardVertex* BoardGraph::getVertex(int indexVertex) {
	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			return i;
		}
		i = i->nextVextex;
	}
	return NULL;
}


bool BoardGraph::hasSettlement(int indexVertex) {
	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if(i->hasSettlement==true){
				return true;
			}
		}
		i = i->nextVextex;
	}
	return false;
}
bool BoardGraph::hasCity(int indexVertex) {
	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if (i->hasCity == true) {
				return true;
			}
		}
		i = i->nextVextex;
	}
	return false;
}
bool BoardGraph::hasTerrain(int indexVertex) {
	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if (i->isTerrain == true) {
				return true;
			}
		}
		i = i->nextVextex;
	}
	return false;
}
bool BoardGraph::settlementConnectToRoad(BoardVertex* vertex, int player) {

	BoardVertex* i = vertex;
	BoardEdge* j = i->edge;

	while (j != NULL) {	
		while (j != NULL) {
			if (j->cloggedRoad == true && j->player==player) {
				return true;
			}
			j = j->next;

		}
	}

	return false;
}	

bool BoardGraph::roadMinimumDistance(BoardVertex* vertex) {//determina si del vertice inicial tiene construcciones con una carretera de distancia 

	BoardVertex* i = vertex;
	BoardEdge* j = i->edge;

	while (j != NULL) {
		while (j != NULL) {
			if (j->term->hasSettlement ) {
				return true;
			}
			if (j->term->hasCity) {
				return true;
			}
			j = j->next;

		}
	}

	return false;
}


void BoardGraph::buildSettlementOnVertex(int indexVertex, int player) {

	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if (true) {//first time == true
				if (!hasSettlement(indexVertex)) {
					i->hasSettlement = true;
					i->player = player;
					cout << "Se ha colocado un asentamiento en el vertice: "<<indexVertex<<" del jugador: " << i->player << endl;

				}
				else {
					cout << "Ya existe un asentamiento en este lugar del jugador: " << i->player << endl;
				}
			}
			else {
				if (settlementConnectToRoad(i, player)) {
					if (!roadMinimumDistance(i)) {
						i->hasSettlement = true;
							i->player = player;
							cout << "No se detectaron asentamientos cercanos. Se ha colocado un asentamiento del jugador: " << i->player << endl;

					}
					else {
						cout << "Debe existir 2 carreteras entre los poblados o ciudades. No se ha colocado la construcción del jugador: " << player << endl;

					}
}
				else {
					cout << "Conexion con carretera no detectada. El asentamiento debe conectar con una carretera" << endl;
				}
			}

		}
		i = i->nextVextex;
	}
}



void BoardGraph::getRoadOnEdge() {
	int initial, terminal;
	bool cloggedRoad;
	int player;
	int indexVertex;


	cout << "Ingrese el vertice de partida: " << endl;
	cin >> initial;
	cout << "Ingrese el vertice de llegada: " << endl;
	cin >> terminal;

	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);

	if (vIni == NULL)
		cout << "El vertice de inicio ingresado no existe" << endl;
	if (vTer == NULL)
		cout << "El vertice de llegada ingresado no existe" << endl;



	BoardEdge* i = getEdge(initial, terminal);

	if (hasRoad(getEdge(initial, terminal))) {
		cout << "Existe una carretera entre los vertices: " << initial << " -> " << terminal <<" Del jugador: " << i->player << endl;
	}
	else {
		cout << "No existe una carretera entre: " << initial << " -> " << terminal << endl;
	}

}






void BoardGraph::buildRoadOnEdge(int initial, int terminal, int player) {
	bool cloggedRoad;
	int indexVertex;


	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);


	if (vIni == NULL)
		cout << "El vertice de inicio ingresado no existe" << endl;
	if (vTer == NULL)
		cout << "El vertice de llegada ingresado no existe" << endl;

	BoardEdge* i = getEdge(initial, terminal);
	BoardEdge* j = getEdge(terminal, initial);



	if (i != NULL || j != NULL) {
		if (hasRoad(getEdge(initial, terminal))) {
			cout << "Ya existe una carretera entre los vertices: " << initial << " -> " << terminal << endl;
		}
		else {
			if (true) {//firstTime == false
				if (roadConnect(initial, terminal, player)) {
					cout << "Se agrego una carretera entre: " << initial << " -> " << terminal << endl;
					cout << "Se agrego una carretera entre: " << terminal << " -> " << initial << endl;

					i->cloggedRoad = true;
					i->player = player;

					j->cloggedRoad = true;
					j->player = player;
				}
				else {
					cout << "Accion invalida. Al agregar carreteras estas deben conectar con otras y deben ser del mismo jugador" << endl;

				}
			}
			else {

				if (roadConnectToSettlement(initial, terminal, player) == true) {
					cout << "Se agrego una carretera entre: " << initial << " -> " << terminal << endl;
					i->cloggedRoad = true;
					i->player = player;
					j->cloggedRoad = true;
					j->player = player;
					firstTime = false;
				}
				else {
					cout << "Accion invalida. En el primer turno la carretera de conectar con asentamiento del mismo jugador." << endl;
				}

			}




		}
	}
	else {
		cout << "Accion invalida. Los vertices no están conectados por una carretera." << endl;

	}



}




bool BoardGraph::roadConnect(int initial, int terminal, int player) {


	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);


	BoardEdge* i = vIni->edge;
	while (vIni->edge != NULL) {

		i = vIni->edge;
		if (i->cloggedRoad == false && i->player==player) {
			return true;
		}
		vIni->edge = vIni->edge->next;
		

	}


	BoardEdge* j = vTer->edge;
	while (vTer->edge != NULL) {

		j = vTer->edge;
		if (j->cloggedRoad == false && j->player == player) {
			return true;
		}
		vTer->edge = vTer->edge->next;


	}


	return false;
}

bool BoardGraph::roadConnectToSettlement(int initial, int terminal, int player) {


	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);



	if (vIni->hasSettlement == true) {
		return true;
	}

	if (vTer->hasSettlement == true) {
		return true;
	}

	return false;
}

int BoardGraph::getTerrainVertex(int indexVertex) {

	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if (i->isTerrain == true) {
				return i->terrain;
			}
		}
		i = i->nextVextex;
	}
	return -1;
}

void BoardGraph::buildTerrainOnVertex(int indexVertex, int terrain)
{

	BoardVertex* i = first;

	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if (i->isTerrain == true) {
				i->terrain = terrain;
				i->isTerrain = true;
				cout << "el vertice: " << indexVertex << " se convirtió en terreno"<<endl;
			}
		}
		i = i->nextVextex;
	}


}


void BoardGraph::buildCityOnVertex() {
	int indexVertex;
	int player;

	cout << "Ingrese el vertice para agregarle una ciudad: " << endl;
	cin >> indexVertex;
	cout << "Ingrese el jugador que pone la ciudad: " << endl;
	cin >> player;

	BoardVertex* i = first;
	while (i != NULL) {
		if (i->indexVertex == indexVertex) {
			if (!hasSettlement(indexVertex)) {
				if (hasSettlement(indexVertex)) {
					i->hasSettlement = false;
					i->hasCity = true;
					i->player = player;
					break;
				}
				else {
					cout << "No existe un asentamiento, necesitas un asentamiento para mejorarlo" << endl;

				}


			}
			else {
				cout << "Ya existe una ciudad en este lugar del jugador: " << i->player << endl;
			}
		}
		i = i->nextVextex;
	}
}

void BoardGraph::addVertex(int indexVertex, bool hasSettlement, bool hasCity, int player, bool isTerrain, int terrain) {

		BoardVertex* newVertex = new BoardVertex(indexVertex,hasSettlement, hasCity, player, isTerrain, terrain);

		if (graphIsEmpty())
			first = newVertex;
		else {

			BoardVertex* i = first;

			while (i->nextVextex != NULL) {
				i = i->nextVextex;
			}
			i->nextVextex = newVertex;
		}
		size++;

}

void BoardGraph::addEdge(int initial, int terminal, bool cloggedRoad, int player) {

	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);


	if(vIni == NULL)
		cout << "El vertice de inicio ingresado no existe" << endl;
	if (vTer == NULL)
		cout << "El vertice de llegada ingresado no existe" << endl;

	if (vIni != NULL && vTer != NULL) {
		BoardEdge* newEdge = new BoardEdge(vTer, cloggedRoad, player);
		if (vIni->edge == NULL) {
			vIni->edge = newEdge;
		}
		else {

			BoardEdge* j = vIni->edge;

			while (j->next != NULL) {
					j = j->next;
			}

			j->next = newEdge;

		}

		}
	

}
void BoardGraph::getAdjacencyList() {

	BoardVertex* i = first;
	
	while (i!=NULL) {
		BoardEdge* j = i->edge;
		cout << i->indexVertex << " = "; 
		//j = j->next;
		while (j != NULL) {
			cout <<" | "<< i->indexVertex << " -> " << j->term->indexVertex << " | " << " , ";

			j = j->next;

		}
		cout << endl;

		i = i->nextVextex;
	}


}

void BoardGraph::deleteEdges(BoardVertex* vertex) {

	BoardEdge* i = vertex->edge;
	while (vertex->edge != NULL) {

		i = vertex->edge;
		vertex->edge = vertex->edge->next;
		cout << "Arista: " << vertex->indexVertex << " -> " << i->term->indexVertex<<" Eliminada";
		delete(i);

	}
}


void BoardGraph::deleteVertex(int indexVertex) {


	if (getVertex(indexVertex) != NULL) {


		if (first->indexVertex == indexVertex) {
			BoardVertex* i = first;
			first = first->nextVextex;
			deleteEdges(i);
			deleteEdgeDest(i->indexVertex);
			cout << "Vertice: " << indexVertex << " Eliminado ";
			delete(i);
			size--;
		}
		else {
			BoardVertex* i = first;
			BoardVertex* j = i->nextVextex;
			while (j != NULL) {
				if (j->indexVertex == indexVertex) {
					deleteEdges(j);
					i->nextVextex = j->nextVextex;
					delete(j);
					size--;
					cout << "Vertice: " << indexVertex << " Eliminado ";
					break;
				}
				i = j;
				j = j->nextVextex;
			}



		}

	}
	else {
		cout << "Vertice a eliminar no existe " << endl;
	}


}


bool BoardGraph::hasRoad(BoardEdge* edge) {
	if (edge->cloggedRoad == true) {
				return true;
	}
	return false;
}

BoardEdge* BoardGraph::getEdge(int initial, int terminal) {

	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);


	if (vIni == NULL)
		cout << "El vertice de inicio ingresado no existe" << endl;
	if (vTer == NULL)
		cout << "El vertice de llegada ingresado no existe" << endl;

	if (vIni != NULL && vTer != NULL && vIni->edge !=NULL && vTer->edge != NULL) {
		
		if (vIni->edge->term == vTer) {
			BoardEdge* i = vIni->edge;
			//vIni->edge = vIni->edge->next;
			cout << "Arista: " << initial << " -> " << terminal << " Encontrada" << endl;

			return i;
		}
		else {

			BoardEdge* i = vIni->edge;
			BoardEdge* j = i->next;

			while (j != NULL) {
				if (j->term == vTer && vTer->edge != NULL) {
					//i->next = j->next;
					cout << "Arista: " << initial << " -> " << terminal << " Encontrada" << endl;
					return j;
					break;
				}
				i = j;
				j = j->next;
			}
		}

	}
	return NULL;

}


void BoardGraph::deleteEdge(int initial, int terminal) {

	BoardVertex* vIni = getVertex(initial);
	BoardVertex* vTer = getVertex(terminal);


	if (vIni == NULL)
		cout << "El vertice de inicio ingresado no existe" << endl;
	if (vTer == NULL)
		cout << "El vertice de llegada ingresado no existe" << endl;

	if (vIni != NULL && vTer != NULL) {
		if (vIni->edge->term == vTer) {
			BoardEdge* i = vIni->edge;
			vIni->edge = vIni->edge->next;
			cout << "Arista: " << initial << " -> " << terminal << " Eliminada" << endl;
			delete(i);
		}
		else {

			BoardEdge* i = vIni->edge;
			BoardEdge* j = i->next;

			while (j != NULL) {
				if (j->term == vTer) {
					i->next = j->next;
					cout << "Arista: " << initial << " -> " << terminal << " Eliminada" << endl;
					delete(j);
					break;
				}
					i = j;
					j = j->next;
			}
		}
		 
	}


}


void BoardGraph::deleteEdgeDest(int term) {
	BoardVertex* i = first;
	while (i!=NULL) {
		if (i->indexVertex == term) 
			continue;

		if (i->edge->term->indexVertex==term) {
			BoardEdge* j = i->edge;
			i->edge = i->edge->next;
			cout << "Arista: " << i->indexVertex << " -> " << j->term->indexVertex<<" Eliminada" << endl;
			delete(j);
		}
		else {
			BoardEdge* x = i->edge;
			BoardEdge* y = x->next;
			while (y!=NULL) {
				if (y->term->indexVertex == term) {
					x->next = y->next;
					cout << "Arista: " << i->indexVertex << " -> " << term << " Eliminada" << endl; 
					delete(y);
				}
			}
		}

			i = i->nextVextex;
	}
}


void BoardGraph::deleteAll() {
	BoardVertex* i = first;
	while (first != NULL) {

		i = first;
		first = first->nextVextex;
		deleteEdges(i);
		cout << "Vertice: " << i->indexVertex << " Eliminado" << endl;

		delete(i);

	}
}


void BoardGraph::generateVertices() {
	
	for (int i = 0; i < 73; i++) {
		if (i < 19) {//los primeros 19 vertices son terrenos
			addVertex(i + 1, false, false, 0, true, 0);
		}
		else {//los demás son posibles asentamientos o ciudades 
			addVertex(i + 1, false, false, 0, false, 0);

		}
	}
}

void BoardGraph::generateRoadsEdges() {

	//aristas para conectar con el terreno 
	
	//1
	addEdge(20, 1, false, 0);
	addEdge(23, 1, false, 0);
	addEdge(24, 1, false, 0);
	addEdge(28, 1, false, 0);
	addEdge(32, 1, false, 0);
	addEdge(27, 1, false, 0);

	//2
	addEdge(24, 2, false, 0);
	addEdge(21, 2, false, 0);
	addEdge(25, 2, false, 0);
	addEdge(29, 2, false, 0);
	addEdge(33, 2, false, 0);
	addEdge(28, 2, false, 0);

	//3
	addEdge(22, 3, false, 0);
	addEdge(26, 3, false, 0);
	addEdge(30, 3, false, 0);
	addEdge(29, 3, false, 0);
	addEdge(25, 3, false, 0);
	addEdge(34, 3, false, 0);

	//4
	addEdge(27, 4, false, 0);
	addEdge(32, 4, false, 0);
	addEdge(37, 4, false, 0);
	addEdge(42, 4, false, 0);
	addEdge(36, 4, false, 0);
	addEdge(31, 4, false, 0);

	//5
	addEdge(28, 5, false, 0);
	addEdge(33, 5, false, 0);
	addEdge(38, 5, false, 0);
	addEdge(43, 5, false, 0);
	addEdge(37, 5, false, 0);
	addEdge(32, 5, false, 0);

	//6
	addEdge(29, 6, false, 0);
	addEdge(34, 6, false, 0);
	addEdge(44, 6, false, 0);
	addEdge(38, 6, false, 0);
	addEdge(33, 6, false, 0);
	addEdge(39, 6, false, 0);

	//7
	addEdge(30, 7, false, 0);
	addEdge(35, 7, false, 0);
	addEdge(40, 7, false, 0);
	addEdge(45, 7, false, 0);
	addEdge(39, 7, false, 0);
	addEdge(34, 7, false, 0);

	//8
	addEdge(36, 8, false, 0);
	addEdge(42, 8, false, 0);
	addEdge(53, 8, false, 0);
	addEdge(47, 8, false, 0);
	addEdge(41, 8, false, 0);
	addEdge(48, 8, false, 0);

	//9
	addEdge(37, 9, false, 0);
	addEdge(43, 9, false, 0);
	addEdge(49, 9, false, 0);
	addEdge(54, 9, false, 0);
	addEdge(48, 9, false, 0);
	addEdge(42, 9, false, 0);

	//10
	addEdge(38, 10, false, 0);
	addEdge(44, 10, false, 0);
	addEdge(50, 10, false, 0);
	addEdge(55, 10, false, 0);
	addEdge(49, 10, false, 0);
	addEdge(43, 10, false, 0);

	//11
	addEdge(39, 11, false, 0);
	addEdge(45, 11, false, 0);
	addEdge(51, 11, false, 0);
	addEdge(56, 11, false, 0);
	addEdge(50, 11, false, 0);
	addEdge(44, 11, false, 0);

	//12
	addEdge(40, 12, false, 0);
	addEdge(46, 12, false, 0);
	addEdge(52, 12, false, 0);
	addEdge(57, 12, false, 0);
	addEdge(51, 12, false, 0);
	addEdge(45, 12, false, 0);

	//13
	addEdge(48, 13, false, 0);
	addEdge(54, 13, false, 0);
	addEdge(59, 13, false, 0);
	addEdge(63, 13, false, 0);
	addEdge(58, 13, false, 0);
	addEdge(53, 13, false, 0);

	//14
	addEdge(49, 14, false, 0);
	addEdge(55, 14, false, 0);
	addEdge(60, 14, false, 0);
	addEdge(64, 14, false, 0);
	addEdge(59, 14, false, 0);
	addEdge(54, 14, false, 0);

	//15
	addEdge(50, 15, false, 0);
	addEdge(56, 15, false, 0);
	addEdge(61, 15, false, 0);
	addEdge(65, 15, false, 0);
	addEdge(60, 15, false, 0);
	addEdge(55, 15, false, 0);

	//16
	addEdge(51, 16, false, 0);
	addEdge(57, 16, false, 0);
	addEdge(62, 16, false, 0);
	addEdge(66, 16, false, 0);
	addEdge(61, 16, false, 0);
	addEdge(56, 16, false, 0);

	//17
	addEdge(59, 17, false, 0);
	addEdge(64, 17, false, 0);
	addEdge(68, 17, false, 0);
	addEdge(71, 17, false, 0);
	addEdge(67, 17, false, 0);
	addEdge(63, 17, false, 0);

	//18
	addEdge(60, 18, false, 0);
	addEdge(65, 18, false, 0);
	addEdge(69, 18, false, 0);
	addEdge(72, 18, false, 0);
	addEdge(68, 18, false, 0);
	addEdge(64, 18, false, 0);

	//19
	addEdge(61, 19, false, 0);
	addEdge(66, 19, false, 0);
	addEdge(70, 19, false, 0);
	addEdge(73, 19, false, 0);
	addEdge(69, 19, false, 0);
	addEdge(65, 19, false, 0);


	//espacios para carreteras

	//20
	addEdge(20, 23, false, 0);
	addEdge(20, 24, false, 0);

	//21
	addEdge(21, 24, false, 0);
	addEdge(21, 25, false, 0);

	//22
	addEdge(22, 25, false, 0);
	addEdge(22, 26, false, 0);

	//23
	addEdge(23, 20, false, 0);
	addEdge(23, 27, false, 0);

	//24
	addEdge(24, 21, false, 0);
	addEdge(24, 20, false, 0);
	addEdge(24, 28, false, 0);

	//25
	addEdge(25, 21, false, 0);
	addEdge(25, 29, false, 0);
	addEdge(25, 22, false, 0);

	//26
	addEdge(26, 22, false, 0);
	addEdge(26, 30, false, 0);

	//27
	addEdge(27, 23, false, 0);
	addEdge(27, 31, false, 0);
	addEdge(27, 32, false, 0);


	//28
	addEdge(28, 24, false, 0);
	addEdge(28, 32, false, 0);
	addEdge(28, 33, false, 0);


	//29
	addEdge(29, 25, false, 0);
	addEdge(29, 33, false, 0);
	addEdge(29, 34, false, 0);

	//30
	addEdge(30, 26, false, 0);
	addEdge(30, 34, false, 0);
	addEdge(30, 35, false, 0);


	//31
	addEdge(31, 27, false, 0);
	addEdge(31, 36, false, 0);

	//32
	addEdge(32, 27, false, 0);
	addEdge(32, 28, false, 0);
	addEdge(32, 37, false, 0);

	//33
	addEdge(33, 28, false, 0);
	addEdge(33, 29, false, 0);
	addEdge(33, 38, false, 0);


	//34
	addEdge(34, 29, false, 0);
	addEdge(34, 30, false, 0);
	addEdge(34, 39, false, 0);


	//35
	addEdge(35, 30, false, 0);
	addEdge(35, 40, false, 0);

	//36
	addEdge(36, 31, false, 0);
	addEdge(36, 41, false, 0);
	addEdge(36, 42, false, 0);


	//37
	addEdge(37, 32, false, 0);
	addEdge(37, 42, false, 0);
	addEdge(37, 43, false, 0);


	//38
	addEdge(38, 33, false, 0);
	addEdge(38, 43, false, 0);
	addEdge(38, 44, false, 0);

	//39
	addEdge(39, 34, false, 0);
	addEdge(39, 44, false, 0);
	addEdge(39, 45, false, 0);


	//40
	addEdge(40, 35, false, 0);
	addEdge(40, 45, false, 0);
	addEdge(40, 46, false, 0);


	//41
	addEdge(41, 36, false, 0);
	addEdge(41, 47, false, 0);

	//42
	addEdge(42, 36, false, 0);
	addEdge(42, 37, false, 0);
	addEdge(42, 48, false, 0);


	//43
	addEdge(43, 37, false, 0);
	addEdge(43, 38, false, 0);
	addEdge(43, 49, false, 0);

	//44
	addEdge(44, 38, false, 0);
	addEdge(44, 39, false, 0); 
	addEdge(44, 50, false, 0);

	//45
	addEdge(45, 39, false, 0);
	addEdge(45, 40, false, 0);
	addEdge(45, 51, false, 0);


	//46
	addEdge(46, 40, false, 0);
	addEdge(46, 52, false, 0);

	//47
	addEdge(47, 41, false, 0);
	addEdge(47, 53, false, 0);

	//48
	addEdge(48, 42, false, 0);
	addEdge(48, 53, false, 0);
	addEdge(48, 54, false, 0);


	//49
	addEdge(49, 43, false, 0);
	addEdge(49, 54, false, 0);
	addEdge(49, 55, false, 0);


	//50
	addEdge(50, 44, false, 0);
	addEdge(50, 55, false, 0);
	addEdge(50, 56, false, 0);


	//51
	addEdge(51, 45, false, 0);
	addEdge(51, 56, false, 0);
	addEdge(51, 57, false, 0);


	//52
	addEdge(52, 46, false, 0);
	addEdge(52, 57, false, 0);

	//53
	addEdge(53, 48, false, 0);
	addEdge(53, 47, false, 0);
	addEdge(53, 58, false, 0);

	//54
	addEdge(54, 48, false, 0);
	addEdge(54, 49, false, 0);
	addEdge(54, 59, false, 0);


	//55
	addEdge(55, 49, false, 0);
	addEdge(55, 50, false, 0);
	addEdge(55, 60, false, 0);


	//56
	addEdge(56, 50, false, 0);
	addEdge(56, 51, false, 0);
	addEdge(56, 61, false, 0);


	//57
	addEdge(57, 51, false, 0);
	addEdge(57, 52, false, 0);
	addEdge(57, 62, false, 0);


	//58
	addEdge(58, 53, false, 0);
	addEdge(58, 63, false, 0);

	//59
	addEdge(59, 54, false, 0);
	addEdge(59, 63, false, 0);
	addEdge(59, 64, false, 0);

	//60
	addEdge(60, 55, false, 0);
	addEdge(60, 64, false, 0);
	addEdge(60, 65, false, 0);

	//61
	addEdge(61, 56, false, 0);
	addEdge(61, 65, false, 0);
	addEdge(61, 66, false, 0);


	//62
	addEdge(62, 57, false, 0);
	addEdge(62, 66, false, 0);

	//63
	addEdge(63, 58, false, 0);
	addEdge(63, 59, false, 0);
	addEdge(63, 67, false, 0);

	//64
	addEdge(64, 59, false, 0);
	addEdge(64, 60, false, 0);
	addEdge(64, 68, false, 0);

	//65
	addEdge(65, 60, false, 0);
	addEdge(65, 61, false, 0);
	addEdge(65, 69, false, 0);

	//66
	addEdge(66, 61, false, 0);
	addEdge(66, 62, false, 0);
	addEdge(66, 70, false, 0);

	//67
	addEdge(67, 63, false, 0);
	addEdge(67, 71, false, 0);

	//68
	addEdge(68, 64, false, 0);
	addEdge(68, 71, false, 0);
	addEdge(68, 72, false, 0);


	//69
	addEdge(69, 65, false, 0);
	addEdge(69, 72, false, 0);
	addEdge(69, 73, false, 0);

	//70
	addEdge(70, 66, false, 0);
	addEdge(70, 73, false, 0);

	//71
	addEdge(71, 67, false, 0);
	addEdge(71, 68, false, 0);

	//72
	addEdge(72, 68, false, 0);
	addEdge(72, 69, false, 0);

	//73
	addEdge(73, 69, false, 0);
	addEdge(73, 70, false, 0);


}

void BoardGraph::generateBoard() {


	generateVertices();
	generateRoadsEdges();



}