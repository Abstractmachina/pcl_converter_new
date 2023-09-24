#pragma once
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include "Constants.h"




namespace PCL_CORE
{
	class Features {

	public:
		Features() {}


		static float* normal_estimation(float* points, const int rows, float searchRadius);
	};
}