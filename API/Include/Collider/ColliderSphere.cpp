#include "ColliderSphere.h"
#include "../Object/Obj.h"
#include "ColliderRect.h"

CColliderSphere::CColliderSphere()
{
    m_eCollType = CT_SPHERE;
}

CColliderSphere::CColliderSphere(const CColliderSphere& coll)
    :CCollider(coll)
{
    m_tInfo = coll.m_tInfo;
}

CColliderSphere::~CColliderSphere()
{
}

bool CColliderSphere::Init()
{
    return true;
}

void CColliderSphere::Input(float fDeltaTime)
{
    CCollider::Input(fDeltaTime);
}

int CColliderSphere::Update(float fDeltaTime)
{
    CCollider::Update(fDeltaTime);
    return 0;
}

int CColliderSphere::LateUpdate(float fDeltaTime)
{
    CCollider::LateUpdate(fDeltaTime);

    POSITION tPos = m_pObj->GetPos();
    m_tWorldInfo.tCenter = tPos+m_tInfo.tCenter;
    m_tWorldInfo.fRadius = m_tInfo.fRadius;

    return 0;
}

bool CColliderSphere::Collision(CCollider* pDest)
{
    CCollider::Collision(pDest);

    switch (pDest->GetColliderType())
    {
    case CT_RECT:
        return CollisionRectToSphere(((CColliderRect*)pDest)->GetWorldInfo(), m_tWorldInfo);
        break;
    case CT_SPHERE:
        return CollisionSphereToSphere(m_tWorldInfo, ((CColliderSphere*)pDest)->GetWorldInfo());
        break;
    }
}

void CColliderSphere::Render(HDC hDC, float fDeltaTime)
{
    CCollider::Render(hDC, fDeltaTime);
}

CColliderSphere* CColliderSphere::Clone()
{
    return new CColliderSphere(*this);
}
