#include <Windows.h>
//#include <gl\GL.h>
#include "..\packages\nupengl.core.0.1.0.1\build\native\include\GL\freeglut.h"

#include "..\Util\Windows\Window.h"
#include "..\Util\Windows\Application.h"

using namespace CAN;

void OnInit(Object* pSender, EventArgs args)
{
	glClearColor(0.4f, 0.5f, 0.65f, 1.0f);
}

void OnRender(Object* pSender, EventArgs args)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OnResize(Object* pSender, ResizeEventArgs args)
{
	glViewport(0, 0, args.Width, args.Height);
}

void OnRelease(Object* pSender, EventArgs args)
{

}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmdArgs, int cmdShow)
{
	Application::Init(hInst);

	Window* mainWindow = new GLWindow;
	mainWindow->SetMainLoop(NotifyEvent(OnRender));
	mainWindow->SetInit(NotifyEvent(OnInit));
	mainWindow->SetResize(ResizeEvent(OnResize));
	mainWindow->SetRelease(NotifyEvent(OnRelease));

	mainWindow->Create(L"CANGui", 1280, 800);

	Application::Run(mainWindow);
	
	return 0;
}