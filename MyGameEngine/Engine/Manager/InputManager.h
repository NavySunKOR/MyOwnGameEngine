#pragma once
#include "../Defines/TotalIncludes.h"


class  MInputManager
{
public:
	MInputManager();

	bool isKeyDown(const  EKey& key);
	bool isKeyUp(const  EKey& key);

	bool isMouseDown(const  EMouseButton& button);
	bool isMouseUp(const  EMouseButton& button);

	FORCEINLINE float getMouseXAxis() const {
		return m_deltaMouse.x;
	};
	FORCEINLINE float getMouseYAxis() const {
		return m_deltaMouse.y;
	};

	void update();

private:
	short m_keys_state[256] = {};
	short m_old_keys_state[256] = {};
	short m_keys_state_res[256] = {};

	bool m_playEnable = false;
	bool m_first_time = true;

	Vector2 m_old_mouse_pos;
	Vector2 m_deltaMouse;
	int states_index = 0;
};
