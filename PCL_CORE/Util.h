#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "Constants.h"

namespace PCL_CORE {

	class Util {
	public:
		/// <summary>
		/// Create a pcl::Pointcloud from a array of points represented as a float array. the points values are flattened so they are arranged sequentially (x1,y1,z1, x2,y2,z2, ...)
		/// </summary>
		/// <param name="points">flattened point array</param>
		/// <param name="numRows">number of dimensions of points.</param>
		/// <returns></returns>
		static pcl::PointCloud<pcl::PointXYZ>::Ptr create_pointcloud(const float* points, const int numRows);
	};

}