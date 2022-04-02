#pragma once

#include <glm/mat3x3.hpp>

#include <SDL.h>

#include "graphics/quad.h"

namespace Dragonfruit
{
	struct MeshComponent
	{
		Quad Mesh;

		operator Quad& () { return Mesh; }

//		MeshComponent(MeshComponent&) = default;
	};

	struct TransformComponent
	{
		Vector3<float> Position { 0.0f };
		Vector3<float> Rotation { 0.0f };
		Vector3<float> Scale { 1.0f };
	};

	struct NameComponent
	{
		const char* Name;
	};
}