#pragma once
#include "Entity.h"
#include "../Defines/TotalIncludes.h"


class  MCameraEntity : public  MEntity
{
public:
	MCameraEntity();
	virtual ~MCameraEntity();

	FORCEINLINE void setNearPlane(float nearPlane) {
		m_nearPlane = nearPlane;
	};
	FORCEINLINE void setFarPlane(float farPlane) {
		m_farPlane = farPlane;
	};
	FORCEINLINE void setScreenArea(const  DirectX::SimpleMath::Rectangle& screen) {
		m_screenArea = screen;
	};
	FORCEINLINE void setFOV(float fov) {
		m_fieldOfView = fov;
	};
	FORCEINLINE void setProjectionMode(EProjectionMode projectionMode) {
		m_ProjectionMode = projectionMode;
	};

	FORCEINLINE Matrix getViewMatrix() const {
		return m_view;
	};
	FORCEINLINE Matrix getProjectionMatrix() const {
		return m_projection;
	};

	FORCEINLINE float getNearPlane() const {
		return m_nearPlane;
	};
	FORCEINLINE float getFarPlane() const {
		return m_farPlane;
	};
	FORCEINLINE DirectX::SimpleMath::Rectangle getScreenArea() const {
		return m_screenArea;
	};
	FORCEINLINE float getFOV() const {
		return m_fieldOfView;
	};
	FORCEINLINE EProjectionMode getProjectionMode() const {
		return m_ProjectionMode;
	};

private:
	Matrix m_view;
	Matrix m_projection;

	float m_nearPlane = 0.1f;
	float m_farPlane = 100.0f;
	float m_fieldOfView = 90.0f;
	DirectX::SimpleMath::Rectangle m_screenArea;

	EProjectionMode m_ProjectionMode = EProjectionMode::PERSPECTIVE;
};
