#pragma once

#include "ManagedObject.h"
#include "../Pcl_CORE/Features.h"
#include "PointCloud.h"

namespace PCL_CLI {

	public ref class Features : ManagedObject<PCL_CORE::Features> {

	public:
		Features() : ManagedObject(new PCL_CORE::Features()) {}
		static PointCloudNormal^ NormalEstimation(PointCloudXYZ^ inputCloud, float searchRadius);

	};
}