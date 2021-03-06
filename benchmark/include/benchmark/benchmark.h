/**
 * @file benchmark.h
 * @brief This file contains the declaration of the Benchmark class
 * 
 * @author Jiancong Zheng 
 * @date 2020-05-31
 * 
 */

#pragma once
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <pcl/point_types.h>
#include <pcl/PCLPointCloud2.h>
#include <pcl/features/normal_3d.h>
#include <pcl/visualization/pcl_visualizer.h>
#include "benchmark/math_computing.h"

namespace benchmark
{
    /**
     * @brief The Benchmark class
     * 
     * This class wraps the methods for a surface reconstruction benchmark 
     */
    class Benchmark
    {
    public:

        /**
         * @brief Construct a new Benchmark object
         */
        Benchmark() {};
        
        /**
         * @brief Destroy the Benchmark object
         */
        ~Benchmark() {};
        
        /**
         * @brief Input a polygon mesh for benchmaking
         * 
         * @param mesh Input mesh representing the surface reconstruction
         */
        void inputPolygonMesh(pcl::PolygonMesh mesh);

        /**
         * @brief Input a point cloud for further investigation
         * 
         * @param cloud Cloud of PointNormal
         */
        void inputPointCloud(pcl::PointCloud<pcl::PointNormal>::Ptr cloud);
        
        /**
         * @brief Get the test cloud
         * 
         * @return Test cloud 
         */
        pcl::PointCloud<pcl::PointNormal>::Ptr getTestCloud();

        /**
         * @brief Get the input cloud
         * 
         * @return Input cloud
         */
        pcl::PointCloud<pcl::PointNormal>::Ptr getInputCloud();

        /**
         * @brief Set the test cloud size
         */
        void setTestCloudSize(double fraction);
        
        /**
         * @brief Generate the result of testing
         */
        void generateData(std::string file_name);

    private:
        
        /**
         * @brief Devide the original cloud into a test cloud and a input cloud
         * 
         * @param[in, out] cloud Original cloud that is reduced to a input cloud
         * @param[out] test_cloud  Cloud for testing the surface reconstruction
         * @param[in] fraction Size of the test cloud
         */
        void divideCloud(pcl::PointCloud<pcl::PointNormal>::Ptr cloud, pcl::PointCloud<pcl::PointNormal>::Ptr test_cloud, double fraction);

        pcl::PointCloud<pcl::PointNormal>::Ptr           test_cloud           /**< Test cloud */
            {new pcl::PointCloud<pcl::PointNormal>};         
        pcl::PointCloud<pcl::PointNormal>::Ptr           input_cloud          /**< Input cloud */
            {new pcl::PointCloud<pcl::PointNormal>};      
        pcl::PolygonMesh                                 mesh;                /**< Mesh representing the surface reconstruction */
        double                                           fraction = 0.02;     /**< Size of the test cloud */
    };
}