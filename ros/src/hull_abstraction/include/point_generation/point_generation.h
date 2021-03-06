/**
 * @file point_generator.h
 * @author Jiancong Zheng
 * @brief This file contains the declarations of the PointGenerator class
 * 
 * @date 2020-06-16
 */
#pragma once
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/PCLPointCloud2.h>
#include "pcl_utilization/math_computing.h"

namespace point_generation
{
    /**
     * @brief The PointGenerator class
     * This class wraps the implementation of algorithms in order to generate point cloud data from a given surface
     */
    class PointGenerator
    {
    public:
        /**
         * @brief Construct a new PointGenerator object
         */
        PointGenerator() {};

        /**
         * @brief Destroy the PointGenerator object
         */
        ~PointGenerator() {};

        /**
         * @brief Input a polygon mesh for point cloud generation
         * 
         * @param mesh Triangle mesh representing the surface reconstruction
         */
        void inputPolygonMesh(pcl::PolygonMesh mesh);

        /**
         * @brief Set the sample size 
         * @param size Sample size
         */
        void setSampleSize(size_t size);

        /**
         * @brief Get the resulted point cloud
         * 
         * @return Resulted point cloud
         */
        pcl::PointCloud<pcl::PointXYZ>::Ptr getPointCloud();

        /**
         * @brief Perform cloud generation
         * 
         */
        void generatePointCloud();

    private:
        pcl::PointCloud<pcl::PointXYZ>::Ptr         output_cloud         /**< Output cloud */
            {new pcl::PointCloud<pcl::PointXYZ>};      
        pcl::PolygonMesh                               input_mesh;          /**< Triangle mesh representing the surface reconstruction */
        size_t                                         sample_size;          /**< Sample_size */

        /**
         * @brief Generate point cloud through randomly sampling
         * 
         * @param mesh Input mesh representing the surface reconstruction
         * @return Resulted point cloud data 
         */
        pcl::PointCloud<pcl::PointXYZ>::Ptr randomlySampling(pcl::PolygonMesh mesh);
    };
}
