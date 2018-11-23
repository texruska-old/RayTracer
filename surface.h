#ifndef SURFACE_H
#define SURFACE_H

#include "colordata.h"
#include "vec3.h"
#include "boundableentity.h"
#include "rayinteractable.h"

#include <experimental/optional>
#include <functional>

namespace RayTracer {

class Scene;

class Surface : public BoundableEntity, public RayInteractable {
	protected:
		std::function<ColorData(const Vec3&)> colorDataFunc;
		std::function<ColorData(void)> colorDataFuncSimple;
	public:
		Surface(Scene * const _scene, const Vec3& _position, const Vec3& _angle, bool _canIntersectRays, bool _canGenerateRays);
		virtual ~Surface();

		ColorData getColorData();
		ColorData getColorData(const Vec3& _position);
		void setColorData(const ColorData& _colorData);
		void setColorData(std::function<ColorData(const Vec3&)> _colorDataFunc);
		virtual std::experimental::optional<Vec3> getHitNorm(const Vec3& _position) = 0;
		virtual std::vector<Vec3> getBasisVectors(double u, double v) = 0;
		virtual Vec3 getPointOnSurface(double u, double v) = 0;
		virtual std::experimental::optional<IntersectData> intersect(const Ray& _r, bool testForwards = true, bool testBackwards = false);
		virtual std::experimental::optional<IntersectData> getIntersectData(const Ray& _r, bool testForwards = true, bool testBackwards = false) = 0;
};

}

#endif
