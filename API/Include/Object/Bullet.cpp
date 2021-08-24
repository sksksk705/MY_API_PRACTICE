#include "Bullet.h"
#include "../Core.h"

CBullet::CBullet()
{
}

CBullet::CBullet(const CBullet& bullet)
    :CMoveObj(bullet)
{
    m_fBulletSize = bullet.m_fBulletSize;
}

CBullet::~CBullet()
{
}

bool CBullet::Init()
 {
    m_fBulletSize = 10.f;
    SetSpeed(600.f);
    return true;
}

int CBullet::Update(float fDeltaTime)
{
    CMoveObj::Update(fDeltaTime);
    
     MoveAngle(fDeltaTime);

    return 0;
}

int CBullet::LateUpdate(float fDeltaTime)
{
    CMoveObj::LateUpdate(fDeltaTime);


    return 0;
}

void CBullet::Collision(float fDeltaTime)
{
    CMoveObj::Collision(fDeltaTime);
}

void CBullet::Render(HDC hDC, float fDeltaTime)
{
    CMoveObj::Render(hDC, fDeltaTime);

    Ellipse(hDC, m_tPos.x - m_fBulletSize, m_tPos.y - m_fBulletSize, m_tPos.x + m_fBulletSize, m_tPos.y + m_fBulletSize);

}
