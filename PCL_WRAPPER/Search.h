#pragma once

#include "..\PCL_CORE\Search.h"
#include "PointCloud.h"
#include "Conversions.h"

namespace PCL_CLI {
	using namespace System::Collections::Generic;
	
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

		/// <summary>
		/// Search k-nearest neighbors by coordinate.
		/// </summary>
		/// <param name="searchCoords"></param>
		/// <param name="pointCloud"></param>
		/// <param name="k"></param>
		/// <param name="out_distances"></param>
		/// <returns></returns>
		static array<int>^ KdTreeKNNSearch(array<float>^ searchCoords, PointCloudXYZ^ pointCloud,
			const int k, List<float>^% out_distances);

		static int KdTreeRadiusSearch(array<float>^ searchPointCoords, PointCloudXYZ^ pointCloud, const float radius, List<int>^% out_indices , List<float>^% out_distances, unsigned int maxNn);
	};

}
