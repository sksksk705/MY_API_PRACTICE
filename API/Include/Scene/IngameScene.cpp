#include "IngameScene.h"
#include "../Object/Player.h"
#include "../Object/Minion.h"
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

	SAFE_RELEASE(pPlayer);
	SAFE_RELEASE(pMinion);

	return true;
}
