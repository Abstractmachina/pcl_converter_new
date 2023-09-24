#include <pcl/point_cloud.h>
#include <pcl/kdtree/kdtree_flann.h>

#include "Search.h"

#include <iostream>
#include <vector>
#include <ctime>

namespace PCL_CORE {

	int* Search::kdtree_knn_search(const int searchPtIdx, const float* inputCloud,
		const int numPoints, const int k, float* out_distances) {

		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr = PCL_CORE::Util::create_pointcloud(inputCloud, numPoints);

		// init kdtree
		pcl::KdTreeFLANN<pcl::PointXYZ> tree;
		tree.setInputCloud(cloud_ptr);

		// define search point by selecting index
		auto searchPt = (*cloud_ptr)[searchPtIdx];

		// K-nearest neighbor search
		std::vector<int> pointIdxNKNSearch(k);
		std::vector<float> pointNKNSquaredDistance(k);

		std::cout << "K nearest neighbor search at (" << searchPt.x
			<< " " << searchPt.y
			<< " " << searchPt.z
			<< ") with K=" << k << std::endl;

		if (tree.nearestKSearch(searchPt, k, pointIdxNKNSearch, pointNKNSquaredDistance) > 0) {
			for (std::size_t i = 0; i < pointIdxNKNSearch.size(); ++i)
				std::cout << "    " << (*cloud_ptr)[pointIdxNKNSearch[i]].x
				<< " " << (*cloud_ptr)[pointIdxNKNSearch[i]].y
				<< " " << (*cloud_ptr)[pointIdxNKNSearch[i]].z
				<< " (squared distance: " << pointNKNSquaredDistance[i] << ")" << std::endl;
		}
		int* indices = new int[k];

		for (int i = 0; i < k; i++)
			indices[i] = pointIdxNKNSearch[i];

		float* dists = new float[k];
		std::cout << "Distances CPP:\n";
		for (int i = 0; i < k; i++) {
			out_distances[i] = pointNKNSquaredDistance[i];

			std::cout << out_distances[i] << std::endl;
		}

		//out_distances = dists;

		return indices;
	}

	int* Search::kdtree_radius_search(const int searchPtIdx, const float* inputCloud,
		const int numPoints, const float r, float* out_distances) {

		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr
			= PCL_CORE::Util::create_pointcloud(inputCloud, numPoints);


		pcl::KdTreeFLANN<pcl::PointXYZ> tree;

		tree.setInputCloud(cloud_ptr);

		auto searchPt = (*cloud_ptr)[searchPtIdx];

		// Neighbors within radius search

		std::vector<int> pointIdxRadiusSearch;
		std::vector<float> pointRadiusSquaredDistance;

		/*std::cout << "Neighbors within radius search at (" << searchPt.x
			<< " " << searchPt.y
			<< " " << searchPt.z
			<< ") with radius=" << radius << std::endl;*/


		if (tree.radiusSearch(searchPt, r, pointIdxRadiusSearch, pointRadiusSquaredDistance) > 0) {
			//for (std::size_t i = 0; i < pointIdxRadiusSearch.size(); ++i)
			//	std::cout << "    " << (*cloud_ptr)[pointIdxRadiusSearch[i]].x
			//	<< " " << (*cloud_ptr)[pointIdxRadiusSearch[i]].y
			//	<< " " << (*cloud_ptr)[pointIdxRadiusSearch[i]].z
			//	<< " (squared distance: " << pointRadiusSquaredDistance[i] << ")" << std::endl;
		}

		int k = pointIdxRadiusSearch.size();

		int* indices = new int[k];

		for (int i = 0; i < k; i++)
			indices[i] = pointIdxRadiusSearch[i];

		float* dists = new float[k];
		for (int i = 0; i < k; i++)
			dists[i] = pointRadiusSquaredDistance[i];

		out_distances = dists;

		return indices;
	}
}