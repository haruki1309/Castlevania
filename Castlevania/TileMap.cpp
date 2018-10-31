#include "TileMap.h"

TileMap::TileMap()
{
	tileWidth = 16;
	tileHeight = 16;
}

TileMap::TileMap(int _cols, int _rows, int _tileWidth, int _tileHeight)
{
	cols = _cols;
	rows = _rows;
	tileWidth = _tileWidth;
	tileHeight = _tileHeight;

	matrix = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	
}


TileMap::~TileMap()
{
	if (matrix)
	{
		for (int i = 0; i < rows; i++)
		{
			delete matrix[i];
		}
		delete matrix;
		matrix = nullptr;
	}
}

void TileMap::InitTileSet(Sprite * _tileSet)
{
	tileSet = _tileSet;
}

void TileMap::LoadMatrixMap(LPCSTR fileSource)
{
	fstream pFile;
	pFile.open(fileSource, fstream::in);

	string lineString;
	int * posSpace = NULL;
	string subString;
	int countLine = 0;
	int i = 0;

	while (pFile.good())
	{
		getline(pFile, lineString);
		if (countLine == 0)
		{
			cols = atoi(lineString.c_str());
		}
		else if (countLine == 1)
		{
			rows = atoi(lineString.c_str());

			matrix = new int *[rows];
			for (int row = 0; row < rows; row++)
			{
				matrix[row] = new int[cols];
			}
		}
		else
		{
			posSpace = new int[cols];
			for (int j = 0; j < cols; j++)
			{
				if (j == 0)
				{
					posSpace[0] = lineString.find(" ", 0);
					subString = lineString.substr(0, posSpace[0]);
					int id = atoi(subString.c_str());
					matrix[i][j] = id;
				}
				else
				{
					posSpace[j] = lineString.find(" ", posSpace[j - 1] + 1);
					subString = lineString.substr(posSpace[j - 1] + 1, posSpace[j] - (posSpace[j - 1] + 1));
					int id = atoi(subString.c_str());
					matrix[i][j] = id;
				}
			}
			i++;
		}
		countLine++;
	}
}

void TileMap::Draw(ViewPort *viewPort)
{
	D3DXVECTOR3 cameraPos = viewPort->GetCameraPos();
	int cameraWidth, cameraHeight;
	viewPort->GetCameraSize(cameraWidth, cameraHeight);

	int colStart = (int)(cameraPos.x + 1) / tileWidth;
	int colEnd = cameraWidth / tileWidth - 1;
	int rowStart = (int)(cameraPos.y + 1 - 40) / tileHeight;
	int rowEnd = cameraHeight / tileHeight - 1;

	RECT tileRect;

	for (int i = rowStart; i <= rowEnd; i++)
	{
		for (int j = colStart; j <= colEnd; j++)
		{	
			tileRect.left = (matrix[i][j] % 16) * 16;
			tileRect.top = (matrix[i][j] / 16) * 16;
			tileRect.right = tileRect.left + 16;
			tileRect.bottom = tileRect.top + 16;

			tileSet->Draw(D3DXVECTOR3(cameraPos.x + j * 16, cameraPos.y + i * 16, 0), tileRect);
		}
	}
}

