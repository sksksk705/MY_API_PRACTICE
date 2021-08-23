#include "Player.h"

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
    SetPos(100.f, 100.f);
    SetSize(100.f, 100.f);
    SetSpeed(400.f);
    return true;
}

void CPlayer::Input(float fDeltaTime)
{
    CMoveObj::Input(fDeltaTime);

    if (GetAsyncKeyState('W') & 0x8000)
    {
        MoveYFromSpeed(fDeltaTime, MD_BACK);
    }

    if (GetAsyncKeyState('A') & 0x8000)
    {
        MoveXFromSpeed(fDeltaTime, MD_BACK);
    }

    if (GetAsyncKeyState('S') & 0x8000)
    {
        MoveYFromSpeed(fDeltaTime, MD_FRONT);
    }

    if (GetAsyncKeyState('D') & 0x8000)
    {
        MoveXFromSpeed(fDeltaTime, MD_FRONT);
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


    Rectangle(hDC, m_tPos.x, m_tPos.y, m_tPos.x + m_tSize.x , m_tPos.y + m_tSize.y);
}
