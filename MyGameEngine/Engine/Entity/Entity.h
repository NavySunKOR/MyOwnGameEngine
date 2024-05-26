#pragma once
#include "../Defines/TotalIncludes.h"

class MGameApplication;

class MEntity
{
public:
	MEntity();
	virtual ~MEntity();

public:
	size_t getId();
	void getWorldMatrix(Matrix& world);
	void setPosition(const  Vector3& position);
	void setRotation(const  Vector3& rotation);
	void setScale(const  Vector3& scale);

	Vector3 getPosition() const;
	Vector3 getRotation() const;
	Vector3 getScale() const;

	MGameApplication* getGame() { return m_game; };

	virtual void onCreate() {}
	virtual void onUpdate(float deltaTime) {}
	virtual void release();
protected:
	void processWorldMatrix();
protected:
	Matrix m_world;

	Vector3 m_position;
	Vector3 m_rotation;
	Vector3 m_scale = Vector3(1, 1, 1);

	size_t m_id = 0;

	MGameApplication* m_game = nullptr;
	friend class  MGameApplication;
};
