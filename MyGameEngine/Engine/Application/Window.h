#pragma once

class MWindow
{
public:
	MWindow();
	~MWindow();

	//Rect getClientSize();
	//Rect getScreenSize();

	//EVENT
	virtual void onCreate() {}
	virtual void onUpdate() {}
	virtual void onDestroy() {}
	virtual void onFocus() {}
	virtual void onKillFocus() {}
	//virtual void onSize(const  Rect& size) {}

	void* getHandle();
	void setTitle(const wchar_t* title);

protected:
	void* m_hwnd = nullptr;


};