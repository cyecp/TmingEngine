/*
			This file is part of:
				TmingEngine
			https://github.com/xiaomingfun/TmingEngine

   Copyright 2018 - 2020 TmingEngine

   File creator: littleblue

   TmingEngine is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef TmingEngine_Engine_Rending_SoftGL_hpp_
#define TmingEngine_Engine_Rending_SoftGL_hpp_

#include "Core/Math/Vector3.h"
#include "Core/Math/Matrix.h"
#include "Rendering/Light.hpp"
#include "Rendering/RHI/IVertex.hpp"
#include "Rendering/RHI/IShader.hpp"
#include "tgaimage/tgaimage.h"

namespace TmingEngine
{
	const TGAColor white = TGAColor(255, 255, 255, 125);
	const TGAColor red = TGAColor(255, 0, 0, 255);
	const TGAColor green = TGAColor(0, 255, 0, 255);
	const TGAColor blue = TGAColor(0, 0, 255, 255);

	Vector3 barycentricCoordinate(Vector3 a, Vector3 b, Vector3 c, Vector3 p);

	Vector3 barycentricCoordinateCrossProduct(Vector3 a, Vector3 b, Vector3 c, Vector3 p);

	Vector3 barycentricCoordinateCrossProduct(IVertex a, IVertex b, IVertex c, IVertex p);

	void fillUpTriangle(Vector2 t0, Vector2 t1, Vector2 t2, TGAImage& image, TGAColor color);

	void fillDownTriangle(Vector2 t0, Vector2 t1, Vector2 t2, TGAImage& image, TGAColor color);

	Vector2* findTriangleBox(Vector2 t0, Vector2 t1, Vector2 t2);

	Vector2* findTriangleBox(Vector3 t0, Vector3 t1, Vector3 t2);

	void point(int x, int y, TGAImage& image, TGAColor color);

	void line(int x0, int y0, int x1, int y1, TGAImage& image, TGAColor color);

	void line(Vector2 x, Vector2 y, TGAImage& image, TGAColor color);

	void triangle(Vector2 t0, Vector2 t1, Vector2 t2, TGAImage& image, TGAColor color);

	void triangle(IVertex t0, IVertex t1, IVertex t2, TGAImage& image, TGAColor color);

	void drawBox(Vector2 miniP, Vector2 maxP, TGAImage& image, TGAColor color);

	void fillTriangleFromEdge(Vector2 A, Vector2 B, Vector2 C, TGAImage& image, TGAColor color);

	void fillTriangleFromEdge(Vector3 t0, Vector3 t1, Vector3 t2, TGAImage& image, TGAColor color, ILight* sunlitght);

	void fillTriangleFromEdgeWitchZbuffer(Vector3 t0, Vector3 t1, Vector3 t2, int frameWidth, int frameHeight, TGAImage& image, TGAColor color, int* zbuffer, ILight* sunlitght, IShader* shader);

	void fillTriangleFromEdgeWitchZbuffer(IVertex v1, IVertex v2, IVertex v3, int frameWidth, int frameHeight, TGAImage& image, TGAColor color, int* zbuffer, ILight* sunlitght, IShader* shader);

	void fillTriangleLinerScan(Vector2 t0, Vector2 t1, Vector2 t2, TGAImage& image, TGAColor color);
} // namespace TmingEngine

#endif //TmingEngine_Engine_Rending_SoftGL_hpp_