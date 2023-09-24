#pragma once
#include "PointCloud.h"
#include "Constants.h"

namespace PCL_CLI {
	
	// Native Conversions

	/*pin_ptr<float>^ float_2darray_conversion(array<float, 2>^ input) {
		pin_ptr<float> arrayPin = &input[0, 0];
		return arrayPin;
	}*/

	float* Convert_To_NativeFloatArray(array<float>^ input);
	float* Convert_To_NativeFloatArray(PointCloudXYZ^ inputCloud);
	
	// CLI Conversions

	array<float>^ Convert_To_ManagedFloatArray(PointCloudXYZ^ inputCloud);
	array<float>^ Convert_To_ManagedFloatArray(float* input, int length);
	array<int>^ Convert_To_ManagedIntArray(int* ks, int length);


}