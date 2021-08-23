#pragma once
#include "Scene.h"
class CIngameScene :
    public CScene
{
private:
    friend class CSceneManager;

private:
    CIngameScene();
    ~CIngameScene();

public:
    virtual bool Init();
};

