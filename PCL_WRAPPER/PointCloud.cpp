#include "PointCloud.h"

namespace PCL_CLI {

	int PointCloudXYZ::Size::get() {
		return Instance->size();
	}

	PointXYZ^ PointCloudXYZ::default::get(int idx) {
		float x = (*Instance)[idx].x;
		float y = (*Instance)[idx].y;
		float z = (*Instance)[idx].z;
		return gcnew PointXYZ(x,y,z);
	}


	int PointCloudNormal::Size::get() {
		return Instance->size();
	}

	Normal^ PointCloudNormal::default::get(int idx) {
		float x = (*Instance)[idx].normal_x;
		float y = (*Instance)[idx].normal_y;
		float z = (*Instance)[idx].normal_z;
		float c = (*Instance)[idx].curvature;
		return gcnew Normal(x, y, z, c);
	}
}