using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using PCL_CLI;

namespace Sandbox {
    internal class Program {
        static void Main(string[] args) {

            string filepath = @"D:\Repos\PCL_Converter_new\Sandbox\test.csv";

            string[] strings = File.ReadAllLines(filepath);

            var cloudXYZ = new PointCloudXYZ();

            for (int i = 0; i < strings.Length; i++) {
                var coords = strings[i].Split(',');

                //Console.WriteLine(strings[i]);
                var p = new PointXYZ(
                    float.Parse(coords[0]),
                    float.Parse(coords[1]),
                    float.Parse(coords[2])
                    );
                //Console.WriteLine(p.ToString());
                cloudXYZ.Pushback(p);
            }

            // test normal estimation
            bool normalestimate = false;
            if (normalestimate) {
                var normals = Features.NormalEstimation(cloudXYZ, 8f);

                for (int i = 0; i < normals.Size; i++) {
                    var n = normals[i];
                    Console.WriteLine($"n1: {n.ToString()}");
                }

                string outPath = @"..\..\output\normalsOut00.csv";
                string[] output = new string[normals.Size];
                using (StreamWriter writer = new StreamWriter(outPath)) {
                    for (int i = 0; i < normals.Size; i++) {
                        var n = normals[i];
                        writer.WriteLine($"{n.Normal_X},{n.Normal_Y},{n.Normal_Z},{n.Curvature}");
                    }
                    Console.WriteLine("Writing To File Finished.");
                }
            }


            // test knn
            bool doTestKnn = false;
            if (doTestKnn)
            {
                int k = 11;

                float[] distances = new float[k];

                var neighbors = Search.KdTreeKNNSearch(1, cloudXYZ, k, ref distances);
                Console.WriteLine($"Neighbors:");
                for (int i = 0; i < k; i++) {
                    int n = neighbors[i];

                    Console.WriteLine($"Point {n}: {cloudXYZ[n].ToString()}; dist: {distances[i]}");
                    //Console.WriteLine($"Point {n}");

                }

                string outPathknn = @"..\..\output\knnOut00.csv";
                using (StreamWriter writer = new StreamWriter(outPathknn)) {
                    for (int i = 0; i < k; i++) {
                        var p = cloudXYZ[neighbors[i]];
                        writer.WriteLine($"{p.X},{p.Y},{p.Z},{distances[i]}");
                    }
                    Console.WriteLine("Finished Writing To File");
                }
            }

            // test coordinate search

            bool doTestCoordinateSearch = true;
            if (doTestCoordinateSearch) {
                // test search point
                float[] searchCoords = new float[] { 12.3705371805146f, 37.3011151307264f, 30.9127258563492f };

                int k = 4;

                //out variables
                var out_indices = new List<int>();
                var out_distances = new List<float>();


                Console.WriteLine("... finding neighbors in search radius ...");
                var neighborsFound = Search.KdTreeKNNSearch(searchCoords, cloudXYZ, k, ref out_distances);

                Console.WriteLine($"{neighborsFound} neighbors found!");
                for (int i = 0; i < neighborsFound.Length; i++) {
                    Console.WriteLine($"index: {neighborsFound[i]}, distance: {out_distances[i]}");
                }
            }

            // test radius search

            bool doTestRadiusSearch = false;
            if (doTestRadiusSearch) 
            {
                // test search point
                float[] searchCoords = new float[] { 12.3705371805146f, 37.3011151307264f, 30.9127258563492f };

                //out variables
                var out_indices = new List<int>();
                var out_distances = new List<float>();


                Console.WriteLine("... finding neighbors in search radius ...");
                var neighborsFound = Search.KdTreeRadiusSearch(searchCoords, cloudXYZ, 10f, ref out_indices, ref out_distances, 4);

                Console.WriteLine($"{neighborsFound} neighbors found!");
                for (int i = 0; i < neighborsFound; i++) {
                    Console.WriteLine($"index: {out_indices[i]}, distance: {out_distances[i]}");
                }
            }

            //
            //Console.WriteLine(cloud.ToString());
            //PCL_CLI.;

            Console.ReadKey();

        }
    }
}
