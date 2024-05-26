#include "Entity.h"

MEntity::MEntity()
{
}

MEntity::~MEntity()
{
}

void MEntity::release()
{

}

void MEntity::processWorldMatrix()
{

}

size_t MEntity::getId()
{
	return m_id;
}

void MEntity::getWorldMatrix(Matrix& world)
{
	world = m_world;
}

void MEntity::setPosition(const Vector3& position)
{
	m_position = position;
}

void MEntity::setRotation(const Vector3& rotation)
{
	m_rotation = rotation;
}

void MEntity::setScale(const Vector3& scale)
{
	m_scale = scale;
}

Vector3 MEntity::getPosition() const
{
	return m_position;
}

Vector3 MEntity::getRotation() const
{
	return m_rotation;
}

Vector3 MEntity::getScale() const
{
	return m_scale;
}
