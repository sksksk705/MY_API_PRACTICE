#pragma once
#include "MoveObj.h"
class CMinion :
    public CMoveObj
{

private:
	friend class CObj;
	friend class CScene;

private:
	CMinion();
	CMinion(const CMinion& minion);
	~CMinion();

private:
	MOVE_DIR		m_eDir;
	float			m_fFireTime;
	float			m_fFireLimitTime;

public:
	virtual bool Init();
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual CMinion* Clone();

private:
	void Fire();
};

