#include "Search.h"


namespace PCL_CLI {
    

    array<int>^ PCL_CLI::Search::KdTreeKNNSearch(const int searchPtIdx,
        PointCloudXYZ^ inputCloud, const int k, array<float>^% out_distances) {

        auto pts = Convert_To_NativeFloatArray(inputCloud);


        float* out_d = new float[k];

        auto ks = PCL_CORE::Search::kdtree_knn_search(
            searchPtIdx, pts, inputCloud->Size, k, out_d);

        std::cout << "Distances CLI:" << std::endl;
        for (int i = 0; i < k; i++) {
            std::cout << out_d[i] << std::endl;
        }
        out_distances = Convert_To_ManagedFloatArray(out_d, k);

        return Convert_To_ManagedIntArray(ks, k);
    }

    array<int>^ PCL_CLI::Search::KdTreeKNNSearch(array<float>^ searchCoords, PointCloudXYZ^ inputCloud,
        const int k, array<float>^% out_distances) {


        auto pointCloud = Convert_To_NativeFloatArray(inputCloud); // cpp array
        float* out_d = new float[k]; // cpp array

        auto nativeSearchCoords = Convert_To_NativeFloatArray(searchCoords);

        std::vector<int> neighborIndices = PCL_CORE::Search::kdtree_knn_search(
            nativeSearchCoords, pointCloud, inputCloud->Size, k, out_d);

        std::cout << "Distances CLI:" << std::endl;
        for (int i = 0; i < k; i++) {
            std::cout << out_d[i] << std::endl;
        }
        out_distances = Convert_To_ManagedFloatArray(out_d, k);

        delete[] out_d;
        delete[] nativeSearchCoords;
        delete[] pointCloud;


        return Convert_To_ManagedIntArray(neighborIndices, k);

    }

    int PCL_CLI::Search::KdTreeRadiusSearch(array<float>^ searchPointCoords, PointCloudXYZ^ pointCloud, const float radius, List<int>^% out_indices, List<float>^% out_distances, unsigned int maxNn)
    {

        // convert pointcloud to float array
        auto flatCloud = Convert_To_NativeFloatArray(pointCloud); // cpp array
        std::vector<int> out_idx; //
        std::vector<float> out_dist_test;

        auto nativeSearchCoords = Convert_To_NativeFloatArray(searchPointCoords);

        auto neighborsFound = PCL_CORE::Search::kdtree_radius_search(
            nativeSearchCoords, flatCloud, pointCloud->Size, radius, out_idx, out_dist_test, maxNn);


        if (neighborsFound > 0) {
            for (int i = 0; i < neighborsFound; i++) {
                out_indices->Add(out_idx[i]);
                out_distances->Add(out_dist_test[i]);
            }
        }

        //out_distances = Convert_To_ManagedFloatArray(out_d, k);

        // clean up


        return neighborsFound;
    }

}