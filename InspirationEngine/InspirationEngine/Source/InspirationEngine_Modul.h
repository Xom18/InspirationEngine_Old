#pragma once

class InspirationEngine;
class InspirationEngine_Modul
{
public:
	InspirationEngine* engine;
	std::thread* trd;
	virtual void Start(){};
};