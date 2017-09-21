#pragma once

class InspirationEngine;
enum MOUSE_STATE
{
	LEFT = 1,
	MIDDLE = 2,
	RIGHT = 3
};
class Input : public InspirationEngine_Modul
{
	struct Mouse
	{
		bool button[3];
		IVec2 position;
		IVec2 deltaPosition;
	};
public:
	~Input();
//	InspirationEngine* parent;
	void Start();
	const Uint8* keyboard;
	Mouse mouse;
private:
	void MouseUpdate(int mEvent);
	void InputThread();
};