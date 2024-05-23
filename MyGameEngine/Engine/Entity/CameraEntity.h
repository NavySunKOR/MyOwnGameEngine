#pragma once
#include "Entity.h"
#include "../Defines/Enums.h"


class  MCameraEntity : public  MEntity
{
public:
	MCameraEntity();
	virtual ~MCameraEntity();

	void setNearPlane(float farPlane);
	void setFarPlane(float farPlane);
	void setScreenArea(const  CXRect& screen);
	void setFOV(float farPlane);
	void setProjectionMode(float farPlane);

	CXMat4 getViewMatrix(Matrix& view);
	CXMat4 getProjectionMatrix(Matrix& proj);

	float getNearPlane() const;
	float getFarPlane() const;
	CXRect getScreenArea() const;
	float getFOV() const;
	EProjectionMode getProjectionMode() const;

private:
	CXMat4 m_view;
	CXMat4 m_projection;

	float m_nearPlane = 0.1f;
	float m_farPlane = 100.0f;
	float m_fieldOfView = 90.0f;
	CXRect m_screenArea;

	EProjectionMode m_ProjectionMode = EProjectionMode::PERSPECTIVE;
};
