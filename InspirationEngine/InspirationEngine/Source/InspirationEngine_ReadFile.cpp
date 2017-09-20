#include <SDL/SDL.h>
#include <fstream>
#include "InspirationEngine_ReadFile.h"

void ReadFile(char** buffer, int* size, const char* filename)
{
	//파일을 읽어들인다, (파일명, 파일형식)
	std::ifstream in(filename, std::ifstream::binary | std::ios::in);

	//만약 들어올 내용이 없으면 0 0
	if (!in)
	{
		*buffer = 0;
		*size = 0;
	}
	else//파일이 있네
	{
		in.seekg(0, std::ifstream::end);//읽기 포인터의 위치를 파일의 맨 끝으로
		*size = in.tellg();//파일 시작위치와 현재위치 사이의 길이<자료형>(파일의 총 길이) 구하기
		in.seekg(0, std::ifstream::beg);//다시 읽기 포인터를 맨 앞으로
		*buffer = new char[*size];//버퍼에 새로운 공간을 할당한다
		in.read(*buffer, *size);//읽는다
	}
}