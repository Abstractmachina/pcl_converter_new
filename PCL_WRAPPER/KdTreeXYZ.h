#pragma once

#include "ManagedObject.h"
#include <pcl/search/kdtree.h>

namespace PCL_CLI {
	public ref class KdTreeXYZ : ManagedObject<pcl::search::KdTree<pcl::PointXYZ>> {
	public:
		KdTreeXYZ() : ManagedObject(new pcl::search::KdTree<pcl::PointXYZ>) {}

	};
}