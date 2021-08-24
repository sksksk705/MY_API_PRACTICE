#pragma once

#include "../Game.h"
#include "../Ref.h"
#include "../Scene/Layer.h"

class CObj:
	public CRef
{

protected:
	friend class CScene;

protected:
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj();

private:
	static list <CObj*> m_ObjList;


public:
	static void AddObj(CObj* pObj);
	static CObj* FindObject(const string& strTag);
	static void EraseObj(CObj* pObj);
	static void EraseObj(const string& strTag);
	static void EraseObj();


protected:
	class CScene* m_pScene;
	class CLayer* m_pLayer;


public:
	void SetScene(class CScene* pScene) { m_pScene = pScene; }
	void SetLayer(class CLayer* pLayer) { m_pLayer = pLayer; }

	class CScene* GetScene() const { return m_pScene; }
	class CLayer* GetLayer() const { return m_pLayer; }


protected:
	string		m_strTag;
	POSITION	m_tPos;
	_SIZE		m_tSize;
	POSITION	m_tPivot;


public:
	void SetTag(const string& strTag) { m_strTag = strTag; }
	void SetPos(const POSITION& tPos) { m_tPos = tPos; }
	void SetPos(float x, float y) { m_tPos.x = x;  m_tPos.y = y; }
	void SetSize(const _SIZE& tSize) { m_tSize = tSize; }
	void SetSize(float x, float y) { m_tSize.x = x;  m_tSize.y = y; }

	string GetTag() const { return m_strTag; }
	POSITION GetPos() const { return m_tPos; }
	_SIZE GetSize() const { return m_tSize; }

public:
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);
	virtual CObj* Clone() = 0;

public:
	template <typename T>
	static T* CreateObj(const string& strTag, class CLayer* pLayer = NULL)
	{
		T* pObj = new T;

		pObj->SetTag(strTag);

		if (!pObj->Init())
		{
			SAFE_DELETE(pObj);
			return NULL;
		}

		if (pLayer)
		{
			pLayer->AddObject(pObj);
		}

		AddObj(pObj);

		return pObj;
	}




	static CObj* CreateCloneObj(const string& strPrototypeKey, const string& strTag,
		class CLayer* pLayer = NULL);
	


};

