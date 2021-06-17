#pragma once
#include "gameNode.h"
#include <functional>

//�Լ������� ���¸� ���� �ݹ��Լ� 
typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);
typedef void(*CALLBACK_FUNCTION_PARAMETER_CONST)(const void*);
// functional�� �̿��� ���
typedef std::function<void(const char*)> CALLBACK_FUNCTIONAL;
// �Լ� ������ ��Ŀ����� typedef void(*CALLBACK_FUNCTIONAL)(const char*);


//���̵� ������
//����ִ� ���� ����Ų��? -> �����̵� �� ����ų���ִ�
//�ٸ� ���� ����Ų ���� �������� ���� �����ؾ� ��밡��

//<Functional> 
//std::Function, std::move, std::bind ����� �Լ��� �ִµ�
//�ݹ��Լ��� ������ ����Ǿ� �־ �Ű������� ����Ҽ����µ�
//���� �͵��� �� �̿��ϸ� �Ϲ����� �Ű������� �־ ����Ҽ� ����.

//����) �ǿܷ� ���, �̰� ��¥ �����ΰ�? ����ǥ ���� ���� ���� ����
//Lambda expression
//Lambda�� �� ��� ���� �ӵ��� ������ ����! ���ٽ��̶� ��� ������
//�� ����!


enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;
	float _x, _y;

	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	//�ݹ��Լ� typedef �� �ָ� ������ ��
	void*						_obj;
	const void*					_constobj;
	const char*					_functionalStr;

	CALLBACK_FUNCTION			_callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;
	CALLBACK_FUNCTION_PARAMETER_CONST _callbackFunctionParameterConst;
	CALLBACK_FUNCTIONAL _callbackFuntional;

public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);
	
	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
			CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION_PARAMETER_CONST cbFunction, const void* obj);

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTIONAL cbFunction, const char* _functionalStr);

	void release();
	void update();
	void render();
};

