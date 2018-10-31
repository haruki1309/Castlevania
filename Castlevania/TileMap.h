#pragma once
#include <fstream>
#include <sstream>
#include <d3dx9.h>
#include <string.h>
#include "Sprites.h"
#include "ViewPort.h"

class TileMap
{
private:
	int ** matrix;
	int cols, rows;
	int tileWidth, tileHeight;
	Sprite * tileSet;

public:
	TileMap();
	TileMap(int _cols, int _rows, int _tileWidth, int _tileHeight);
	~TileMap();

	void InitTileSet(Sprite * tileSet);
	void LoadMatrixMap(LPCSTR fileSource);
	void Draw(ViewPort *viewPort);

};

