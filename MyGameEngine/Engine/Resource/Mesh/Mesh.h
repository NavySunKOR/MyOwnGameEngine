#pragma once
#include "../Resource.h"
#include <memory>
#include <vector>

class MVertexBuffer;
class MIndexBuffer;

class MMesh : MResource
{

public:
	MMesh(const wchar_t* full_path);
	MMesh(FVertex* vertices, unsigned int verticesCount,
		unsigned int* indices, unsigned int indicesCount,
		CXMaterialSlot* materials, unsigned int materialCounts);
	const  MVertexBuffer& getVertexBuffer();
	const  MIndexBuffer& getIndexBuffer();

	const  CXMaterialSlot& getMaterialSlot(unsigned int slot);
	size_t getNumMaterialSlots();

	Vector3 getMaxCorner();
	Vector3 getMinCorner();
private:
	void computeTangents(
		const  Vector3& v0, const  Vector3& v1, const  Vector3& v2,
		const  Vector3& t0, const  Vector3& t1, const  Vector3& t2,
		Vector3& tangent, Vector3& binormal);
private:
	std::shared_ptr<MVertexBuffer> m_vertexBuffer;
	std::shared_ptr<MIndexBuffer> m_indexBuffer;
	std::vector<CXMaterialSlot> m_mat_slots;

	Vector3 m_maxCorner;
	Vector3 m_minCorner = Vector3(10000, 10000, 10000);
};