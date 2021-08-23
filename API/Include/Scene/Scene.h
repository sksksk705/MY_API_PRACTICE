#pragma once

#include "../Game.h"
class CScene
{
private:
	friend class CSceneManager;

protected:
	CScene();
	virtual ~CScene() = 0;

protected:
	list<class CLayer*> m_LayerList;

public:
	class CLayer* CreateLayer(const string& strTag, int iZOder = 0);

	class CLayer* FindLayer(const string& strTag);


public:
	virtual bool Init();

	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);


	static bool LayerSort(class CLayer* pL1, class CLayer* pL2);
};

