#include "InputManager.h"

MInputManager::MInputManager()
{
}

bool MInputManager::isKeyDown(const EKey& key)
{
	short keyWin = 0;

	if (key >= EKey::A && key <= EKey::Z)
		keyWin = 'A' + ((short)key - (short)EKey::A);
	else if (key >= EKey::N0 && key <= EKey::N9)
		keyWin = '0' + ((short)key - (short)EKey::N0);
	else if (key == EKey::Shift)
		keyWin = VK_SHIFT;
	else if (key == EKey::Escape)
		keyWin = VK_ESCAPE;
	else if (key == EKey::Space)
		keyWin = VK_SPACE;

	return  (m_keys_state_res[keyWin] == 0);
}

bool MInputManager::isKeyUp(const EKey& key)
{
	short keyWin = 0;

	if (key >= EKey::A && key <= EKey::Z)
		keyWin = 'A' + ((short)key - 2);
	else if (key >= EKey::N0 && key <= EKey::N9)
		keyWin = '0' + ((short)key - 28);
	else if (key == EKey::Shift)
		keyWin = VK_SHIFT;
	else if (key == EKey::Escape)
		keyWin = VK_ESCAPE;
	else if (key == EKey::Space)
		keyWin = VK_SPACE;

	return  (m_keys_state_res[keyWin] == 1);
}

bool MInputManager::isMouseDown(const EMouseButton& button)
{
	if (button == EMouseButton::Left)
	{
		auto state = m_keys_state_res[VK_LBUTTON];
		return (state == 0);

	}
	else if (button == EMouseButton::Middle)
	{
		auto state = m_keys_state_res[VK_MBUTTON];
		return (state == 0);
	}
	else if (button == EMouseButton::Right)
	{
		auto state = m_keys_state_res[VK_RBUTTON];
		return (state == 0);
	}

	return false;
}

bool MInputManager::isMouseUp(const EMouseButton& button)
{
	if (button == EMouseButton::Left)
	{
		auto state = m_keys_state_res[VK_LBUTTON];
		return  (state == 1);

	}
	else if (button == EMouseButton::Middle)
	{
		auto state = m_keys_state_res[VK_MBUTTON];
		return  (state == 1);
	}
	else if (button == EMouseButton::Right)
	{
		auto state = m_keys_state_res[VK_RBUTTON];
		return (state == 1);
	}
	return false;
}

void MInputManager::update()
{
	POINT current_mouse_pos = {};
	::GetCursorPos(&current_mouse_pos);

	if (current_mouse_pos.x != (int)m_old_mouse_pos.x || current_mouse_pos.y != (int)m_old_mouse_pos.y)
	{
		m_deltaMouse = Vector2((float)current_mouse_pos.x - (float)m_old_mouse_pos.x, (float)current_mouse_pos.y - (float)m_old_mouse_pos.y);
	}
	else
	{
		m_deltaMouse = Vector2(0, 0);
	}


	for (unsigned int i = 0; i < 256; i++)
	{
		m_keys_state[i] = ::GetAsyncKeyState(i);


		if (m_keys_state[i] & 0x8001)
		{
			m_keys_state_res[i] = 0;
		}
		else // KEY IS UP
		{
			if (m_keys_state[i] != m_old_keys_state[i])
			{
				m_keys_state_res[i] = 1;
			}
			else
			{
				m_keys_state_res[i] = 2;
			}
		}
	}

	::memcpy(m_old_keys_state, m_keys_state, sizeof(short) * 256);
}
