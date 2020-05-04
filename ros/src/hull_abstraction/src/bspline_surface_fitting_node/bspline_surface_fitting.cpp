#include "bspline_surface_fitting.h"

void bspline_surface_fitting_node::BsplineSurfaceFitting::processing(const sensor_msgs::PointCloud2ConstPtr input_msg)
{
    pcl::fromROSMsg(*input_msg, *cloud); 
    mesh = rc.bsplineSurfaceFitting(cloud);
    pcl_conversions::fromPCL(mesh, output_msg);
    pub = nh.advertise<pcl_msgs::PolygonMesh>("bspline_surface_fitting", 1);
    pub.publish(output_msg);
    std::cout << "successfully pulished" << std::endl;
}

void bspline_surface_fitting_node::BsplineSurfaceFitting::run()
{
    sub = nh.subscribe("load_pcd", 1, &BsplineSurfaceFitting::processing, this);
}