#include "Search.h"

namespace PCL_CLI {

    array<int>^ PCL_CLI::Search::KdTreeKNNSearch(const int searchPtIdx,
        PointCloudXYZ^ inputCloud, const int k, array<float>^% out_distances) {

        auto pts = Convert_To_NativeFloatArray(inputCloud);

        auto distReceiver = gcnew array<float>(k);

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

    array<int>^ PCL_CLI::Search::KdTreeKNNSearch(array<float>^ searchCoords, PointCloudXYZ^ pointCloud,
        const int k, array<float>^% out_distances) {

        // find point nearest to search coords.



        //do kdtree search with the found point idx.


    }

}