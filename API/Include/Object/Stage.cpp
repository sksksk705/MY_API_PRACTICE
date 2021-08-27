#include "Stage.h"
#include "../Resources/Texture.h"
#include "../Core.h"
#include "../Core/Camera.h"
CStage::CStage()
{
}

CStage::CStage(const CStage& stage) :
	CStaticObj(stage)
{
}

CStage::~CStage()
{
}

bool CStage::Init()
{
	SetPos(0.f, 0.f);
	SetSize(2400.f, 1351.f);
	SetPivot(0.f, 0.f);

	SetTexture("Stage", L"Stage1_1.bmp");
	return true;
	return true;
}

void CStage::Input(float fDeltaTime)
{
	CStaticObj::Input(fDeltaTime);
}

int CStage::Update(float fDeltaTime)
{
	CStaticObj::Update(fDeltaTime);
	return 0;
}

int CStage::LateUpdate(float fDeltaTime)
{
	CStaticObj::LateUpdate(fDeltaTime);
	return 0;
}

void CStage::Collision(float fDeltaTime)
{
	CStaticObj::Collision(fDeltaTime);
}

void CStage::Render(HDC hDC, float fDeltaTime)
{
	//CStaticObj::Render(hDC, fDeltaTime);

	if (m_pTexture)
	{
		POSITION tPos = m_tPos - (m_tSize * m_tPivot);

		POSITION tCamPos = GET_SINGLE(CCamera)->GetPos();

		BitBlt(hDC, tPos.x, tPos.y, GETRESOLUTION.iW, GETRESOLUTION.iH, m_pTexture->GetDC(), tCamPos.x, tCamPos.y, SRCCOPY);
	}
}

CStage* CStage::Clone()
{
	return new CStage(*this);
}
