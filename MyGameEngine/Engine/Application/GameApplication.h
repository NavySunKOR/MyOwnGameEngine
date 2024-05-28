#pragma once
#include "../Defines/TotalIncludes.h"

class MGameApplication
{
	public:
		MGameApplication();
		virtual ~MGameApplication();

		virtual void onCreate() {}
		virtual void onUpdate(float deltaTime) {}
		virtual void onQuit() {}	
		
		void setTitle(const wchar_t* title);
		void run();
		void quit();

		//CXInputManager* getInputManager();
		//CXGraphicsEngine* getGraphicsEngine();
		//CXResourceManager* getResourceManager();

private:
	//void onDisplaySize(const  Rect& size);


private:
	std::unique_ptr<class MInputManager> m_inputManager;
	std::unique_ptr<class MResourceManager> m_resourceManager;
	std::unique_ptr<class MRenderModule> m_renderModule;
	std::unique_ptr<class MWindow> m_windows;
	std::map<size_t, std::map<class MEntity*, std::unique_ptr<MEntity>>> m_entities;
	std::set<MEntity*> m_entitiesToDestroy;

	friend class MEntity;
	friend class MInputManager;

};


MGameApplication* GameApp = nullptr;