#pragma once

class Image
{
public:
	int ReadBMP(const char* filename);
	Image(char** buffer, int width, int height);
	Image();
	~Image();
	Uint32* GetData();
	int GetWidth();
	int GetHeight();
protected:
	Uint32* data;
	int width;
	int height;
private:
	
};

class Tile
{
public:
	Tile();
	~Tile();
	int ImageToTile(Image image, int splitSize);
	Uint32* GetData();
	Uint32* GetData(int index);

	int GetSize();
	int GetTileCount();
	int GetOffset();
protected:
	Uint32* data;
	int size;
	int tileCount;
	int offset;
private:
};