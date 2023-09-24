#pragma once

#include "ManagedObject.h"
#include "PointTypes.h"
#include <pcl/point_cloud.h>

namespace PCL_CLI {
	public ref class PointCloudXYZ : ManagedObject<pcl::PointCloud<pcl::PointXYZ>> {
	public:
		PointCloudXYZ() : ManagedObject(new pcl::PointCloud<pcl::PointXYZ>) {}

		property int Size {int get(); };
		property PointXYZ^ default[int]{ PointXYZ^ get(int idx); }

		void Pushback(PCL_CLI::PointXYZ^ val) {
			auto p = new pcl::PointXYZ(val->X, val->Y, val->Z);
			Instance->push_back(*p);
		}
	};

	public ref class PointCloudNormal : ManagedObject<pcl::PointCloud<pcl::Normal>> {
	public:
		PointCloudNormal() : ManagedObject(new pcl::PointCloud<pcl::Normal>) {}
		//PointCloudNormal(pcl::PointCloud<pcl::Normal> input) : ManagedObject(&input) {}

		property int Size {int get(); };
		property Normal^ default[int]{ Normal^ get(int idx); }

		void Pushback(PCL_CLI::Normal^ val) {
			auto n = val->Instance;
			Instance->push_back(*n);
		}
	};
}
