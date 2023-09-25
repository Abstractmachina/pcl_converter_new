#pragma once

#include "Util.h"

namespace PCL_CORE {

	class Search {
	public:
		/// <summary>
		/// search k-nearest neighbors of a point in the point cloud.
		/// </summary>
		/// <param name="searchPtIdx">index of search point</param>
		/// <param name="pointCloud">point cloud in the form of a flattened float array</param>
		/// <param name="numPoints">number of points in point cloud</param>
		/// <param name="k">amount of neighbors to find</param>
		/// <param name="out_distances">the distances to the search point</param>
		/// <returns></returns>
		static int* kdtree_knn_search(const int searchPtIdx, const float* pointCloud,
			const int numPoints, const int k, float* out_distances);

		/// <summary>
		/// search k nearest neighbors around a specified search point.
		/// </summary>
		/// <param name="searchPointCoords"></param>
		/// <param name="pointCloud"></param>
		/// <param name="numPoints"></param>
		/// <param name="k"></param>
		/// <param name="out_distances"></param>
		/// <returns></returns>
		static std::vector<int> kdtree_knn_search(const float* searchPointCoords, const float* pointCloud,
			const int numPoints, const int k, float* out_distances);

		/// <summary>
		/// search k nearest neighbors based on distance defined as radius.
		/// </summary>
		/// <param name="searchPt"></param>
		/// <param name="pointCloud"></param>
		/// <param name="numPoints"></param>
		/// <param name="r"></param>
		/// <param name="out_distances"></param>
		/// <returns></returns>
		static int* kdtree_radius_search(const int searchPt, const float* pointCloud,
			const int numPoints, const float r, float* out_distances);

		static std::vector<int> kdtree_radius_search(const float* searchPointCoords, const float* pointCloud,
			const int numPoints, const float r, float* out_distances);
	};

}