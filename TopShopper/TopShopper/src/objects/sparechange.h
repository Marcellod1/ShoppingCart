#ifndef SPARECHANGE_H_
#define SPARECHANGE_H_

#include "entity.h"

namespace physx {
	class PxRigidDynamic;
};

class SpareChange : public Entity {
	public:
		SpareChange(physx::PxRigidDynamic *actor);
		virtual ~SpareChange();

	private:

};




#endif // SPARECHANGE_H_
