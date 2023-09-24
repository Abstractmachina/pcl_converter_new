#include "Conversions.h"

namespace PCL_CLI {

	// Native Conversions
	float* Convert_To_NativeFloatArray(array<float>^ input) {
		pin_ptr<float> array_pin = &input[0];
		float* nativeArray = array_pin;
		return nativeArray;
	}



	float* Convert_To_NativeFloatArray(PointCloudXYZ^ inputCloud) {
		array<float>^ pts = Convert_To_ManagedFloatArray(inputCloud);
		return Convert_To_NativeFloatArray(pts);
	}


	// CLI Conversions

	array<float>^ Convert_To_ManagedFloatArray(PointCloudXYZ^ inputCloud) {
		const int numRows = inputCloud->Size;
		array<float>^ pts = gcnew array<float>(numRows * POINTXYZSIZE);

		for (int r = 0; r < numRows; r++) {
			int curIdx = r * POINTXYZSIZE;
			pts[curIdx] = inputCloud[r]->X;
			pts[curIdx + 1] = inputCloud[r]->Y;
			pts[curIdx + 2] = inputCloud[r]->Z;
		}
		return pts;
	}

	array<float>^ Convert_To_ManagedFloatArray(float* input, int length) {
		auto output = gcnew array<float>(length);

		for (int i = 0; i < length; i++) {
			output[i] = input[i];
		}
		return output;
	}

	array<int>^ Convert_To_ManagedIntArray(int* input, int length) {
		auto output = gcnew array<int>(length);

		for (int i = 0; i < length; i++) {
			output[i] = input[i];
		}
		return output;
	}

}