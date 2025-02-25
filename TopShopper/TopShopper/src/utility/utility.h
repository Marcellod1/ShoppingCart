#ifndef UTILITY_H_
#define UTILITY_H_

// NOTE: always implement global funcions inside a .cpp, otherwise if multiple files includes this header, you get a linker error (same symbol multi defined)


#include <vector>
#include <glm/glm.hpp>
#include <foundation/PxVec3.h>
#include <foundation/PxQuat.h>
#include <memory>



class Entity;



struct ItemLocation {
	enum TargetTypes {
		OTHER,
		COOKIE,
		MYSTERY_BAG,
		PASS_OFF_HOT_POTATO
	};

	ItemLocation() {}
	ItemLocation(physx::PxVec3 pos, bool inWorld, TargetTypes targetType, std::shared_ptr<Entity> targetEntity) : _pos(pos), _inWorld(inWorld), _targetType(targetType), _targetEntity(targetEntity) {}
	physx::PxVec3 _pos;
	bool _inWorld; // either PHYSICALLY IN WORLD or ON A PLAYER
	TargetTypes _targetType;
	std::shared_ptr<Entity> _targetEntity = nullptr;
};


physx::PxVec3 castGLMVec4ToPxVec3(glm::vec4 glmVec);

std::vector<physx::PxVec3> castVectorOfGLMVec4ToVectorOfPxVec3(std::vector<glm::vec4> v_glmVec);


bool isApproxEqual(physx::PxVec3 v1, physx::PxVec3 v2);

physx::PxQuat toQuaternion(double yaw, double pitch, double roll);
void toEulerAngle(const physx::PxQuat& q, double& roll, double& pitch, double& yaw);



#endif // UTILITY_H_