#include "poisson_reconstruction.h"

void poisson_reconstruction::PoissonReconstruction::processing(const sensor_msgs::PointCloud2ConstPtr input_msg)
{
    pcl::PointCloud<pcl::PointNormal>::Ptr      cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr         cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr         filtered_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointNormal>::Ptr      filtered_cloud_with_normals(new pcl::PointCloud<pcl::PointNormal>);

    // Generate the mesh
    pcl::fromROSMsg(*input_msg, *cloud); // Convert point cloud message to a cloud
    pp.movingLeastSquares(cloud, filtered_cloud, filtered_cloud_with_normals);
    pp.appendNormalEstimation(filtered_cloud, cloud_with_normals); // Add normal estimation to the original cloud
    mesh = rc.poissonReconstruction(cloud_with_normals); // Perform Poisson reconstruction
    
    // Calculate the centroid of the cloud
    std::vector<double> cloud_centroid = pcl_utilization::computeCentroid(cloud);
    std::cout << "The centroid of the cloud: [" << cloud_centroid[0] << ", " << cloud_centroid[1] << ", " << cloud_centroid[2] << "] " << std::endl;
    
    // Calculate the centroid of the mesh
    std::vector<double> mesh_centroid = pcl_utilization::computeCentroid(mesh);
    std::cout << "The centroid of the mesh:  [" << mesh_centroid[0] << ", " << mesh_centroid[1] << ", " << mesh_centroid[2] << "] " << std::endl;
    std::cout << std::endl;
    
    // Publish the mesh
    pcl_conversions::fromPCL(mesh, output_msg); // Convert a polygon mesh to a mesh message
    pub = nh.advertise<pcl_msgs::PolygonMesh>("poisson_reconstruction", 1);
    pub.publish(output_msg);
}

void poisson_reconstruction::PoissonReconstruction::run()
{
    sub = nh.subscribe("load_pcd", 1, &PoissonReconstruction::processing, this);
}