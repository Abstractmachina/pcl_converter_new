#include "Util.h"

namespace PCL_CORE {

	pcl::PointCloud<pcl::PointXYZ>::Ptr Util::create_pointcloud(
		const float* pt_arr, const int num_points) {

		// instantiate empty point cloud
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZ>());

		//convert float array to points
		for (int r = 0; r < num_points; r++) {
			// multiply counter r with point size (which is 3).
			// every 3 sequential floats represent one point
			int curIdx = r * PCL_CORE::POINTXYZSIZE;
			float x = pt_arr[curIdx];
			float y = pt_arr[curIdx + 1];
			float z = pt_arr[curIdx + 2];
			auto p = new pcl::PointXYZ(x, y, z);

			cloud_ptr->push_back(*p);
		}

		/*cloud_ptr->width = num_points;
		cloud_ptr->height = 1;
		cloud_ptr->points.resize(cloud_ptr->width * cloud_ptr->height);*/

		return cloud_ptr;
	}

}