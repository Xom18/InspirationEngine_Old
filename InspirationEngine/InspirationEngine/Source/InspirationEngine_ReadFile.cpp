#include <SDL/SDL.h>
#include <fstream>
#include "InspirationEngine_ReadFile.h"

void ReadFile(char** buffer, int* size, const char* filename)
{
	//������ �о���δ�, (���ϸ�, ��������)
	std::ifstream in(filename, std::ifstream::binary | std::ios::in);

	//���� ���� ������ ������ 0 0
	if (!in)
	{
		*buffer = 0;
		*size = 0;
	}
	else//������ �ֳ�
	{
		in.seekg(0, std::ifstream::end);//�б� �������� ��ġ�� ������ �� ������
		*size = in.tellg();//���� ������ġ�� ������ġ ������ ����<�ڷ���>(������ �� ����) ���ϱ�
		in.seekg(0, std::ifstream::beg);//�ٽ� �б� �����͸� �� ������
		*buffer = new char[*size];//���ۿ� ���ο� ������ �Ҵ��Ѵ�
		in.read(*buffer, *size);//�д´�
	}
}