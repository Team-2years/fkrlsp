#include "stdafx.h"
#include "button.h"


button::button()
{
}


button::~button()
{
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnDownFramePoint, POINT btnUpFramePoint, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;
	_callbackFunctionParameterConst = NULL;
	_constobj = NULL;
	_direction = BUTTONDIRECTION_NULL;
	_callbackFuntional = NULL;

	_x = x;
	_y = y;

	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

// 함수에서 매개변수를 받아 써보자
HRESULT button::init(const char * imageName, int x, int y, POINT btnDownFramePoint, POINT btnUpFramePoint, CALLBACK_FUNCTION_PARAMETER cbFunction, void * obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;
	_callbackFunctionParameterConst = NULL;
	_constobj = NULL;
	_direction = BUTTONDIRECTION_NULL;
	_callbackFuntional = NULL;

	_x = x;
	_y = y;

	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnDownFramePoint, POINT btnUpFramePoint, CALLBACK_FUNCTION_PARAMETER_CONST cbFunction, const void * obj)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;
	_callbackFunctionParameterConst = cbFunction;
	_constobj = obj;
	_callbackFuntional = NULL;

	_direction = BUTTONDIRECTION_NULL;

	_x = x;
	_y = y;

	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

HRESULT button::init(const char * imageName, int x, int y, POINT btnDownFramePoint, POINT btnUpFramePoint, CALLBACK_FUNCTIONAL cbFunction, const char* functionalStr)
{
	_callbackFuntional = cbFunction;
	_functionalStr = functionalStr;
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;
	_callbackFunctionParameterConst = NULL;
	_constobj = NULL;
	_direction = BUTTONDIRECTION_NULL;

	_x = x;
	_y = y;

	_btnUpFramePoint = btnUpFramePoint;
	_btnDownFramePoint = btnDownFramePoint;

	_imageName = imageName;
	_image = IMAGEMANAGER->findImage(imageName);

	_rc = RectMakeCenter(x, y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}

void button::release()
{
}

void button::update()
{
	if (PtInRect(&_rc, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_direction = BUTTONDIRECTION_DOWN;
		}
		else if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON) && _direction == BUTTONDIRECTION_DOWN)
		{
			_direction = BUTTONDIRECTION_UP;
			if (_obj != NULL)
			{
				_callbackFunctionParameter(_obj);
			}
			else if (_constobj != NULL) 
			{
				_callbackFunctionParameterConst(_constobj);
			}
			else if (_callbackFuntional != NULL) 
			{
				_callbackFuntional(_functionalStr);
			}
			else
			{
				if (_callbackFunction != NULL) _callbackFunction();
			}
		}
	}
	else _direction = BUTTONDIRECTION_NULL;

}

void button::render()
{
	switch (_direction)
	{
		case BUTTONDIRECTION_NULL: case BUTTONDIRECTION_UP:
			_image->frameRender(getMemDC(), _rc.left, _rc.top,
				_btnUpFramePoint.x, _btnUpFramePoint.y);
		break;
		case BUTTONDIRECTION_DOWN:
			_image->frameRender(getMemDC(), _rc.left, _rc.top,
				_btnDownFramePoint.x, _btnDownFramePoint.y);
		break;
	
	}
}
