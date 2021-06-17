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
	const char* str = "��Ÿ��";
	const void* ptr = str;
	
	
	// std::function<void (std::string)>
	/*auto introduce = [](std::string name) {
		std::cout << "My name is " << name << std::endl;
	};*/
	//auto cbfun = []() {SCENEMANAGER->changeScene("��Ÿ��"); };
	// ���� 
	//_btnSceneChange->init("��ư", WINSIZEX / 2, WINSIZEY / 2, PointMake(0, 1), PointMake(0, 0), []() {SCENEMANAGER->changeScene("��Ÿ��"); });
	
	_btnSceneChange->init("��ư", WINSIZEX / 2, WINSIZEY / 2,
		PointMake(0, 1), PointMake(0, 0), std::bind(&selectScene::cbSceneChangeFunctional, this, std::placeholders::_1), "������");
	/////////////////////////
	// Ŭ���� ��� �Լ� ���޽� std::bind�� ����Ͽ� ����
	// Ŭ������ this ��ü�� ����
	// Ŭ���� ����Լ��� ������ ���� ����
	// �Լ� ������ ��Ŀ����� function�� ���� ���ָ� �����.
	// ���ڰ� ���ٸ� ������� �ʾƵ��ǰ�
	// ���ڰ� 3�����
	// std::placeholders::_1, std::placeholders::_2, std::placeholders::_3
	// ���� ������ŭ �߰��ؼ� �Է��ؾߵȴ�.
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
	SCENEMANAGER->changeScene("��Ÿ��");
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

