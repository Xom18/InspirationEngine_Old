#include "InspirationEngine_Image.h"

Image::Image()
{

}

Image::Image(char** buffer, int width, int height)
{

}

Image::~Image()
{

}

//RGBA BMP only
int Image::ReadBMP(const char* filename)
{
	data = 0;
	width = 0;
	height = 0;

	int size;
	char* buf;
	Uint32* buf_int;
	int offset;
	char bm6[3];
	char magic[3] = { 'B', 'M', '6' };

	ReadFile(&buf, &size, filename);
	for (int i = 0; i < 3; ++i)
		bm6[i] = buf[i];

	for(int i = 0; i < 3; ++i)
		if (bm6[i] != magic[i])
			return 1;

	buf_int = reinterpret_cast<Uint32*>(buf + 18);

	offset = *(buf + 10);
	width = *(buf_int);
	height = *(buf_int + 1);

	buf_int = reinterpret_cast<Uint32*>(buf + offset - 1);
	data = new Uint32[width * height];

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			data[y * width + x] = buf_int[(height - y - 1) * width + x];
		}
	}
	delete buf;
	return 0;
}

Uint32* Image::GetData()
{
	return data;
}

int Image::GetWidth()
{
	return width;
}

int Image::GetHeight()
{
	return height;
}

Tile::Tile()
{

}

Tile::~Tile()
{

}

//ex)64 * 64 size to 16 * 256
int Tile::ImageToTile(Image image, int splitSize)
{
	if (image.GetHeight() == 0 || image.GetWidth() == 0)
		return 1;

	data = new Uint32[image.GetWidth() * image.GetHeight()];
	int counter = 0;
	int splitWidth = image.GetWidth() / splitSize;
	int splitHeight = image.GetHeight() / splitSize;
	tileCount = splitWidth * splitHeight;
	offset = splitSize * splitSize;
	for (int y = 0; y < splitHeight; ++y)
	{
		for (int x = 0; x < splitWidth; ++x)
		{
			for (int Y = 0; Y < splitSize; ++Y)
			{
				for (int X = 0; X < splitSize; ++X)
				{
					data[counter] = image.GetData()[(y * splitSize + Y) * image.GetWidth() + x * splitSize + X];
					++counter;
				}
			}
		}
	}
	return 0;
}

Uint32* Tile::GetData()
{
	return data;
}

Uint32* Tile::GetData(int index)
{
	return data + index * offset;
}

int Tile::GetTileCount()
{
	return tileCount;
}

int Tile::GetOffset()
{
	return offset;
}

int Tile::GetSize()
{
	return size;
}