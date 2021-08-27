#include "Player.h"
#include "../Core/Input.h"
#include "../Object/Bullet.h"
#include "../Collider/ColliderRect.h"
#include "../Collider/Collider.h"
#include "../Core/Camera.h"

CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& player) :
    CMoveObj(player)
{
    
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
    SetPos(50.f , 50.f);
    SetSize(100.f, 100.f);
    SetSpeed(400.f);
    SetPivot(0.5f, 0.5f);

    m_iHP = 100;
    
    SetTexture("Player", L"sigongjoa.bmp");

    CColliderRect* pRC = AddCollider<CColliderRect>("PlayerBody");

    pRC->SetRect(-50.f, -50.f, 50.f, 50.f);
    pRC->AddCollisionFunction(CS_ENTER, this, &CPlayer::Hit);

    SAFE_RELEASE(pRC);


    return true;
}

void CPlayer::Input(float fDeltaTime)
{
    CMoveObj::Input(fDeltaTime);

    if (KEYPRESS("MoveFront"))
    {
        MoveYFromSpeed(fDeltaTime, MD_BACK);
    }

    if (KEYPRESS("MoveLeft"))
    {
        MoveXFromSpeed(fDeltaTime, MD_BACK);
    }

    if (KEYPRESS("MoveBack"))
    {
        MoveYFromSpeed(fDeltaTime, MD_FRONT);
    }

    if (KEYPRESS("MoveRight"))
    {
        MoveXFromSpeed(fDeltaTime, MD_FRONT);
    }

    if (KEYDOWN("Fire"))
    {
        Fire();
    }
    if (KEYDOWN("Skill1"))
    {
        MessageBox(NULL, L"Skill1", L"Skill1", MB_OK);
    }
}

int CPlayer::Update(float fDeltaTime)
{
    CMoveObj::Update(fDeltaTime);


    return 0;
}

int CPlayer::LateUpdate(float fDeltaTime)
{
    CMoveObj::LateUpdate(fDeltaTime);


    return 0;
}

void CPlayer::Collision(float fDeltaTime)
{
    CMoveObj::Collision(fDeltaTime);


}

void CPlayer::Render(HDC hDC, float fDeltaTime)
{
    CMoveObj::Render(hDC, fDeltaTime);
    wchar_t strHP[32] = {};

    POSITION tPos = m_tPos - (m_tSize * m_tPivot);
    tPos -= GET_SINGLE(CCamera)->GetPos();

    wsprintf(strHP, L"HP: %d ", m_iHP);
    TextOut(hDC, tPos.x, tPos.y, strHP, lstrlen(strHP));
}

CPlayer* CPlayer::Clone()
{
    return new CPlayer(*this);
}

void CPlayer::Hit(CCollider* pSrc, CCollider* pDest, float fDeltaTime)
{
    m_iHP -= 5;
}

void CPlayer::Fire()
{
    CObj* pBullet = CObj::CreateCloneObj("Bullet", "PlayerBullet", m_pLayer);

    pBullet->AddCollisionFunction("BulletBody", CS_ENTER, (CBullet*)pBullet, &CBullet::Hit);

    POSITION    tPos;
    tPos.x = GetRight() + pBullet->GetSize().x * pBullet->GetPivot().x;
    tPos.y = GetCenter().y;


    pBullet->SetPos(tPos);

    SAFE_RELEASE(pBullet);
}
