#pragma once
#include "../Defines/Enums.h"
#include "../Defines/Structs.h"

class  MInputManager
{
public:
	MInputManager();

	virtual bool isKeyDown(const  CXKey& key);
	virtual bool isKeyUp(const  CXKey& key);

	virtual bool isMouseDown(const  CXMouseButton& button);
	virtual bool isMouseUp(const  CXMouseButton& button);

	virtual f32 getMouseXAxis();
	virtual f32 getMouseYAxis();

	virtual void enablePlayMode(bool enable);

	void setScreenArea(const  CXRect& area);
	void update();

private:
	short m_keys_state[256] = {};
	short m_old_keys_state[256] = {};
	short m_keys_state_res[256] = {};

	bool m_playEnable = false;
	CXVec2 m_old_mouse_pos;
	bool m_first_time = true;
	CXRect m_screenArea;
	CXVec2 m_deltaMouse;
	int states_index = 0;
};
