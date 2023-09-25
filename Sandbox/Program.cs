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

            //
            //Console.WriteLine(cloud.ToString());
            //PCL_CLI.;

            Console.ReadKey();

        }
    }
}
