#include "Features.h"

namespace PCL_CLI {

	PointCloudNormal^ Features::NormalEstimation(PCL_CLI::PointCloudXYZ^ inputCloud, float searchRadius) {

		const int numRows = inputCloud->Size;
		array<float>^ pts = gcnew array<float>(numRows * PCL_CORE::POINTXYZSIZE);

		for (int r = 0; r < numRows; r++) {
			int curIdx = r * PCL_CORE::POINTXYZSIZE;
			pts[curIdx] = inputCloud[r]->X;
			pts[curIdx + 1] = inputCloud[r]->Y;
			pts[curIdx + 2] = inputCloud[r]->Z;
		}


		//array<Byte, N>^ byteMultiArray = Battle::Storm::GetBytes(0);
		pin_ptr<float> array_pin = &pts[0];
		float* nativeArray = array_pin;


		float* normals = new float[numRows * PCL_CORE::NORMALSIZE];

		//int t = Instance->test(searchRadius);
		normals = PCL_CORE::Features::normal_estimation(nativeArray, numRows, searchRadius);

		auto cloud_out = gcnew PointCloudNormal();

		for (int i = 0; i < numRows; i++) {
			int curIdx = i * PCL_CORE::NORMALSIZE;
			auto n = gcnew Normal(
				normals[curIdx], 
				normals[curIdx+1], 
				normals[curIdx+2], 
				normals[curIdx+3]);
			//Console::WriteLine(String::Format("normal: {0}", n->ToString()));
			//all good to here.
			cloud_out->Pushback(n);
		}

		return cloud_out;
	}

}