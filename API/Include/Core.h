#pragma once
#include "Game.h"

class CCore
{
private:
	static CCore* m_pInst;
	static bool m_bLoop;

public:
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}

private:
	CCore();
	~CCore();

private:
	HINSTANCE	m_hInst;
	HWND		m_hWnd;
	RESOLUTION	m_tRS;
	HDC			m_hDC;

public:
	bool Init(HINSTANCE hInst);
	int Run();
	RESOLUTION GetResolution() const
	{
		return m_tRS;
	}

private:
	ATOM MyRegisterClass();
	BOOL Create();
	void Logic();

	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(float fDeltaTime);

public:
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

