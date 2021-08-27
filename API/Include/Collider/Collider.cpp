#include "Collider.h"
#include "../Object/Obj.h"
#include "../Core/Math.h"


CCollider::CCollider()
{
}

CCollider::CCollider(const CCollider& coll)
{
    *this = coll;
}

CCollider::~CCollider()
{
    list<CCollider*>::iterator	iter;
    list<CCollider*>::iterator	iterEnd = m_CollisionList.end();
    for (iter = m_CollisionList.begin(); iter != iterEnd; ++iter)
    {
        (*iter)->EraseCollisionList(this);
    }
}

void CCollider::Input(float fDeltaTime)
{
}

int CCollider::Update(float fDeltaTime)
{
    return 0;
}

int CCollider::LateUpdate(float fDeltaTime)
{
    return 0;
}

bool CCollider::Collision(CCollider* pDest)
{
    return false;
}

void CCollider::Render(HDC hDC, float fDeltaTime)
{
}

bool CCollider::CollisionRectToRect(const RECTANGLE& src, const RECTANGLE& dest)
{

    if (src.l > dest.r)
        return false;
    else if (src.r < dest.l)
        return false;
    else if (src.t > dest.b)
        return false;
    else if (src.b < dest.t)
        return false;

    return true;
}

bool CCollider::CollisionRectToSphere(const RECTANGLE& src, const SPHERE& dest)
{
    if (dest.tCenter.x >= src.l && dest.tCenter.x <= src.r ||
        dest.tCenter.y >= src.t && dest.tCenter.y <= src.b)
    {
        RECTANGLE tRC = src;
        tRC.l -= dest.fRadius;
        tRC.t -= dest.fRadius;
        tRC.r += dest.fRadius;
        tRC.b += dest.fRadius;

        if (dest.tCenter.x < tRC.l)
            return false;
        else if (dest.tCenter.x > tRC.r)
            return false;
        else if (dest.tCenter.y < tRC.t)
            return false;
        else if (dest.tCenter.y > tRC.b)
            return false;
        return true;
    }

    POSITION    tPos[4];
    tPos[0] = POSITION(src.l, src.t);
    tPos[1] = POSITION(src.r, src.t);
    tPos[2] = POSITION(src.l, src.b);
    tPos[3] = POSITION(src.r, src.b);

    for (int i = 0; i < 4; ++i)
    {
        CMath math;
        float fDist = math.Distance(tPos[i], dest.tCenter);
        if (fDist <= dest.fRadius)
            return true;
    }
    return false;
}

bool CCollider::CollisionSphereToSphere(const SPHERE& src, const SPHERE& dest)
{
    CMath Math;;
    float fDist = Math.Distance(src.tCenter, dest.tCenter);
    return fDist <= src.fRadius + dest.fRadius;

    return false;
}

