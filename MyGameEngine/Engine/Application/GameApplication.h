#pragma once

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
	/*std::unique_ptr<CXInputManager> m_inputManager;
	std::unique_ptr<CXGraphicsEngine> m_graphicsEngine;
	std::unique_ptr<CXDisplay> m_display;
	std::unique_ptr<CXResourceManager> m_resourceManager;
	std::map<size_t, std::map<CXEntity*, std::unique_ptr<CXEntity>>> m_entities;
	std::set<CXEntity*> m_entitiesToDestroy;

	friend class  CXEntity;
	friend class  CXDisplay;
	*/

};