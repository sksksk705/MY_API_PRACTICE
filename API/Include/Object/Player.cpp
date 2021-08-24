#include "Player.h"
#include "Bullet.h"

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
    SetAngleSpeed(5.f);
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

    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        CBullet* bullet = CreateObj<CBullet>("Bullet", this->GetLayer());

        bullet->SetAngle(GetAngle());

        bullet->SetPos(GetPos().x + GetSize().x/2 + cosf(GetAngle()) * 50, GetPos().y + GetSize().y/2 + sinf(GetAngle()) * 50);

        SAFE_RELEASE(bullet);

    }

    if (GetAsyncKeyState('J') & 0x8000)
    {
         Rotation(fDeltaTime, MD_FRONT);
    }

    if (GetAsyncKeyState('K') & 0x8000)
    {
        Rotation(fDeltaTime, MD_BACK);
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
