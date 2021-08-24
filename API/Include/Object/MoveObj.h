#pragma once

#include "../Game.h"
#include "Obj.h"
class CMoveObj:
	public CObj
{
protected:
	CMoveObj();
	CMoveObj(const CMoveObj& obj);
	virtual ~CMoveObj();

private:
	float		m_fAngle;
	float		m_fSpeed;
	float		m_fAngleSpeed;

public:
	void SetAngle(float fAngle) { m_fAngle = fAngle; }
	void SetSpeed(float fSpeed) { m_fSpeed = fSpeed; }
	void SetAngleSpeed(float fAngleSpeed) { m_fAngleSpeed = fAngleSpeed; }

	float GetAngle() { return m_fAngle; }
	float GetSpeed() { return m_fSpeed; }
	float GetAngleSpeed() { return m_fAngleSpeed; }

public:
	void Move(float x, float y);
	void Move(float x, float y, float fDeltaTime);
	void Move(const POSITION& tMove);
	void Move(const POSITION& tMove, float fDeltaTime);
	void MoveXFromSpeed(float fDeltaTime, MOVE_DIR eDir);
	void MoveX(float x);
	void MoveX(float x, float fDeltaTime);
	void MoveYFromSpeed(float fDeltaTime, MOVE_DIR eDir);
	void MoveY(float y);
	void MoveY(float y, float fDeltaTime);
	void MoveAngle();
	void MoveAngle(float fDeltaTime);
	void Rotation(float fDeltaTime, MOVE_DIR eDir);

public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);


};

