#pragma once
#include "../Game.h"
class CCamera
{
	DECLARE_SINGLE(CCamera)

private:
	POSITION		m_tPos;
	RESOLUTION		m_tClientRS;
	RESOLUTION		m_tWorldRS;
	POSITION		m_tPivot;
	class CObj*		m_pTarget;



public:
	void SetTarget(class CObj* pObj);
	void SetPivot(const POSITION& tPivot)
	{
		m_tPivot = tPivot;
	}

	void SetPivot(float x, float y)
	{
		m_tPivot.x = x;
		m_tPivot.y = y;
	}
	void SetPos(const POSITION& tPos) { m_tPos = tPos; }
	void SetPos(float x, float y) { m_tPos.x = x; m_tPos.y = y; }

	void SetClientResolution(const RESOLUTION& tRS) { m_tClientRS = tRS; }
	void SetClientResolution(int x, int y)
	{
		m_tClientRS.iW = x;  
		m_tClientRS.iH = y;
	}

	void SetWorldResolution(const RESOLUTION& tRS) { m_tWorldRS = tRS; }
	void SetWorldResolution(int x, int y)
	{
		m_tWorldRS.iW = x;
		m_tWorldRS.iH = y;
	}

	POSITION GetPos()const { return m_tPos; }


public:
	bool Init(const POSITION& tPos, const RESOLUTION& tRS, const RESOLUTION& tWorldRS);
	void Update(float fDeltaTime);
	void Input(float fDeltaTime);


};

