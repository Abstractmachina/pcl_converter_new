#pragma once

#include "Util.h"

namespace PCL_CORE {

	class Search {
	public:
		static int* kdtree_knn_search(const int searchPt, const float* pointCloud,
			const int numPoints, const int k, float* out_distances);
		static int* kdtree_radius_search(const int searchPt, const float* pointCloud,
			const int numPoints, const float r, float* out_distances);
	};

}