#pragma once
#include "Collider.h"
class CColliderRect :
    public CCollider
{
private:
	friend class CObj;

private:
	RECTANGLE	m_tInfo;
	RECTANGLE	m_tWorldInfo;

public:
	void SetRect(float l, float t, float r, float b)
	{
		m_tInfo.l = l;
		m_tInfo.t = t;
		m_tInfo.r = r;
		m_tInfo.b = b;
	}
	RECTANGLE GetInfo() const { return m_tInfo; }
	RECTANGLE GetWorldInfo() const { return m_tWorldInfo; }



protected:
	CColliderRect();
	CColliderRect(const CColliderRect& coll);
	virtual ~CColliderRect();

protected:
	COLLIDER_TYPE	m_eCollType;

public:
	COLLIDER_TYPE	GetColliderType() const { return m_eCollType; }

public:

	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual bool Collision(CCollider* pDest);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual CColliderRect* Clone();

};

