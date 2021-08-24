#include "IngameScene.h"
#include "../Object/Player.h"
#include "../Object/Minion.h"
#include "../Object/Bullet.h"
#include "Layer.h"


CIngameScene::CIngameScene()
{
}

CIngameScene::~CIngameScene()
{
}

bool CIngameScene::Init()
{
	if (!CScene::Init())
		return false;

	CLayer* pLayer = FindLayer("Default");

	CPlayer* pPlayer = CObj::CreateObj<CPlayer>("Player", pLayer);

	CMinion* pMinion = CObj::CreateObj<CMinion>("Minion", pLayer);

	CBullet* pBullet = CScene::CreatePrototype<CBullet>("Bullet");

	pBullet->SetSize(50.f, 50.f);

	SAFE_RELEASE(pPlayer);
	SAFE_RELEASE(pMinion);
	SAFE_RELEASE(pBullet);

	return true;
}
