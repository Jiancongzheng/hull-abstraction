/**
 * @file bspline_surface_fitting.h

 * @brief Framework of b-spline surface fitting node
 * @ros_node bspline_surface_fitting_node
 * 
 * @author Jiancong Zheng
 * @date 2020-05-12
 * 
 * This node subscribes a ROS topic to get an input point cloud and then perform b-spline surface fitting to generate a mesh.
 * The result of b-spline surface fitting is published as a pcl message.
 */

#pragma once

#include <iostream>

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include "hull_abstraction/preprocessor.h"
#include "hull_abstraction/reconstructor.h"
#include "pcl_utilization/pcl_utilization.h"

namespace bspline_surface_fitting_node
{
    /**
     * @brief  Class utilizing B-spline surface fitting method
     * 
     * This framework is developed to generate and publish a mesh for a point cloud through b-spline surface fitting.
     */
    class BsplineSurfaceFitting
    {
    public:
        /**
         * @brief Construct a new BsplineSurfaceFitting object
         */
        BsplineSurfaceFitting() {}
        
        /**
         * @brief  Encapsulate a method to run the bspline_surface_fitting node
         */
        void run();

    private:
        ros::NodeHandle                   nh;           /**< Node Handle reference from embedding node */
        ros::Publisher                    pub;          /**< Polygon mesh publisher */
        ros::Subscriber                   sub;          /**< Raw point cloud subscriber */
        pcl_msgs::PolygonMesh             output_msg;   /**< Polygon mesh message used to publish the mesh */

        hull_abstraction::Reconstructor   rc;           /**< Object for Reconstructor class */
        hull_abstraction::Preprocessor    pp;           /**< Object for Preprocessor class */
        pcl::PolygonMesh                  mesh;         /**< Resulted polygon mesh */
        

        /**
         * @brief Process the input ROS message
         * 
         * @param input_msg Input ROS message
         */
        void processing(const sensor_msgs::PointCloud2ConstPtr input_msg);
        
    };
}

