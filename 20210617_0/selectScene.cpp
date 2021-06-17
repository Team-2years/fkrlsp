#include "stdafx.h"
#include "selectScene.h"

#include <iostream>
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
using namespace std;

selectScene::selectScene()
{
}


selectScene::~selectScene()
{
}

HRESULT selectScene::init()
{
	_btnSceneChange = new button;
	const char* str = "½ºÅ¸¾À";
	const void* ptr = str;
	
	_btnSceneChange->init("¹öÆ°", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), cbSceneChangeObjConst, ptr);

	return S_OK;
}

void selectScene::release()
{
}

void selectScene::update()
{
	_btnSceneChange->update();
}

void selectScene::render()
{
	_btnSceneChange->render();
}

void selectScene::cbSceneChange()
{
	SCENEMANAGER->changeScene("½ºÅ¸¾À");
}

void selectScene::cbSceneChangeObj(void * obj)
{
	
	const char* str = (const char*)obj;
	
	cout << str;
	//SCENEMANAGER->changeScene(str);
}

void selectScene::cbSceneChangeObjConst(const void * obj)
{
	const char* str = (const char*)obj;
	cout << str;
	SCENEMANAGER->changeScene(str);
}
