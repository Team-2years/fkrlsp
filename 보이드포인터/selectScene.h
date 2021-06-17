#pragma once
#include "gameNode.h"
#include "button.h"

class selectScene : public gameNode
{
private:
	button* _btnSceneChange;	//�� �����



public:
	selectScene();
	~selectScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	//�Լ������Ͱ� ����� ���� ���������̶� static �ٿ������
	static void cbSceneChange();
	static void cbSceneChangeObj(void* obj);
	static void cbSceneChangeObjConst(const void* obj);

	void cbSceneChangeFunctional(const char* str);
};

