#pragma once

#include "ManagedObject.h"
#include <pcl/impl/point_types.hpp>




namespace PCL_CLI {

	public ref class PointXYZ : ManagedObject < pcl::PointXYZ> {
	public:
		PointXYZ();
		PointXYZ(float x, float y, float z);

		property float X {
			float get();
			void set(float value);
		};
		property float Y {
			float get();
			void set(float value);
		};
		property float Z {
			float get();
			void set(float value);
		};

		String^ ToString() override;
	};

	public ref class Normal : ManagedObject<pcl::Normal> {
	public:
		Normal() : ManagedObject(new pcl::Normal()) {}

		Normal(float x, float y, float z, float curvature)
			: ManagedObject(new pcl::Normal(x, y, z, curvature)) {}

		property float Curvature {
			float get() {
				return Instance->curvature;
			}
			void set(float value) {
				Instance->curvature = value;
			}
		}

		property float Normal_X {
			float get() {
				return Instance->normal_x;
			}
			void set(float value) {
				Instance->normal_x = value;
			}
		}

		property float Normal_Y {
			float get() {
				return Instance->normal_y;
			}
			void set(float value) {
				Instance->normal_y = value;
			}
		}

		property float Normal_Z {
			float get() {
				return Instance->normal_z;
			}
			void set(float value) {
				Instance->normal_z = value;
			}
		}

		String^ ToString() override;
	};

}