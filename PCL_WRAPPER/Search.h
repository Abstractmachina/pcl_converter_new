#pragma once

#include "..\PCL_CORE\Search.h"
#include "PointCloud.h"
#include "Conversions.h"

namespace PCL_CLI {

	
	public ref class Search {
	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="searchPtIdx"></param>
		/// <param name="pointCloud"></param>
		/// <param name="k"></param>
		/// <param name="out_distances"></param>
		/// <returns></returns>
		static array<int>^ KdTreeKNNSearch(const int searchPtIdx, PointCloudXYZ^ pointCloud,
			const int k, array<float>^% out_distances);
		static array<int>^ KdTreeKNNSearch(array<float>^ searchCoords, PointCloudXYZ^ pointCloud,
			const int k, array<float>^% out_distances);
	};

}
