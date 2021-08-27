#pragma once
#include "MoveObj.h"
class CPlayer :
    public CMoveObj
{

private:
	friend class CObj;
	friend class CScene;

private:
    CPlayer();
	CPlayer(const CPlayer& player);
    ~CPlayer();

	int m_iHP;

public:
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual CPlayer* Clone();

public:
	void Hit(class CCollider* pSrc, class CCollider* pDest, float fDeltaTime);

private:
	void Fire();
};

