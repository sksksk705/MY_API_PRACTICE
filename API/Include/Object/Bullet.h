#pragma once
#include "MoveObj.h"
class CBullet :
	public CMoveObj
{

private:
	friend class CObj;

private:
	CBullet();
	CBullet(const CBullet& bullet);
public:
	~CBullet();

private:
	float m_fBulletSize;

public:
	virtual bool Init();
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);

};

