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
	const char* str = "스타씬";
	const void* ptr = str;
	
	
	// std::function<void (std::string)>
	/*auto introduce = [](std::string name) {
		std::cout << "My name is " << name << std::endl;
	};*/
	//auto cbfun = []() {SCENEMANAGER->changeScene("스타씬"); };
	// 람다 
	//_btnSceneChange->init("버튼", WINSIZEX / 2, WINSIZEY / 2, PointMake(0, 1), PointMake(0, 0), []() {SCENEMANAGER->changeScene("스타씬"); });
	
	_btnSceneChange->init("버튼", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), std::bind(&selectScene::cbSceneChangeFunctional, this, std::placeholders::_1), "거지씬");
	/////////////////////////
	// 클래스 멤버 함수 전달시 std::bind를 사용하여 전달
	// 클래스의 this 개체를 전달
	// 클래스 멤버함수의 인자의 인자 개수
	// 함수 포인터 방식에서는 function만 전달 해주면 됬었다.
	// 인자가 없다면 기록하지 않아도되고
	// 인자가 3개라면
	// std::placeholders::_1, std::placeholders::_2, std::placeholders::_3
	// 인자 수량만큼 추가해서 입력해야된다.
	/////////////////////////
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
	SCENEMANAGER->changeScene("스타씬");
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

void selectScene::cbSceneChangeFunctional(const char * str)
{
	SCENEMANAGER->changeScene(str);
}

