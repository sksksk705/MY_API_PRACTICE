#include "Core.h"
#include "Scene/SceneManager.h"
#include "Core/Timer.h"
#include "Core/PathManager.h"
#include "Core/Camera.h"
#include "Core/Input.h"
#include "Collider/ColliderManager.h"
#include "Resources/ResourcesManager.h"
#include "Resources/Texture.h"

CCore* CCore::m_pInst = NULL;
bool CCore::m_bLoop = true;

CCore::CCore()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(250);
}

CCore::~CCore()
{
	DESTROY_SINGLE(CSceneManager);
	DESTROY_SINGLE(CCamera);
	DESTROY_SINGLE(CResourcesManager);
	DESTROY_SINGLE(CPathManager);
	DESTROY_SINGLE(CTimer);
	DESTROY_SINGLE(CInput);
	DESTROY_SINGLE(CColliderManager);


	ReleaseDC(m_hWnd, m_hDC);
}

bool CCore::Init(HINSTANCE hInst)
{
	m_hInst = hInst;

	if (!MyRegisterClass())
		return false;

	m_tRS.iW = 1280;
	m_tRS.iH = 720;

	if(!Create())
		return false;

	m_hDC = GetDC(m_hWnd);

	if (!GET_SINGLE(CTimer)->Init())
		return false;

	if (!GET_SINGLE(CInput)->Init(m_hWnd))
		return false;

	if (!GET_SINGLE(CPathManager)->Init())
		return false;

	if (!GET_SINGLE(CResourcesManager)->Init(hInst,m_hDC))
		return false;

	if (!GET_SINGLE(CCamera)->Init(POSITION(0.f, 0.f), m_tRS, RESOLUTION(2400, 1351)))
		return false;

	if (!GET_SINGLE(CSceneManager)->Init())
		return false;



	
	return true;
}


ATOM CCore::MyRegisterClass()
{

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; //MAKEINTRESOURCEW(IDC_PEEKMASSAGE);
	wcex.lpszClassName = L"AR13API";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);

}

BOOL CCore::Create()
{

	m_hWnd = CreateWindowW(L"AR13API", L"AR13API", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInst, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	RECT rc = { 0, 0, m_tRS.iW,  m_tRS.iH };

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	SetWindowPos(m_hWnd, HWND_TOPMOST, 100, 100, rc.right - rc.left, rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);


	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return TRUE;
}

void CCore::Logic()
{
	GET_SINGLE(CTimer)->Update();

	float fDeltaTime = GET_SINGLE(CTimer)->GetDeltaTime();

	Input(fDeltaTime);

	Update(fDeltaTime);

	LateUpdate(fDeltaTime);

	Collision(fDeltaTime);

	Render(fDeltaTime);
}

void CCore::Input(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Input(fDeltaTime);
	GET_SINGLE(CCamera)->Input(fDeltaTime);
}

int CCore::Update(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Update(fDeltaTime);
	GET_SINGLE(CCamera)->Update(fDeltaTime);
	GET_SINGLE(CInput)->Update(fDeltaTime);
	return 0;
}

int CCore::LateUpdate(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->LateUpdate(fDeltaTime);
	return 0;
}

void CCore::Collision(float fDeltaTime)
{
	GET_SINGLE(CSceneManager)->Collision(fDeltaTime);
	GET_SINGLE(CColliderManager)->Collision(fDeltaTime);
}

void CCore::Render(float fDeltaTime)
{
	CTexture* pBackBuffer = GET_SINGLE(CResourcesManager)->GetBackBuffer();

	Rectangle(pBackBuffer->GetDC(), 0, 0, 1280, 720);

	GET_SINGLE(CSceneManager)->Render(pBackBuffer->GetDC(), fDeltaTime);

	BitBlt(m_hDC, 0, 0, m_tRS.iW, m_tRS.iH, pBackBuffer->GetDC(), 0, 0, SRCCOPY);

	SAFE_RELEASE(pBackBuffer);
}

LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		m_bLoop = false;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



int CCore::Run()
{
	MSG msg;

	// �⺻ �޽��� �����Դϴ�:
	while (m_bLoop)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Logic();
		}
	}

	return (int)msg.wParam;
}